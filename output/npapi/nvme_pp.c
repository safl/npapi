/**
 * NVMe; Pretty Printer Implementation
 *
 * ------------------------------------------------------------------------------------------------
 * Copyright (C) Simon A. F. Lund <os@safl.dk>
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * @file nvme_pp.c
 * ------------------------------------------------------------------------------------------------
 * NOTE: This file is created using yace: https://github.com/safl/yace
 */
#include <libnvme.h>
const char *
nvme_sct_str(int enum_val)
{
	switch (enum_val) {
	case NVME_SCT_GENERIC:
		return "NVME_SCT_GENERIC";
	case NVME_SCT_CMDSPEC:
		return "NVME_SCT_CMDSPEC";
	case NVME_SCT_MEDIA:
		return "NVME_SCT_MEDIA";
	case NVME_SCT_PATH:
		return "NVME_SCT_PATH";
	case NVME_SCT_VENDOR:
		return "NVME_SCT_VENDOR";
	}

	return "ENOSYS";
}
const char *
nvme_sc_generic_str(int enum_val)
{
	switch (enum_val) {
	case NVME_SC_GENERIC_SUCCESS:
		return "NVME_SC_GENERIC_SUCCESS";
	case NVME_SC_GENERIC_INVALID_OPCODE:
		return "NVME_SC_GENERIC_INVALID_OPCODE";
	case NVME_SC_GENERIC_INVALID_FIELD:
		return "NVME_SC_GENERIC_INVALID_FIELD";
	case NVME_SC_GENERIC_COMMAND_ID_CONFLICT:
		return "NVME_SC_GENERIC_COMMAND_ID_CONFLICT";
	case NVME_SC_GENERIC_DATA_TRANSFER_ERROR:
		return "NVME_SC_GENERIC_DATA_TRANSFER_ERROR";
	case NVME_SC_GENERIC_ABORTED_POWER_LOSS:
		return "NVME_SC_GENERIC_ABORTED_POWER_LOSS";
	}

	return "ENOSYS";
}
const char *
nvme_sc_cmdspec_str(int enum_val)
{
	switch (enum_val) {
	case NVME_SC_CMDSPEC_COMPLETION_QUEUE_INVALID:
		return "NVME_SC_CMDSPEC_COMPLETION_QUEUE_INVALID";
	case NVME_SC_CMDSPEC_ZONE_BOUNDARY_ERROR:
		return "NVME_SC_CMDSPEC_ZONE_BOUNDARY_ERROR";
	case NVME_SC_CMDSPEC_ZONE_IS_FULL:
		return "NVME_SC_CMDSPEC_ZONE_IS_FULL";
	case NVME_SC_CMDSPEC_ZONE_IS_READ_ONLY:
		return "NVME_SC_CMDSPEC_ZONE_IS_READ_ONLY";
	case NVME_SC_CMDSPEC_ZONE_IS_OFFLINE:
		return "NVME_SC_CMDSPEC_ZONE_IS_OFFLINE";
	case NVME_SC_CMDSPEC_ZONE_INVALID_WRITE:
		return "NVME_SC_CMDSPEC_ZONE_INVALID_WRITE";
	case NVME_SC_CMDSPEC_TOO_MANY_ACTIVE_ZONES:
		return "NVME_SC_CMDSPEC_TOO_MANY_ACTIVE_ZONES";
	case NVME_SC_CMDSPEC_TOO_MANY_OPEN_ZONES:
		return "NVME_SC_CMDSPEC_TOO_MANY_OPEN_ZONES";
	case NVME_SC_CMDSPEC_INVALID_ZONE_STATE_TRANSITION:
		return "NVME_SC_CMDSPEC_INVALID_ZONE_STATE_TRANSITION";
	}

	return "ENOSYS";
}
const char *
nvme_sc_media_str(int enum_val)
{
	switch (enum_val) {
	case NVME_SC_MEDIA_INTERNAL_PATH_ERROR:
		return "NVME_SC_MEDIA_INTERNAL_PATH_ERROR";
	}

	return "ENOSYS";
}
const char *
nvme_log_lpi_str(int enum_val)
{
	switch (enum_val) {
	case NVME_LOG_LPI_SUPPORTED:
		return "NVME_LOG_LPI_SUPPORTED";
	case NVME_LOG_LPI_ERROR:
		return "NVME_LOG_LPI_ERROR";
	case NVME_LOG_LPI_HEALTH_INFORMATION:
		return "NVME_LOG_LPI_HEALTH_INFORMATION";
	case NVME_LOG_LPI_FIRMWARE_SLOT:
		return "NVME_LOG_LPI_FIRMWARE_SLOT";
	case NVME_LOG_LPI_CHANGED_NS_LIST:
		return "NVME_LOG_LPI_CHANGED_NS_LIST";
	case NVME_LOG_LPI_COMMAND_EFFECTS_LOG:
		return "NVME_LOG_LPI_COMMAND_EFFECTS_LOG";
	case NVME_LOG_LPI_DEVICE_SELF_TEST:
		return "NVME_LOG_LPI_DEVICE_SELF_TEST";
	case NVME_LOG_LPI_TELEMETRY_HOST_INITIATED:
		return "NVME_LOG_LPI_TELEMETRY_HOST_INITIATED";
	case NVME_LOG_LPI_TELEMETRY_CTRLR_INITIATED:
		return "NVME_LOG_LPI_TELEMETRY_CTRLR_INITIATED";
	case NVME_LOG_LPI_ENDURANCE_GROUP_INFORMATION:
		return "NVME_LOG_LPI_ENDURANCE_GROUP_INFORMATION";
	case NVME_LOG_LPI_PREDICTABLE_LATENCY_PER_NVM_SET:
		return "NVME_LOG_LPI_PREDICTABLE_LATENCY_PER_NVM_SET";
	case NVME_LOG_LPI_PREDICTABLE_LATENCY_EVENT_AGGREGATE:
		return "NVME_LOG_LPI_PREDICTABLE_LATENCY_EVENT_AGGREGATE";
	case NVME_LOG_LPI_ASSYMETRIC_NAMESPACE_ACCESS:
		return "NVME_LOG_LPI_ASSYMETRIC_NAMESPACE_ACCESS";
	case NVME_LOG_LPI_PERSISTENT_EVENT_LOG:
		return "NVME_LOG_LPI_PERSISTENT_EVENT_LOG";
	case NVME_LOG_LPI_ENDURANCE_GROUP_EVENT_AGGREGATE:
		return "NVME_LOG_LPI_ENDURANCE_GROUP_EVENT_AGGREGATE";
	case NVME_LOG_LPI_LOG_DISCOVERY:
		return "NVME_LOG_LPI_LOG_DISCOVERY";
	case NVME_LOG_LPI_RESERVATION_NOTIFICATION:
		return "NVME_LOG_LPI_RESERVATION_NOTIFICATION";
	case NVME_LOG_LPI_SANITIZE_STATUS:
		return "NVME_LOG_LPI_SANITIZE_STATUS";
	case NVME_LOG_LPI_VENDOR_SPECIFIC_START:
		return "NVME_LOG_LPI_VENDOR_SPECIFIC_START";
	case NVME_LOG_LPI_VENDOR_SPECIFIC_END:
		return "NVME_LOG_LPI_VENDOR_SPECIFIC_END";
	}

	return "ENOSYS";
}
static int
nvme_health_entry_yaml(FILE *stream, const struct nvme_health_entry *obj, int flags)
{
	int wrtn = 0;

	wrtn += fprintf(stream, "nvme_health_entry:");

	if (!obj) {
		wrtn += fprintf(stream, " ~\n");
		return wrtn;
	}

	wrtn += fprintf(stream, "\n");
	wrtn += fprintf(stream, "%*scrit_warn: %d\n", 2, "", obj->crit_warn);
	wrtn += fprintf(stream, "%*scomp_temp: %d\n", 2, "", obj->comp_temp);
	wrtn += fprintf(stream, "%*savail_spare: %d\n", 2, "", obj->avail_spare);
	wrtn += fprintf(stream, "%*savail_spare_thresh: %d\n", 2, "", obj->avail_spare_thresh);
	wrtn += fprintf(stream, "%*spct_used: %d\n", 2, "", obj->pct_used);
	wrtn += fprintf(stream, "%*seg_crit_warn_sum: %d\n", 2, "", obj->eg_crit_warn_sum);
	wrtn += fprintf(stream, "%*srsvd7: RESERVED\n", 2, "");
	wrtn += fprintf(stream, "%*srsvd8: RESERVED\n", 2, "");

	return wrtn;
}

