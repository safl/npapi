/**
 * nvme; Command Preparation API
 *
 * ------------------------------------------------------------------------------------------------
 * @file libnvme_prep.h
 * ------------------------------------------------------------------------------------------------
 * NOTE: This file is created using yace: https://github.com/safl/yace
 */

/**
 * NVM Write Command - Command Preparation
 *
 * @param nsid Namespace Identifier"
 * @param slba Starting LBA
 * @param nlb Number of Logical Blocks
 * @param dtype Directtive Type
 * @param stc Storage Tag Check
 * @param prinfo Protection Information
 * @param fua Force Unit Access
 * @param lr Limited Retry
 * @param dspec Directive Specific
 * @param lbat Logical Block Application Tag
 * @param lbatm Logical Block Application Tag Mask
 *
 * @return On success 0 is returned. On error, -errno is
 * returned.
 */
int
nvme_nvm_write_prep(void *cmd_buf, uint32_t nsid, uint64_t slba, uint8_t nlb, uint8_t dtype,
		    bool stc, uint8_t prinfo, bool fua, bool lr, uint8_t dspec, uint8_t lbat,
		    uint8_t lbatm);

/**
 * NVM Read Command - Command Preparation
 *
 * @param nsid Namespace Identifier"
 * @param slba Starting LBA
 * @param nlb Number of Logical Blocks
 * @param dtype Directtive Type
 * @param stc Storage Tag Check
 * @param prinfo Protection Information
 * @param fua Force Unit Access
 * @param lr Limited Retry
 * @param dspec Directive Specific
 * @param lbat Logical Block Application Tag
 * @param lbatm Logical Block Application Tag Mask
 *
 * @return On success 0 is returned. On error, -errno is
 * returned.
 */
int
nvme_nvm_read_prep(void *cmd_buf, uint32_t nsid, uint64_t slba, uint8_t nlb, uint8_t dtype,
		   bool stc, uint8_t prinfo, bool fua, bool lr, uint8_t dspec, uint8_t lbat,
		   uint8_t lbatm);

/**
 * NVM Write Uncorrectable Command - Command Preparation
 *
 * @param nsid Namespace Identifier"
 * @param slba Starting LBA
 * @param nlb Number of Logical Blocks
 *
 * @return On success 0 is returned. On error, -errno is
 * returned.
 */
int
nvme_nvm_write_uncor_prep(void *cmd_buf, uint32_t nsid, uint64_t slba, uint8_t nlb);

/**
 * NVM Write Zeroes Command - Command Preparation
 *
 * @param nsid Namespace Identifier"
 * @param slba Starting LBA
 * @param nlb Number of Logical Blocks
 *
 * @return On success 0 is returned. On error, -errno is
 * returned.
 */
int
nvme_nvm_write_zeroes_prep(void *cmd_buf, uint32_t nsid, uint64_t slba, uint8_t nlb);
