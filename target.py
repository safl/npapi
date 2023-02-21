"""
The :class:`.NPAPI` is an extension of the :class:`.CAPI` target.

TODO:

* Generate the actual command-prepper code

* Generate the function-body with shifts

* Add a nice header-description

* Add a nice src-description

* Add function docs

Thus, the above files are what you should expect to see in the output-directory
"""
from yace.targets.capi.target import CAPI
from yace.emitters import Emitter
from pathlib import Path
from pprint import pprint
import logging as log


class NPAPI(CAPI):
    """
    Generate a C API just like :class:`.CAPI` and in addition to that, produce
    NVMe getter/setter functions.
    """

    NAME = "npapi"

    def emit_placeholder(self, model, hdr_path, src_path):
        """emit placeholder-code; for quick plumbing check."""

        with hdr_path.open("w") as hdrfile:
            hdrfile.write("int foo(int x, int y);\n")
        with src_path.open("w") as srcfile:
            srcfile.write("int foo(int x, int y) { return x + y; }\n")

    def emit_preppers(self, model, hdr_path, src_path):
        """Method creating preppers"""

        emitter = Emitter(Path(__file__).parent)
        preppers = []

        ignore = ["opc", "opcode", "cid", "rsvd", "psdt", "fuse"]

        for entity in (
            ent
            for ent in model.entities
            if ent.cls in ["struct"] and "nvme_nvm" in ent.sym
        ):
            opc = entity.ant.get("opc", None)
            if not opc:
                log.error("Missing ant.opc in: %s", entity.as_dict())
                return

            prepper = {
                "sym": entity.sym,
                "doc": entity.doc,
                "opc": opc,
                "params": [],
            }

            for member in entity.members:
                if member.sym.startswith("cdw"):  # Generic fields => no prep
                    continue
                if member.sym in ["mptr", "dptr"]:  # Payload-setup => no prep here
                    continue
                if member.sym in ignore:  # Explicit ignore-list => no prep here
                    continue
                if member.sym.startswith("rsvd"):  # Reserved fields => no prep
                    continue

                if member.cls in ["bitfield"]:  # Construct info for bit-operation
                    for bits in member.members:
                        if bits.sym in ignore:
                            continue
                        if "rsvd" in bits.sym:
                            continue
                        prepper["params"].append(
                            (
                                "bool" if bits.width == 1 else "uint8_t",
                                f"{member.sym}.{bits.sym}",
                                bits.sym,
                                bits.doc,
                            )
                        )
                else:
                    prepper["params"].append(
                        (
                            "uint%d_t" % member.typ.width,
                            member.sym,
                            member.sym,
                            member.doc,
                        )
                    )

            preppers.append(prepper)

        with hdr_path.open("w") as hdrfile:
            hdrfile.write(
                emitter.render("file_prep.h", {"data": preppers, "meta": model.meta})
            )
        with src_path.open("w") as srcfile:
            srcfile.write(
                emitter.render("file_prep.c", {"data": preppers, "meta": model.meta})
            )

    def emit(self, model):
        """Emit code"""

        hdr_path = (self.output / f"lib{model.meta.prefix}_prep.h").resolve()
        src_path = (self.output / f"{model.meta.prefix}_prep.c").resolve()

        # self.emit_placeholder(model, hdr_path, src_path)
        self.emit_preppers(model, hdr_path, src_path)

        # Add the command-prepper code to the library-bundle and check-code
        # emitted by CAPI.
        self.headers.append(hdr_path)
        self.sources.append(src_path)
        super().emit(model)