static int
nvme_health_entry_json(FILE *stream, const struct nvme_health_entry *obj, int flags)
{
	int wrtn = 0;

	if (!obj) {
		wrtn += fprintf(stream, "{ \"nvme_health_entry\": null }\n");
		return wrtn;
	}
	wrtn += fprintf(stream, "{\n%*s\"nvme_health_entry\": {\n", 2, "");
	wrtn += fprintf(stream, "%*s\"crit_warn\": %" PRIu8 "", 4, "", obj->crit_warn);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"comp_temp\": %" PRIu16 "", 4, "", obj->comp_temp);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"avail_spare\": %" PRIu8 "", 4, "", obj->avail_spare);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"avail_spare_thresh\": %" PRIu8 "", 4, "",
			obj->avail_spare_thresh);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"pct_used\": %" PRIu8 "", 4, "", obj->pct_used);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"eg_crit_warn_sum\": %" PRIu8 "", 4, "",
			obj->eg_crit_warn_sum);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd7\": \"RESERVED\"", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd8\": \"RESERVED\"", 4, "");
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}\n", 2, "");
	wrtn += fprintf(stream, "}\n");

	return wrtn;
}

int
nvme_health_entry_fpr(FILE *stream, const struct nvme_health_entry *obj, int flags)
{
	switch (flags) {
	case NVME_PR_DEF:
	case NVME_PR_YAML:
		return nvme_health_entry_yaml(stream, obj, flags);
		break;

	case NVME_PR_JSON:
		return nvme_health_entry_json(stream, obj, flags);
	}

	return -ENOSYS;
}

