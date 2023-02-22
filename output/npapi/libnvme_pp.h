/**
 * NVMe; Pretty Printer Implementation
 *
 * ------------------------------------------------------------------------------------------------
 * Copyright (C) Simon A. F. Lund <os@safl.dk>
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * @file libnvme_pp.h
 * ------------------------------------------------------------------------------------------------
 * NOTE: This file is created using yace: https://github.com/safl/yace
 */

/**
 * Options for pretty-printer (``*_pr``, ``*_fpr``) functions
 *
 * Options determines the format the pretty-printer uses, e.g. Yaml or JSON
 *
 * @enum nvme_pr
 */
enum nvme_pr {
	NVME_PR_DEF  = 0x0,
	NVME_PR_YAML = 0x1,
	NVME_PR_JSON = 0x2,
};

/**
 * Produces a string representation of the given ::nvme_sct
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_sct_str(int enum_val);

/**
 * Produces a string representation of the given ::nvme_sc_generic
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_sc_generic_str(int enum_val);

/**
 * Produces a string representation of the given ::nvme_sc_cmdspec
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_sc_cmdspec_str(int enum_val);

/**
 * Produces a string representation of the given ::nvme_sc_media
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_sc_media_str(int enum_val);

/**
 * Produces a string representation of the given ::nvme_log_lpi
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_log_lpi_str(int enum_val);

/**
 * Prints the given ::nvme_health_entry 'obj' to the given output 'stream'
 *
 * @param stream output stream used for printing
 * @param obj Pointer to the ::nvme_health_entry to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_health_entry_fpr(FILE *stream, const struct nvme_health_entry *obj, int flags);

/**
 * Prints the given ::nvme_health_entry 'obj' to stdout
 *
 * @param obj Pointer to the ::nvme_health_entry to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_health_entry_pr(const struct nvme_health_entry *obj, int flags);

/**
 * Produces a string representation of the given ::nvme_opc_adm
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_opc_adm_str(int enum_val);

/**
 * Produces a string representation of the given ::nvme_idfy
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_idfy_str(int enum_val);

/**
 * Produces a string representation of the given ::nvme_csi
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_csi_str(int enum_val);

/**
 * Prints the given ::nvme_dsm_range 'obj' to the given output 'stream'
 *
 * @param stream output stream used for printing
 * @param obj Pointer to the ::nvme_dsm_range to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_dsm_range_fpr(FILE *stream, const struct nvme_dsm_range *obj, int flags);

/**
 * Prints the given ::nvme_dsm_range 'obj' to stdout
 *
 * @param obj Pointer to the ::nvme_dsm_range to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_dsm_range_pr(const struct nvme_dsm_range *obj, int flags);

/**
 * Produces a string representation of the given ::nvme_opc_nvm
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_opc_nvm_str(int enum_val);

/**
 * Produces a string representation of the given ::nvme_opc_zns
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_opc_zns_str(int enum_val);

/**
 * Produces a string representation of the given ::nvme_zns_zsa
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_zns_zsa_str(int enum_val);

/**
 * Produces a string representation of the given ::nvme_zns_zra
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_zns_zra_str(int enum_val);

/**
 * Produces a string representation of the given ::nvme_zns_zras
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_zns_zras_str(int enum_val);

/**
 * Produces a string representation of the given ::nvme_opc_kvs
 *
 * @param enum_val the enum value to produce a string representation of
 *
 * @return On success, a string representation is returned. On error, the string
 * "ENOSYS" is returned.
 */
const char *
nvme_opc_kvs_str(int enum_val);

/**
 * Prints the given ::nvme_nvm_write 'obj' to the given output 'stream'
 *
 * @param stream output stream used for printing
 * @param obj Pointer to the ::nvme_nvm_write to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_nvm_write_fpr(FILE *stream, const struct nvme_nvm_write *obj, int flags);

/**
 * Prints the given ::nvme_nvm_write 'obj' to stdout
 *
 * @param obj Pointer to the ::nvme_nvm_write to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_nvm_write_pr(const struct nvme_nvm_write *obj, int flags);

/**
 * Prints the given ::nvme_nvm_read 'obj' to the given output 'stream'
 *
 * @param stream output stream used for printing
 * @param obj Pointer to the ::nvme_nvm_read to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_nvm_read_fpr(FILE *stream, const struct nvme_nvm_read *obj, int flags);

/**
 * Prints the given ::nvme_nvm_read 'obj' to stdout
 *
 * @param obj Pointer to the ::nvme_nvm_read to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_nvm_read_pr(const struct nvme_nvm_read *obj, int flags);

/**
 * Prints the given ::nvme_nvm_write_uncor 'obj' to the given output 'stream'
 *
 * @param stream output stream used for printing
 * @param obj Pointer to the ::nvme_nvm_write_uncor to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_nvm_write_uncor_fpr(FILE *stream, const struct nvme_nvm_write_uncor *obj, int flags);

/**
 * Prints the given ::nvme_nvm_write_uncor 'obj' to stdout
 *
 * @param obj Pointer to the ::nvme_nvm_write_uncor to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_nvm_write_uncor_pr(const struct nvme_nvm_write_uncor *obj, int flags);

/**
 * Prints the given ::nvme_nvm_write_zeroes 'obj' to the given output 'stream'
 *
 * @param stream output stream used for printing
 * @param obj Pointer to the ::nvme_nvm_write_zeroes to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_nvm_write_zeroes_fpr(FILE *stream, const struct nvme_nvm_write_zeroes *obj, int flags);

/**
 * Prints the given ::nvme_nvm_write_zeroes 'obj' to stdout
 *
 * @param obj Pointer to the ::nvme_nvm_write_zeroes to print
 * @param flags Pretty-printer flags
 *
 * @return On success, the number of characters printed is returned.
 */
int
nvme_nvm_write_zeroes_pr(const struct nvme_nvm_write_zeroes *obj, int flags);
