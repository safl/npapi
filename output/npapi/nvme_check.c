/**
 * NVMe; this a simple check that pretty-printers behave as intended
 *
 * This is not an exhaustive test, however, ensuring that a program can be built using
 * the headers produced and that the generated pretty-printers are sound, goes a long
 * way.
 *
 * ------------------------------------------------------------------------------------------------
 * Copyright (C) Simon A. F. Lund <os@safl.dk>
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * @file nvme_check.c
 * ------------------------------------------------------------------------------------------------
 * NOTE: This file is created using yace: https://github.com/safl/yace
 */
#include <stdio.h>
#include <libnvme.h>

int
test_nvme_health_entry_pr(void)
{
	struct nvme_health_entry obj = {0};
	int wrtn;

	printf("\n# output from: nvme_health_entry_pr(..., NVME_PR_YAML)\n");
	wrtn = nvme_health_entry_pr(&obj, NVME_PR_YAML);
	if (wrtn < 0) {
		return 1;
	}

	printf("\n# output from: nvme_health_entry_pr(..., NVME_PR_JSON)\n");
	wrtn = nvme_health_entry_pr(&obj, NVME_PR_JSON);
	if (wrtn < 0) {
		return 1;
	}

	return 0;
}

int
test_nvme_dsm_range_pr(void)
{
	struct nvme_dsm_range obj = {0};
	int wrtn;

	printf("\n# output from: nvme_dsm_range_pr(..., NVME_PR_YAML)\n");
	wrtn = nvme_dsm_range_pr(&obj, NVME_PR_YAML);
	if (wrtn < 0) {
		return 1;
	}

	printf("\n# output from: nvme_dsm_range_pr(..., NVME_PR_JSON)\n");
	wrtn = nvme_dsm_range_pr(&obj, NVME_PR_JSON);
	if (wrtn < 0) {
		return 1;
	}

	return 0;
}

int
test_nvme_nvm_write_pr(void)
{
	struct nvme_nvm_write obj = {0};
	int wrtn;

	printf("\n# output from: nvme_nvm_write_pr(..., NVME_PR_YAML)\n");
	wrtn = nvme_nvm_write_pr(&obj, NVME_PR_YAML);
	if (wrtn < 0) {
		return 1;
	}

	printf("\n# output from: nvme_nvm_write_pr(..., NVME_PR_JSON)\n");
	wrtn = nvme_nvm_write_pr(&obj, NVME_PR_JSON);
	if (wrtn < 0) {
		return 1;
	}

	return 0;
}

int
test_nvme_nvm_read_pr(void)
{
	struct nvme_nvm_read obj = {0};
	int wrtn;

	printf("\n# output from: nvme_nvm_read_pr(..., NVME_PR_YAML)\n");
	wrtn = nvme_nvm_read_pr(&obj, NVME_PR_YAML);
	if (wrtn < 0) {
		return 1;
	}

	printf("\n# output from: nvme_nvm_read_pr(..., NVME_PR_JSON)\n");
	wrtn = nvme_nvm_read_pr(&obj, NVME_PR_JSON);
	if (wrtn < 0) {
		return 1;
	}

	return 0;
}

int
test_nvme_nvm_write_uncor_pr(void)
{
	struct nvme_nvm_write_uncor obj = {0};
	int wrtn;

	printf("\n# output from: nvme_nvm_write_uncor_pr(..., NVME_PR_YAML)\n");
	wrtn = nvme_nvm_write_uncor_pr(&obj, NVME_PR_YAML);
	if (wrtn < 0) {
		return 1;
	}

	printf("\n# output from: nvme_nvm_write_uncor_pr(..., NVME_PR_JSON)\n");
	wrtn = nvme_nvm_write_uncor_pr(&obj, NVME_PR_JSON);
	if (wrtn < 0) {
		return 1;
	}

	return 0;
}

int
test_nvme_nvm_write_zeroes_pr(void)
{
	struct nvme_nvm_write_zeroes obj = {0};
	int wrtn;

	printf("\n# output from: nvme_nvm_write_zeroes_pr(..., NVME_PR_YAML)\n");
	wrtn = nvme_nvm_write_zeroes_pr(&obj, NVME_PR_YAML);
	if (wrtn < 0) {
		return 1;
	}

	printf("\n# output from: nvme_nvm_write_zeroes_pr(..., NVME_PR_JSON)\n");
	wrtn = nvme_nvm_write_zeroes_pr(&obj, NVME_PR_JSON);
	if (wrtn < 0) {
		return 1;
	}

	return 0;
}

int
main(int argc, char *argv[])
{
	int err;

	printf("#\n");
	printf("# Pretty-printer output and testing\n");
	printf("#\n");

	err = test_nvme_health_entry_pr();
	if (err) {
		return err;
	}

	err = test_nvme_dsm_range_pr();
	if (err) {
		return err;
	}

	err = test_nvme_nvm_write_pr();
	if (err) {
		return err;
	}

	err = test_nvme_nvm_read_pr();
	if (err) {
		return err;
	}

	err = test_nvme_nvm_write_uncor_pr();
	if (err) {
		return err;
	}

	err = test_nvme_nvm_write_zeroes_pr();
	if (err) {
		return err;
	}

	return 0;
}