int
nvme_health_entry_pr(const struct nvme_health_entry *obj, int flags)
{
	return nvme_health_entry_fpr(stdout, obj, flags);
}
const char *
nvme_opc_adm_str(int enum_val)
{
	switch (enum_val) {
	case NVME_OPC_ADM_DELETE_IO_SQ:
		return "NVME_OPC_ADM_DELETE_IO_SQ";
	case NVME_OPC_ADM_CREATE_IO_SQ:
		return "NVME_OPC_ADM_CREATE_IO_SQ";
	case NVME_OPC_ADM_GET_LOG_PAGE:
		return "NVME_OPC_ADM_GET_LOG_PAGE";
	case NVME_OPC_ADM_DELETE_IO_CQ:
		return "NVME_OPC_ADM_DELETE_IO_CQ";
	case NVME_OPC_ADM_CREATE_IO_CQ:
		return "NVME_OPC_ADM_CREATE_IO_CQ";
	case NVME_OPC_ADM_IDENTIFY:
		return "NVME_OPC_ADM_IDENTIFY";
	case NVME_OPC_ADM_ABORT:
		return "NVME_OPC_ADM_ABORT";
	case NVME_OPC_ADM_SFEAT:
		return "NVME_OPC_ADM_SFEAT";
	case NVME_OPC_ADM_GFEAT:
		return "NVME_OPC_ADM_GFEAT";
	case NVME_OPC_ADM_ASYNC_EVENT_REQUEST:
		return "NVME_OPC_ADM_ASYNC_EVENT_REQUEST";
	case NVME_OPC_ADM_NS_MANAGEMENT:
		return "NVME_OPC_ADM_NS_MANAGEMENT";
	case NVME_OPC_ADM_FIRMWARE_COMMIT:
		return "NVME_OPC_ADM_FIRMWARE_COMMIT";
	case NVME_OPC_ADM_FIRMWARE_IMAGE_DOWNLOAD:
		return "NVME_OPC_ADM_FIRMWARE_IMAGE_DOWNLOAD";
	case NVME_OPC_ADM_DEVICE_SELF_TEST:
		return "NVME_OPC_ADM_DEVICE_SELF_TEST";
	case NVME_OPC_ADM_NS_ATTACHMENT:
		return "NVME_OPC_ADM_NS_ATTACHMENT";
	case NVME_OPC_ADM_KEEP_ALIVE:
		return "NVME_OPC_ADM_KEEP_ALIVE";
	case NVME_OPC_ADM_DSEND:
		return "NVME_OPC_ADM_DSEND";
	case NVME_OPC_ADM_DRECV:
		return "NVME_OPC_ADM_DRECV";
	case NVME_OPC_ADM_VIRTUALIZATION_MGMT:
		return "NVME_OPC_ADM_VIRTUALIZATION_MGMT";
	case NVME_OPC_ADM_MI_SEND:
		return "NVME_OPC_ADM_MI_SEND";
	case NVME_OPC_ADM_MI_RECV:
		return "NVME_OPC_ADM_MI_RECV";
	case NVME_OPC_ADM_CAPACITY_MGMT:
		return "NVME_OPC_ADM_CAPACITY_MGMT";
	case NVME_OPC_ADM_LOCKDOWN:
		return "NVME_OPC_ADM_LOCKDOWN";
	case NVME_OPC_ADM_DOORBELL_BUFFER_CONFIG:
		return "NVME_OPC_ADM_DOORBELL_BUFFER_CONFIG";
	case NVME_OPC_ADM_FABRICS_COMMANDS:
		return "NVME_OPC_ADM_FABRICS_COMMANDS";
	case NVME_OPC_ADM_FORMAT:
		return "NVME_OPC_ADM_FORMAT";
	case NVME_OPC_ADM_SECURITY_SEND:
		return "NVME_OPC_ADM_SECURITY_SEND";
	case NVME_OPC_ADM_SECURITY_RECV:
		return "NVME_OPC_ADM_SECURITY_RECV";
	case NVME_OPC_ADM_SANITIZE:
		return "NVME_OPC_ADM_SANITIZE";
	case NVME_OPC_ADM_GET_LBA_STATUS:
		return "NVME_OPC_ADM_GET_LBA_STATUS";
	}

	return "ENOSYS";
}
const char *
nvme_idfy_str(int enum_val)
{
	switch (enum_val) {
	case NVME_IDFY_NS:
		return "NVME_IDFY_NS";
	case NVME_IDFY_CTRLR:
		return "NVME_IDFY_CTRLR";
	case NVME_IDFY_NSLIST:
		return "NVME_IDFY_NSLIST";
	case NVME_IDFY_NSDSCR:
		return "NVME_IDFY_NSDSCR";
	case NVME_IDFY_SETL:
		return "NVME_IDFY_SETL";
	case NVME_IDFY_NS_IOCS:
		return "NVME_IDFY_NS_IOCS";
	case NVME_IDFY_CTRLR_IOCS:
		return "NVME_IDFY_CTRLR_IOCS";
	case NVME_IDFY_NSLIST_IOCS:
		return "NVME_IDFY_NSLIST_IOCS";
	case NVME_IDFY_NSLIST_ALLOC:
		return "NVME_IDFY_NSLIST_ALLOC";
	case NVME_IDFY_NS_ALLOC:
		return "NVME_IDFY_NS_ALLOC";
	case NVME_IDFY_CTRLR_NS:
		return "NVME_IDFY_CTRLR_NS";
	case NVME_IDFY_CTRLR_SUB:
		return "NVME_IDFY_CTRLR_SUB";
	case NVME_IDFY_CTRLR_PRI:
		return "NVME_IDFY_CTRLR_PRI";
	case NVME_IDFY_CTRLR_SEC:
		return "NVME_IDFY_CTRLR_SEC";
	case NVME_IDFY_NSGRAN:
		return "NVME_IDFY_NSGRAN";
	case NVME_IDFY_UUIDL:
		return "NVME_IDFY_UUIDL";
	case NVME_IDFY_NSLIST_ALLOC_IOCS:
		return "NVME_IDFY_NSLIST_ALLOC_IOCS";
	case NVME_IDFY_NS_ALLOC_IOCS:
		return "NVME_IDFY_NS_ALLOC_IOCS";
	case NVME_IDFY_IOCS:
		return "NVME_IDFY_IOCS";
	}

	return "ENOSYS";
}
const char *
nvme_csi_str(int enum_val)
{
	switch (enum_val) {
	case NVME_CSI_NVM:
		return "NVME_CSI_NVM";
	case NVME_CSI_KVS:
		return "NVME_CSI_KVS";
	case NVME_CSI_ZNS:
		return "NVME_CSI_ZNS";
	}

	return "ENOSYS";
}
static int
nvme_dsm_range_yaml(FILE *stream, const struct nvme_dsm_range *obj, int flags)
{
	int wrtn = 0;

	wrtn += fprintf(stream, "nvme_dsm_range:");

	if (!obj) {
		wrtn += fprintf(stream, " ~\n");
		return wrtn;
	}

	wrtn += fprintf(stream, "\n");
	wrtn += fprintf(stream, "%*scattr: %d\n", 2, "", obj->cattr);
	wrtn += fprintf(stream, "%*snlb: %d\n", 2, "", obj->nlb);
	wrtn += fprintf(stream, "%*sslba: 0x%" PRIx64 "\n", 2, "", obj->slba);

	return wrtn;
}

static int
nvme_dsm_range_json(FILE *stream, const struct nvme_dsm_range *obj, int flags)
{
	int wrtn = 0;

	if (!obj) {
		wrtn += fprintf(stream, "{ \"nvme_dsm_range\": null }\n");
		return wrtn;
	}
	wrtn += fprintf(stream, "{\n%*s\"nvme_dsm_range\": {\n", 2, "");
	wrtn += fprintf(stream, "%*s\"cattr\": %" PRIu32 "", 4, "", obj->cattr);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"nlb\": %" PRIu32 "", 4, "", obj->nlb);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"slba\": %" PRIu64 "", 4, "", obj->slba);
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}\n", 2, "");
	wrtn += fprintf(stream, "}\n");

	return wrtn;
}

