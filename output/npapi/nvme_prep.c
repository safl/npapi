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
 * - fix generation of struct to support assignment of bit-fields
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
	cmd->bits1.raw = ((nlb & 65535) << 0) | ((dtype & 15) << 20) | ((stc & 1) << 24) |
			 ((prinfo & 15) << 26) | ((fua & 1) << 30) | ((lr & 1) << 31);
	cmd->dspec = dspec;
	cmd->bits3.raw = ((lbat & 65535) << 0) | ((lbatm & 65535) << 16);

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
	cmd->bits1.raw = ((nlb & 65535) << 0) | ((dtype & 15) << 20) | ((stc & 1) << 24) |
			 ((prinfo & 15) << 26) | ((fua & 1) << 30) | ((lr & 1) << 31);
	cmd->dspec = dspec;
	cmd->bits3.raw = ((lbat & 65535) << 0) | ((lbatm & 65535) << 16);

	return 0;
}

int
nvme_nvm_write_uncor_prep(void *cmd_buf, uint32_t nsid, uint64_t slba, uint8_t nlb)
{
	struct nvme_nvm_write_uncor *cmd = cmd_buf;

	cmd->opc = 0x4;

	cmd->nsid = nsid;
	cmd->slba = slba;
	cmd->bits1.raw = ((nlb & 65535) << 0);

	return 0;
}

int
nvme_nvm_write_zeroes_prep(void *cmd_buf, uint32_t nsid, uint64_t slba, uint8_t nlb)
{
	struct nvme_nvm_write_zeroes *cmd = cmd_buf;

	cmd->opc = 0x8;

	cmd->nsid = nsid;
	cmd->slba = slba;
	cmd->bits1.raw = ((nlb & 65535) << 0);

	return 0;
}
