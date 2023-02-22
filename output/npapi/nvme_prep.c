/**
 * nvme; Command Preparation API Implementation
 *
 * TODO
 * ====
 *
 * - use bit-mask and shift instead of relying on compiler-bitfields
 *   - code-generator knows widths and offset, can directly mask/shift instead
 *     of relying on macros
 * - add use of little-endian types
 * - add use of little-endian conversion
 */
#include <stdbool.h>
#include <stdint.h>
#include <libnvme_core.h>

int
nvme_nvm_write_prep(void *cmd_buf, uint32_t nsid, uint64_t slba, uint8_t nlb, uint8_t dtype,
		    bool stc, uint8_t prinfo, bool fua, bool lr, uint8_t dspec, uint8_t lbat,
		    uint8_t lbatm)
{
	struct nvme_nvm_write *cmd = cmd_buf;

	cmd->opc = 0x1;

	cmd->nsid = nsid;
	cmd->slba = slba;
	cmd->bits1.nlb = nlb;
	cmd->bits1.dtype = dtype;
	cmd->bits1.stc = stc;
	cmd->bits1.prinfo = prinfo;
	cmd->bits1.fua = fua;
	cmd->bits1.lr = lr;
	cmd->dspec = dspec;
	cmd->bits3.lbat = lbat;
	cmd->bits3.lbatm = lbatm;

	// TODO: replace '.bits'-accessor, with inline, compound bit-mask+shift

	return 0;
}

int
nvme_nvm_read_prep(void *cmd_buf, uint32_t nsid, uint64_t slba, uint8_t nlb, uint8_t dtype,
		   bool stc, uint8_t prinfo, bool fua, bool lr, uint8_t dspec, uint8_t lbat,
		   uint8_t lbatm)
{
	struct nvme_nvm_read *cmd = cmd_buf;

	cmd->opc = 0x2;

	cmd->nsid = nsid;
	cmd->slba = slba;
	cmd->bits1.nlb = nlb;
	cmd->bits1.dtype = dtype;
	cmd->bits1.stc = stc;
	cmd->bits1.prinfo = prinfo;
	cmd->bits1.fua = fua;
	cmd->bits1.lr = lr;
	cmd->dspec = dspec;
	cmd->bits3.lbat = lbat;
	cmd->bits3.lbatm = lbatm;

	// TODO: replace '.bits'-accessor, with inline, compound bit-mask+shift

	return 0;
}

int
nvme_nvm_write_uncor_prep(void *cmd_buf, uint32_t nsid, uint64_t slba, uint8_t nlb)
{
	struct nvme_nvm_write_uncor *cmd = cmd_buf;

	cmd->opc = 0x4;

	cmd->nsid = nsid;
	cmd->slba = slba;
	cmd->bits1.nlb = nlb;

	// TODO: replace '.bits'-accessor, with inline, compound bit-mask+shift

	return 0;
}

int
nvme_nvm_write_zeroes_prep(void *cmd_buf, uint32_t nsid, uint64_t slba, uint8_t nlb)
{
	struct nvme_nvm_write_zeroes *cmd = cmd_buf;

	cmd->opc = 0x8;

	cmd->nsid = nsid;
	cmd->slba = slba;
	cmd->bits1.nlb = nlb;

	// TODO: replace '.bits'-accessor, with inline, compound bit-mask+shift

	return 0;
}