int
nvme_dsm_range_fpr(FILE *stream, const struct nvme_dsm_range *obj, int flags)
{
	switch (flags) {
	case NVME_PR_DEF:
	case NVME_PR_YAML:
		return nvme_dsm_range_yaml(stream, obj, flags);
		break;

	case NVME_PR_JSON:
		return nvme_dsm_range_json(stream, obj, flags);
	}

	return -ENOSYS;
}

int
nvme_dsm_range_pr(const struct nvme_dsm_range *obj, int flags)
{
	return nvme_dsm_range_fpr(stdout, obj, flags);
}
const char *
nvme_opc_nvm_str(int enum_val)
{
	switch (enum_val) {
	case NVME_OPC_NVM_FLUSH:
		return "NVME_OPC_NVM_FLUSH";
	case NVME_OPC_NVM_WRITE:
		return "NVME_OPC_NVM_WRITE";
	case NVME_OPC_NVM_READ:
		return "NVME_OPC_NVM_READ";
	case NVME_OPC_NVM_WRITE_UNCORRECTABLE:
		return "NVME_OPC_NVM_WRITE_UNCORRECTABLE";
	case NVME_OPC_NVM_COMPARE:
		return "NVME_OPC_NVM_COMPARE";
	case NVME_OPC_NVM_WRITE_ZEROES:
		return "NVME_OPC_NVM_WRITE_ZEROES";
	case NVME_OPC_NVM_DATASET_MANAGEMENT:
		return "NVME_OPC_NVM_DATASET_MANAGEMENT";
	case NVME_OPC_NVM_VERIFY:
		return "NVME_OPC_NVM_VERIFY";
	case NVME_OPC_NVM_RESERVATION_REGISTER:
		return "NVME_OPC_NVM_RESERVATION_REGISTER";
	case NVME_OPC_NVM_RESERVATION_REPORT:
		return "NVME_OPC_NVM_RESERVATION_REPORT";
	case NVME_OPC_NVM_RESERVATION_ACQUIRE:
		return "NVME_OPC_NVM_RESERVATION_ACQUIRE";
	case NVME_OPC_NVM_RESERVATION_RELEASE:
		return "NVME_OPC_NVM_RESERVATION_RELEASE";
	case NVME_OPC_NVM_SCOPY:
		return "NVME_OPC_NVM_SCOPY";
	}

	return "ENOSYS";
}
const char *
nvme_opc_zns_str(int enum_val)
{
	switch (enum_val) {
	case NVME_OPC_ZNS_MGMT_SEND:
		return "NVME_OPC_ZNS_MGMT_SEND";
	case NVME_OPC_ZNS_MGMT_RECV:
		return "NVME_OPC_ZNS_MGMT_RECV";
	case NVME_OPC_ZNS_APPEND:
		return "NVME_OPC_ZNS_APPEND";
	}

	return "ENOSYS";
}
const char *
nvme_zns_zsa_str(int enum_val)
{
	switch (enum_val) {
	case NVME_ZNS_ZSA_CLOSE:
		return "NVME_ZNS_ZSA_CLOSE";
	case NVME_ZNS_ZSA_FINISH:
		return "NVME_ZNS_ZSA_FINISH";
	case NVME_ZNS_ZSA_OPEN:
		return "NVME_ZNS_ZSA_OPEN";
	case NVME_ZNS_ZSA_RESET:
		return "NVME_ZNS_ZSA_RESET";
	case NVME_ZNS_ZSA_OFFLINE:
		return "NVME_ZNS_ZSA_OFFLINE";
	case NVME_ZNS_ZSA_SET_DESCR_EXTENSION:
		return "NVME_ZNS_ZSA_SET_DESCR_EXTENSION";
	case NVME_ZNS_ZSA_ZRWA_FLUSH:
		return "NVME_ZNS_ZSA_ZRWA_FLUSH";
	}

	return "ENOSYS";
}
const char *
nvme_zns_zra_str(int enum_val)
{
	switch (enum_val) {
	case NVME_ZNS_ZRA_REPORT_ZONES:
		return "NVME_ZNS_ZRA_REPORT_ZONES";
	case NVME_ZNS_ZRA_EXTENDED_REPORT_ZONES:
		return "NVME_ZNS_ZRA_EXTENDED_REPORT_ZONES";
	}

	return "ENOSYS";
}
const char *
nvme_zns_zras_str(int enum_val)
{
	switch (enum_val) {
	case NVME_ZNS_ZRAS_LIST_ALL:
		return "NVME_ZNS_ZRAS_LIST_ALL";
	case NVME_ZNS_ZRAS_LIST_EMPTY:
		return "NVME_ZNS_ZRAS_LIST_EMPTY";
	case NVME_ZNS_ZRAS_LIST_IOPEN:
		return "NVME_ZNS_ZRAS_LIST_IOPEN";
	case NVME_ZNS_ZRAS_LIST_EOPEN:
		return "NVME_ZNS_ZRAS_LIST_EOPEN";
	case NVME_ZNS_ZRAS_LIST_CLOSED:
		return "NVME_ZNS_ZRAS_LIST_CLOSED";
	case NVME_ZNS_ZRAS_LIST_FULL:
		return "NVME_ZNS_ZRAS_LIST_FULL";
	case NVME_ZNS_ZRAS_LIST_READONLY:
		return "NVME_ZNS_ZRAS_LIST_READONLY";
	case NVME_ZNS_ZRAS_LIST_OFFLINE:
		return "NVME_ZNS_ZRAS_LIST_OFFLINE";
	case NVME_ZNS_ZRAS_LIST_ATTR:
		return "NVME_ZNS_ZRAS_LIST_ATTR";
	}

	return "ENOSYS";
}
const char *
nvme_opc_kvs_str(int enum_val)
{
	switch (enum_val) {
	case NVME_OPC_KVS_STORE:
		return "NVME_OPC_KVS_STORE";
	case NVME_OPC_KVS_RETRIEVE:
		return "NVME_OPC_KVS_RETRIEVE";
	case NVME_OPC_KVS_DELETE:
		return "NVME_OPC_KVS_DELETE";
	case NVME_OPC_KVS_EXIST:
		return "NVME_OPC_KVS_EXIST";
	case NVME_OPC_KVS_LIST:
		return "NVME_OPC_KVS_LIST";
	}

	return "ENOSYS";
}
static int
nvme_nvm_write_yaml(FILE *stream, const struct nvme_nvm_write *obj, int flags)
{
	int wrtn = 0;

	wrtn += fprintf(stream, "nvme_nvm_write:");

	if (!obj) {
		wrtn += fprintf(stream, " ~\n");
		return wrtn;
	}

	wrtn += fprintf(stream, "\n");
	wrtn += fprintf(stream, "%*sopc: %d\n", 2, "", obj->opc);
	wrtn += fprintf(stream, "%*srsvd_cdw0: RESERVED\n", 2, "");
	wrtn += fprintf(stream, "%*scid: %d\n", 2, "", obj->cid);
	wrtn += fprintf(stream, "%*snsid: 0x%" PRIx32 "\n", 2, "", obj->nsid);
	wrtn += fprintf(stream, "%*scdw02: 0x%" PRIx32 "\n", 2, "", obj->cdw02);
	wrtn += fprintf(stream, "%*scdw03: 0x%" PRIx32 "\n", 2, "", obj->cdw03);
	wrtn += fprintf(stream, "%*scdw04: 0x%" PRIx32 "\n", 2, "", obj->cdw04);
	wrtn += fprintf(stream, "%*scdw05: 0x%" PRIx32 "\n", 2, "", obj->cdw05);
	wrtn += fprintf(stream, "%*scdw06: 0x%" PRIx32 "\n", 2, "", obj->cdw06);
	wrtn += fprintf(stream, "%*scdw07: 0x%" PRIx32 "\n", 2, "", obj->cdw07);
	wrtn += fprintf(stream, "%*scdw08: 0x%" PRIx32 "\n", 2, "", obj->cdw08);
	wrtn += fprintf(stream, "%*scdw09: 0x%" PRIx32 "\n", 2, "", obj->cdw09);
	wrtn += fprintf(stream, "%*sslba: 0x%" PRIx64 "\n", 2, "", obj->slba);
	wrtn += fprintf(stream, "%*sbits1:\n", 2, "");

	wrtn += fprintf(stream, "%*snlb: 0x%x\n", 4, "", obj->bits1.nlb);
	wrtn += fprintf(stream, "%*srsvd2: 0x%x\n", 4, "", obj->bits1.rsvd2);
	wrtn += fprintf(stream, "%*sdtype: 0x%x\n", 4, "", obj->bits1.dtype);
	wrtn += fprintf(stream, "%*sstc: 0x%x\n", 4, "", obj->bits1.stc);
	wrtn += fprintf(stream, "%*srsvd1: 0x%x\n", 4, "", obj->bits1.rsvd1);
	wrtn += fprintf(stream, "%*sprinfo: 0x%x\n", 4, "", obj->bits1.prinfo);
	wrtn += fprintf(stream, "%*sfua: 0x%x\n", 4, "", obj->bits1.fua);
	wrtn += fprintf(stream, "%*slr: 0x%x\n", 4, "", obj->bits1.lr);
	wrtn += fprintf(stream, "%*sdspec: 0x%" PRIx8 "\n", 2, "", obj->dspec);
	wrtn += fprintf(stream, "%*srsvd1: RESERVED\n", 2, "");
	wrtn += fprintf(stream, "%*sbits2:\n", 2, "");

	wrtn += fprintf(stream, "%*srsvd: 0x%x\n", 4, "", obj->bits2.rsvd);
	wrtn += fprintf(stream, "%*scdw14: 0x%" PRIx32 "\n", 2, "", obj->cdw14);
	wrtn += fprintf(stream, "%*sbits3:\n", 2, "");

	wrtn += fprintf(stream, "%*slbat: 0x%x\n", 4, "", obj->bits3.lbat);
	wrtn += fprintf(stream, "%*slbatm: 0x%x\n", 4, "", obj->bits3.lbatm);

	return wrtn;
}

