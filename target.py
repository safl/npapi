"""
The :class:`.NPAPI` is an extension of the :class:`.CAPI` target.

Thus, the above files are what you should expect to see in the output-directory
"""
from yace.targets.capi.target import CAPI


class NPAPI(CAPI):
    """
    Generate a C API just like :class:`.CAPI` and in addition to that, produce
    NVMe getter/setter functions.
    """

    NAME = "npapi"

    def emit(self, model):
        """Emit code"""

        super().emit(model)