static int
nvme_nvm_write_json(FILE *stream, const struct nvme_nvm_write *obj, int flags)
{
	int wrtn = 0;

	if (!obj) {
		wrtn += fprintf(stream, "{ \"nvme_nvm_write\": null }\n");
		return wrtn;
	}
	wrtn += fprintf(stream, "{\n%*s\"nvme_nvm_write\": {\n", 2, "");
	wrtn += fprintf(stream, "%*s\"opc\": %" PRIu8 "", 4, "", obj->opc);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd_cdw0\": \"RESERVED\"", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cid\": %" PRIu16 "", 4, "", obj->cid);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"nsid\": %" PRIu32 "", 4, "", obj->nsid);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw02\": %" PRIu32 "", 4, "", obj->cdw02);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw03\": %" PRIu32 "", 4, "", obj->cdw03);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw04\": %" PRIu32 "", 4, "", obj->cdw04);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw05\": %" PRIu32 "", 4, "", obj->cdw05);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw06\": %" PRIu32 "", 4, "", obj->cdw06);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw07\": %" PRIu32 "", 4, "", obj->cdw07);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw08\": %" PRIu32 "", 4, "", obj->cdw08);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw09\": %" PRIu32 "", 4, "", obj->cdw09);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"slba\": %" PRIu64 "", 4, "", obj->slba);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"bits1\": {\n", 4, "");

	wrtn += fprintf(stream, "%*s\"nlb\": %u", 6, "", obj->bits1.nlb);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd2\": %u", 6, "", obj->bits1.rsvd2);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"dtype\": %u", 6, "", obj->bits1.dtype);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"stc\": %u", 6, "", obj->bits1.stc);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd1\": %u", 6, "", obj->bits1.rsvd1);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"prinfo\": %u", 6, "", obj->bits1.prinfo);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"fua\": %u", 6, "", obj->bits1.fua);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"lr\": %u", 6, "", obj->bits1.lr);
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"dspec\": %" PRIu8 "", 4, "", obj->dspec);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd1\": \"RESERVED\"", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"bits2\": {\n", 4, "");

	wrtn += fprintf(stream, "%*s\"rsvd\": %u", 6, "", obj->bits2.rsvd);
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw14\": %" PRIu32 "", 4, "", obj->cdw14);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"bits3\": {\n", 4, "");

	wrtn += fprintf(stream, "%*s\"lbat\": %u", 6, "", obj->bits3.lbat);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"lbatm\": %u", 6, "", obj->bits3.lbatm);
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}", 4, "");
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}\n", 2, "");
	wrtn += fprintf(stream, "}\n");

	return wrtn;
}

int
nvme_nvm_write_fpr(FILE *stream, const struct nvme_nvm_write *obj, int flags)
{
	switch (flags) {
	case NVME_PR_DEF:
	case NVME_PR_YAML:
		return nvme_nvm_write_yaml(stream, obj, flags);
		break;

	case NVME_PR_JSON:
		return nvme_nvm_write_json(stream, obj, flags);
	}

	return -ENOSYS;
}

int
nvme_nvm_write_pr(const struct nvme_nvm_write *obj, int flags)
{
	return nvme_nvm_write_fpr(stdout, obj, flags);
}
static int
nvme_nvm_read_yaml(FILE *stream, const struct nvme_nvm_read *obj, int flags)
{
	int wrtn = 0;

	wrtn += fprintf(stream, "nvme_nvm_read:");

	if (!obj) {
		wrtn += fprintf(stream, " ~\n");
		return wrtn;
	}

	wrtn += fprintf(stream, "\n");
	wrtn += fprintf(stream, "%*sopc: %d\n", 2, "", obj->opc);
	wrtn += fprintf(stream, "%*srsvd_cdw0: RESERVED\n", 2, "");
	wrtn += fprintf(stream, "%*scid: %d\n", 2, "", obj->cid);
	wrtn += fprintf(stream, "%*snsid: 0x%" PRIx32 "\n", 2, "", obj->nsid);
	wrtn += fprintf(stream, "%*scdw02: 0x%" PRIx32 "\n", 2, "", obj->cdw02);
	wrtn += fprintf(stream, "%*scdw03: 0x%" PRIx32 "\n", 2, "", obj->cdw03);
	wrtn += fprintf(stream, "%*scdw04: 0x%" PRIx32 "\n", 2, "", obj->cdw04);
	wrtn += fprintf(stream, "%*scdw05: 0x%" PRIx32 "\n", 2, "", obj->cdw05);
	wrtn += fprintf(stream, "%*scdw06: 0x%" PRIx32 "\n", 2, "", obj->cdw06);
	wrtn += fprintf(stream, "%*scdw07: 0x%" PRIx32 "\n", 2, "", obj->cdw07);
	wrtn += fprintf(stream, "%*scdw08: 0x%" PRIx32 "\n", 2, "", obj->cdw08);
	wrtn += fprintf(stream, "%*scdw09: 0x%" PRIx32 "\n", 2, "", obj->cdw09);
	wrtn += fprintf(stream, "%*sslba: 0x%" PRIx64 "\n", 2, "", obj->slba);
	wrtn += fprintf(stream, "%*sbits1:\n", 2, "");

	wrtn += fprintf(stream, "%*snlb: 0x%x\n", 4, "", obj->bits1.nlb);
	wrtn += fprintf(stream, "%*srsvd2: 0x%x\n", 4, "", obj->bits1.rsvd2);
	wrtn += fprintf(stream, "%*sdtype: 0x%x\n", 4, "", obj->bits1.dtype);
	wrtn += fprintf(stream, "%*sstc: 0x%x\n", 4, "", obj->bits1.stc);
	wrtn += fprintf(stream, "%*srsvd1: 0x%x\n", 4, "", obj->bits1.rsvd1);
	wrtn += fprintf(stream, "%*sprinfo: 0x%x\n", 4, "", obj->bits1.prinfo);
	wrtn += fprintf(stream, "%*sfua: 0x%x\n", 4, "", obj->bits1.fua);
	wrtn += fprintf(stream, "%*slr: 0x%x\n", 4, "", obj->bits1.lr);
	wrtn += fprintf(stream, "%*sdspec: 0x%" PRIx8 "\n", 2, "", obj->dspec);
	wrtn += fprintf(stream, "%*srsvd1: RESERVED\n", 2, "");
	wrtn += fprintf(stream, "%*sbits2:\n", 2, "");

	wrtn += fprintf(stream, "%*srsvd: 0x%x\n", 4, "", obj->bits2.rsvd);
	wrtn += fprintf(stream, "%*scdw14: 0x%" PRIx32 "\n", 2, "", obj->cdw14);
	wrtn += fprintf(stream, "%*sbits3:\n", 2, "");

	wrtn += fprintf(stream, "%*slbat: 0x%x\n", 4, "", obj->bits3.lbat);
	wrtn += fprintf(stream, "%*slbatm: 0x%x\n", 4, "", obj->bits3.lbatm);

	return wrtn;
}

static int
nvme_nvm_read_json(FILE *stream, const struct nvme_nvm_read *obj, int flags)
{
	int wrtn = 0;

	if (!obj) {
		wrtn += fprintf(stream, "{ \"nvme_nvm_read\": null }\n");
		return wrtn;
	}
	wrtn += fprintf(stream, "{\n%*s\"nvme_nvm_read\": {\n", 2, "");
	wrtn += fprintf(stream, "%*s\"opc\": %" PRIu8 "", 4, "", obj->opc);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd_cdw0\": \"RESERVED\"", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cid\": %" PRIu16 "", 4, "", obj->cid);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"nsid\": %" PRIu32 "", 4, "", obj->nsid);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw02\": %" PRIu32 "", 4, "", obj->cdw02);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw03\": %" PRIu32 "", 4, "", obj->cdw03);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw04\": %" PRIu32 "", 4, "", obj->cdw04);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw05\": %" PRIu32 "", 4, "", obj->cdw05);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw06\": %" PRIu32 "", 4, "", obj->cdw06);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw07\": %" PRIu32 "", 4, "", obj->cdw07);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw08\": %" PRIu32 "", 4, "", obj->cdw08);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw09\": %" PRIu32 "", 4, "", obj->cdw09);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"slba\": %" PRIu64 "", 4, "", obj->slba);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"bits1\": {\n", 4, "");

	wrtn += fprintf(stream, "%*s\"nlb\": %u", 6, "", obj->bits1.nlb);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd2\": %u", 6, "", obj->bits1.rsvd2);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"dtype\": %u", 6, "", obj->bits1.dtype);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"stc\": %u", 6, "", obj->bits1.stc);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd1\": %u", 6, "", obj->bits1.rsvd1);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"prinfo\": %u", 6, "", obj->bits1.prinfo);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"fua\": %u", 6, "", obj->bits1.fua);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"lr\": %u", 6, "", obj->bits1.lr);
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"dspec\": %" PRIu8 "", 4, "", obj->dspec);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd1\": \"RESERVED\"", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"bits2\": {\n", 4, "");

	wrtn += fprintf(stream, "%*s\"rsvd\": %u", 6, "", obj->bits2.rsvd);
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw14\": %" PRIu32 "", 4, "", obj->cdw14);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"bits3\": {\n", 4, "");

	wrtn += fprintf(stream, "%*s\"lbat\": %u", 6, "", obj->bits3.lbat);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"lbatm\": %u", 6, "", obj->bits3.lbatm);
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}", 4, "");
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}\n", 2, "");
	wrtn += fprintf(stream, "}\n");

	return wrtn;
}

int
nvme_nvm_read_fpr(FILE *stream, const struct nvme_nvm_read *obj, int flags)
{
	switch (flags) {
	case NVME_PR_DEF:
	case NVME_PR_YAML:
		return nvme_nvm_read_yaml(stream, obj, flags);
		break;

	case NVME_PR_JSON:
		return nvme_nvm_read_json(stream, obj, flags);
	}

	return -ENOSYS;
}

int
nvme_nvm_read_pr(const struct nvme_nvm_read *obj, int flags)
{
	return nvme_nvm_read_fpr(stdout, obj, flags);
}
static int
nvme_nvm_write_uncor_yaml(FILE *stream, const struct nvme_nvm_write_uncor *obj, int flags)
{
	int wrtn = 0;

	wrtn += fprintf(stream, "nvme_nvm_write_uncor:");

	if (!obj) {
		wrtn += fprintf(stream, " ~\n");
		return wrtn;
	}

	wrtn += fprintf(stream, "\n");
	wrtn += fprintf(stream, "%*sopc: %d\n", 2, "", obj->opc);
	wrtn += fprintf(stream, "%*srsvd_cdw0: RESERVED\n", 2, "");
	wrtn += fprintf(stream, "%*scid: %d\n", 2, "", obj->cid);
	wrtn += fprintf(stream, "%*snsid: 0x%" PRIx32 "\n", 2, "", obj->nsid);
	wrtn += fprintf(stream, "%*scdw02: 0x%" PRIx32 "\n", 2, "", obj->cdw02);
	wrtn += fprintf(stream, "%*scdw03: 0x%" PRIx32 "\n", 2, "", obj->cdw03);
	wrtn += fprintf(stream, "%*scdw04: 0x%" PRIx32 "\n", 2, "", obj->cdw04);
	wrtn += fprintf(stream, "%*scdw05: 0x%" PRIx32 "\n", 2, "", obj->cdw05);
	wrtn += fprintf(stream, "%*scdw06: 0x%" PRIx32 "\n", 2, "", obj->cdw06);
	wrtn += fprintf(stream, "%*scdw07: 0x%" PRIx32 "\n", 2, "", obj->cdw07);
	wrtn += fprintf(stream, "%*scdw08: 0x%" PRIx32 "\n", 2, "", obj->cdw08);
	wrtn += fprintf(stream, "%*scdw09: 0x%" PRIx32 "\n", 2, "", obj->cdw09);
	wrtn += fprintf(stream, "%*sslba: 0x%" PRIx64 "\n", 2, "", obj->slba);
	wrtn += fprintf(stream, "%*sbits1:\n", 2, "");

	wrtn += fprintf(stream, "%*snlb: 0x%x\n", 4, "", obj->bits1.nlb);
	wrtn += fprintf(stream, "%*srsvd_cdw12: 0x%x\n", 4, "", obj->bits1.rsvd_cdw12);
	wrtn += fprintf(stream, "%*scdw13: 0x%" PRIx32 "\n", 2, "", obj->cdw13);
	wrtn += fprintf(stream, "%*scdw14: 0x%" PRIx32 "\n", 2, "", obj->cdw14);
	wrtn += fprintf(stream, "%*scdw15: 0x%" PRIx32 "\n", 2, "", obj->cdw15);

	return wrtn;
}

static int
nvme_nvm_write_uncor_json(FILE *stream, const struct nvme_nvm_write_uncor *obj, int flags)
{
	int wrtn = 0;

	if (!obj) {
		wrtn += fprintf(stream, "{ \"nvme_nvm_write_uncor\": null }\n");
		return wrtn;
	}
	wrtn += fprintf(stream, "{\n%*s\"nvme_nvm_write_uncor\": {\n", 2, "");
	wrtn += fprintf(stream, "%*s\"opc\": %" PRIu8 "", 4, "", obj->opc);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd_cdw0\": \"RESERVED\"", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cid\": %" PRIu16 "", 4, "", obj->cid);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"nsid\": %" PRIu32 "", 4, "", obj->nsid);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw02\": %" PRIu32 "", 4, "", obj->cdw02);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw03\": %" PRIu32 "", 4, "", obj->cdw03);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw04\": %" PRIu32 "", 4, "", obj->cdw04);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw05\": %" PRIu32 "", 4, "", obj->cdw05);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw06\": %" PRIu32 "", 4, "", obj->cdw06);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw07\": %" PRIu32 "", 4, "", obj->cdw07);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw08\": %" PRIu32 "", 4, "", obj->cdw08);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw09\": %" PRIu32 "", 4, "", obj->cdw09);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"slba\": %" PRIu64 "", 4, "", obj->slba);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"bits1\": {\n", 4, "");

	wrtn += fprintf(stream, "%*s\"nlb\": %u", 6, "", obj->bits1.nlb);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd_cdw12\": %u", 6, "", obj->bits1.rsvd_cdw12);
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw13\": %" PRIu32 "", 4, "", obj->cdw13);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw14\": %" PRIu32 "", 4, "", obj->cdw14);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw15\": %" PRIu32 "", 4, "", obj->cdw15);
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}\n", 2, "");
	wrtn += fprintf(stream, "}\n");

	return wrtn;
}

int
nvme_nvm_write_uncor_fpr(FILE *stream, const struct nvme_nvm_write_uncor *obj, int flags)
{
	switch (flags) {
	case NVME_PR_DEF:
	case NVME_PR_YAML:
		return nvme_nvm_write_uncor_yaml(stream, obj, flags);
		break;

	case NVME_PR_JSON:
		return nvme_nvm_write_uncor_json(stream, obj, flags);
	}

	return -ENOSYS;
}

int
nvme_nvm_write_uncor_pr(const struct nvme_nvm_write_uncor *obj, int flags)
{
	return nvme_nvm_write_uncor_fpr(stdout, obj, flags);
}
static int
nvme_nvm_write_zeroes_yaml(FILE *stream, const struct nvme_nvm_write_zeroes *obj, int flags)
{
	int wrtn = 0;

	wrtn += fprintf(stream, "nvme_nvm_write_zeroes:");

	if (!obj) {
		wrtn += fprintf(stream, " ~\n");
		return wrtn;
	}

	wrtn += fprintf(stream, "\n");
	wrtn += fprintf(stream, "%*sopc: %d\n", 2, "", obj->opc);
	wrtn += fprintf(stream, "%*srsvd_cdw0: RESERVED\n", 2, "");
	wrtn += fprintf(stream, "%*scid: %d\n", 2, "", obj->cid);
	wrtn += fprintf(stream, "%*snsid: 0x%" PRIx32 "\n", 2, "", obj->nsid);
	wrtn += fprintf(stream, "%*scdw02: 0x%" PRIx32 "\n", 2, "", obj->cdw02);
	wrtn += fprintf(stream, "%*scdw03: 0x%" PRIx32 "\n", 2, "", obj->cdw03);
	wrtn += fprintf(stream, "%*scdw04: 0x%" PRIx32 "\n", 2, "", obj->cdw04);
	wrtn += fprintf(stream, "%*scdw05: 0x%" PRIx32 "\n", 2, "", obj->cdw05);
	wrtn += fprintf(stream, "%*scdw06: 0x%" PRIx32 "\n", 2, "", obj->cdw06);
	wrtn += fprintf(stream, "%*scdw07: 0x%" PRIx32 "\n", 2, "", obj->cdw07);
	wrtn += fprintf(stream, "%*scdw08: 0x%" PRIx32 "\n", 2, "", obj->cdw08);
	wrtn += fprintf(stream, "%*scdw09: 0x%" PRIx32 "\n", 2, "", obj->cdw09);
	wrtn += fprintf(stream, "%*sslba: 0x%" PRIx64 "\n", 2, "", obj->slba);
	wrtn += fprintf(stream, "%*sbits1:\n", 2, "");

	wrtn += fprintf(stream, "%*snlb: 0x%x\n", 4, "", obj->bits1.nlb);
	wrtn += fprintf(stream, "%*srsvd_cdw12: 0x%x\n", 4, "", obj->bits1.rsvd_cdw12);
	wrtn += fprintf(stream, "%*scdw13: 0x%" PRIx32 "\n", 2, "", obj->cdw13);
	wrtn += fprintf(stream, "%*scdw14: 0x%" PRIx32 "\n", 2, "", obj->cdw14);
	wrtn += fprintf(stream, "%*scdw15: 0x%" PRIx32 "\n", 2, "", obj->cdw15);

	return wrtn;
}

static int
nvme_nvm_write_zeroes_json(FILE *stream, const struct nvme_nvm_write_zeroes *obj, int flags)
{
	int wrtn = 0;

	if (!obj) {
		wrtn += fprintf(stream, "{ \"nvme_nvm_write_zeroes\": null }\n");
		return wrtn;
	}
	wrtn += fprintf(stream, "{\n%*s\"nvme_nvm_write_zeroes\": {\n", 2, "");
	wrtn += fprintf(stream, "%*s\"opc\": %" PRIu8 "", 4, "", obj->opc);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd_cdw0\": \"RESERVED\"", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cid\": %" PRIu16 "", 4, "", obj->cid);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"nsid\": %" PRIu32 "", 4, "", obj->nsid);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw02\": %" PRIu32 "", 4, "", obj->cdw02);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw03\": %" PRIu32 "", 4, "", obj->cdw03);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw04\": %" PRIu32 "", 4, "", obj->cdw04);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw05\": %" PRIu32 "", 4, "", obj->cdw05);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw06\": %" PRIu32 "", 4, "", obj->cdw06);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw07\": %" PRIu32 "", 4, "", obj->cdw07);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw08\": %" PRIu32 "", 4, "", obj->cdw08);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw09\": %" PRIu32 "", 4, "", obj->cdw09);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"slba\": %" PRIu64 "", 4, "", obj->slba);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"bits1\": {\n", 4, "");

	wrtn += fprintf(stream, "%*s\"nlb\": %u", 6, "", obj->bits1.nlb);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"rsvd_cdw12\": %u", 6, "", obj->bits1.rsvd_cdw12);
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}", 4, "");
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw13\": %" PRIu32 "", 4, "", obj->cdw13);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw14\": %" PRIu32 "", 4, "", obj->cdw14);
	wrtn += fprintf(stream, ",\n");

	wrtn += fprintf(stream, "%*s\"cdw15\": %" PRIu32 "", 4, "", obj->cdw15);
	wrtn += fprintf(stream, "\n");

	wrtn += fprintf(stream, "%*s}\n", 2, "");
	wrtn += fprintf(stream, "}\n");

	return wrtn;
}

int
nvme_nvm_write_zeroes_fpr(FILE *stream, const struct nvme_nvm_write_zeroes *obj, int flags)
{
	switch (flags) {
	case NVME_PR_DEF:
	case NVME_PR_YAML:
		return nvme_nvm_write_zeroes_yaml(stream, obj, flags);
		break;

	case NVME_PR_JSON:
		return nvme_nvm_write_zeroes_json(stream, obj, flags);
	}

	return -ENOSYS;
}

int
nvme_nvm_write_zeroes_pr(const struct nvme_nvm_write_zeroes *obj, int flags)
{
	return nvme_nvm_write_zeroes_fpr(stdout, obj, flags);
}
