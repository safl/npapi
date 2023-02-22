/**
 * NVMe; Core API
 *
 * NVMe structs, enum, values and helper function declarations
 *
 * If an entity is defined in the NVMe specification, then an enum or struct should exist in this
 * header file. The purpose of this is to provide a single point of entry for spec. definitions for
 * the purpose of providing structs with accessors, and enums for values such as command opcodes.
 *
 * ------------------------------------------------------------------------------------------------
 * Copyright (C) Simon A. F. Lund <os@safl.dk>
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * @file libnvme.h
 * ------------------------------------------------------------------------------------------------
 * NOTE: This file is created using yace: https://github.com/safl/yace
 */

#define NVME_CTRLR_SN_LEN                          = 20         ///< brief description
#define NVME_CTRLR_MN_LEN                          = 40         ///< brief description
#define NVME_CTRLR_FR_LEN                          = 8          ///< brief description
#define NVME_NSID_ALL                              = 4294967295 ///<
#define NVME_NSID_NONE                             = 0          ///<
#define NVME_UUID_NONE                             = 0          ///<
#define NVME_CNTLID_NONE                           = 0          ///<
#define NVME_CNSSPECID_NONE                        = 0          ///<
#define NVME_LOG_LSP_NONE                          = 0          ///<
#define NVME_LOG_LSI_NONE                          = 0          ///<
#define NVME_LOG_LPO_NONE                          = 0          ///<
#define NVME_IDENTIFY_DATA_SIZE                    = 4096       ///<
#define NVME_LOG_SUPPORTED_LOG_PAGES_MAX           = 256        ///<
#define NVME_ID_NVMSET_LIST_MAX                    = 31         ///<
#define NVME_ID_UUID_LIST_MAX                      = 127        ///<
#define NVME_ID_CTRL_LIST_MAX                      = 2047       ///<
#define NVME_ID_NS_LIST_MAX                        = 1024       ///<
#define NVME_ID_SECONDARY_CTRL_MAX                 = 127        ///<
#define NVME_ID_DOMAIN_LIST_MAX                    = 31         ///<
#define NVME_ID_ENDURANCE_GROUP_LIST_MAX           = 2047       ///<
#define NVME_ID_ND_DESCRIPTOR_MAX                  = 16         ///<
#define NVME_FEAT_LBA_RANGE_MAX                    = 64         ///<
#define NVME_LOG_ST_MAX_RESULTS                    = 20         ///<
#define NVME_LOG_TELEM_BLOCK_SIZE                  = 512        ///<
#define NVME_LOG_FID_SUPPORTED_EFFECTS_MAX         = 256        ///<
#define NVME_LOG_MI_CMD_SUPPORTED_EFFECTS_MAX      = 256        ///<
#define NVME_LOG_MI_CMD_SUPPORTED_EFFECTS_RESERVED = 768        ///<
#define NVME_DSM_MAX_RANGES                        = 256        ///<
#define NVME_NQN_LENGTH                            = 256        ///<
#define NVME_NVMF_TRADDR_SIZE                      = 256        ///<
#define NVME_NVMF_TSAS_SIZE                        = 256        ///<
#define NVME_ZNS_CHANGED_ZONES_MAX                 = 511        ///<

/**
 * Status Code Types
 *
 * @enum nvme_sct
 */
enum nvme_sct {
	NVME_SCT_GENERIC = 0x0, ///< successful completion
	NVME_SCT_CMDSPEC = 0x1, ///< invalid command opcode
	NVME_SCT_MEDIA   = 0x2, ///< invalid field in command
	NVME_SCT_PATH    = 0x3, ///< invalid command opcode
	NVME_SCT_VENDOR  = 0x7, ///< invalid command opcode
};

/**
 * Status Codes for for Status-Code-Type(0x0)
 *
 * @enum nvme_sc_generic
 */
enum nvme_sc_generic {
	NVME_SC_GENERIC_SUCCESS             = 0x0, ///< Successful Completion
	NVME_SC_GENERIC_INVALID_OPCODE      = 0x1, ///< Invalid Command Opcode
	NVME_SC_GENERIC_INVALID_FIELD       = 0x2, ///< Invalid Field in Command
	NVME_SC_GENERIC_COMMAND_ID_CONFLICT = 0x3, ///< Command ID Conflict
	NVME_SC_GENERIC_DATA_TRANSFER_ERROR = 0x4, ///< Data Transfer Error
	NVME_SC_GENERIC_ABORTED_POWER_LOSS =
		0x5, ///< Commands Aborted due to Power Loss Notification
};

/**
 * Status Codes for Command-Specific aka Status-Code-Type(0x1)
 *
 * @enum nvme_sc_cmdspec
 */
enum nvme_sc_cmdspec {
	NVME_SC_CMDSPEC_COMPLETION_QUEUE_INVALID      = 0x0,  ///< Completion Queue Invalid
	NVME_SC_CMDSPEC_ZONE_BOUNDARY_ERROR           = 0xb8, ///< Zone Boundary Error
	NVME_SC_CMDSPEC_ZONE_IS_FULL                  = 0xb9, ///< Zone Is Full
	NVME_SC_CMDSPEC_ZONE_IS_READ_ONLY             = 0xba, ///< Zone Is Read Only
	NVME_SC_CMDSPEC_ZONE_IS_OFFLINE               = 0xbb, ///< Zone Is Offline
	NVME_SC_CMDSPEC_ZONE_INVALID_WRITE            = 0xbc, ///< Zone Invalid Write
	NVME_SC_CMDSPEC_TOO_MANY_ACTIVE_ZONES         = 0xbd, ///< Too Many Active Zones
	NVME_SC_CMDSPEC_TOO_MANY_OPEN_ZONES           = 0xbe, ///< Too Many Open Zones
	NVME_SC_CMDSPEC_INVALID_ZONE_STATE_TRANSITION = 0xbf, ///< Invalid Zone State Transition
};

/**
 * Status Codes for INTERNAL_PATH_ERROR aka Status-Code-Type(0x2)
 *
 * @enum nvme_sc_media
 */
enum nvme_sc_media {
	NVME_SC_MEDIA_INTERNAL_PATH_ERROR = 0x0, ///< Internal Path Error
};

/**
 * Log Page identifiers
 *
 * @enum nvme_log_lpi
 */
enum nvme_log_lpi {
	NVME_LOG_LPI_SUPPORTED                       = 0x0, ///< Supported Log Pages
	NVME_LOG_LPI_ERROR                           = 0x1, ///< Error Information
	NVME_LOG_LPI_HEALTH_INFORMATION              = 0x2, ///< SMART / Health Information
	NVME_LOG_LPI_FIRMWARE_SLOT                   = 0x3, ///< Firmware Slot Information
	NVME_LOG_LPI_CHANGED_NS_LIST                 = 0x4, ///< Changed Namespace List
	NVME_LOG_LPI_COMMAND_EFFECTS_LOG             = 0x5, ///< Commands Supported and Effects
	NVME_LOG_LPI_DEVICE_SELF_TEST                = 0x6, ///< Device Self-test
	NVME_LOG_LPI_TELEMETRY_HOST_INITIATED        = 0x7, ///< Telemetry Host-Initiated
	NVME_LOG_LPI_TELEMETRY_CTRLR_INITIATED       = 0x8, ///< Telemetry Controller-Initiated
	NVME_LOG_LPI_ENDURANCE_GROUP_INFORMATION     = 0x9, ///< Endurance Group Information
	NVME_LOG_LPI_PREDICTABLE_LATENCY_PER_NVM_SET = 0xa, ///< Predictable Latency Per NVM Set
	NVME_LOG_LPI_PREDICTABLE_LATENCY_EVENT_AGGREGATE =
		0xb, ///< Predictable Latency Event Aggregate
	NVME_LOG_LPI_ASSYMETRIC_NAMESPACE_ACCESS     = 0xc,  ///< Asymmetric Namespace Access
	NVME_LOG_LPI_PERSISTENT_EVENT_LOG            = 0xd,  ///< Persistent Event Log
	NVME_LOG_LPI_ENDURANCE_GROUP_EVENT_AGGREGATE = 0xf,  ///< Endurance Group Event Aggregate
	NVME_LOG_LPI_LOG_DISCOVERY                   = 0x70, ///< Predictable Latency Per NVM Set
	NVME_LOG_LPI_RESERVATION_NOTIFICATION = 0x80, ///< Predictable Latency Event Aggregate
	NVME_LOG_LPI_SANITIZE_STATUS          = 0x81, ///< Asymmetric Namespace Access
	NVME_LOG_LPI_VENDOR_SPECIFIC_START    = 0xc0, ///< Vendor Specific start
	NVME_LOG_LPI_VENDOR_SPECIFIC_END      = 0xff, ///< Vendor Specific start
};

/**
 * Device Health
 *
 * @struct
 */
struct nvme_health_entry {
	uint8_t crit_warn;          ///< Critical Warning
	uint16_t comp_temp;         ///< Composite Temperature (Temp.)
	uint8_t avail_spare;        ///< Available Spare (pct)
	uint8_t avail_spare_thresh; ///< Available Spare Threshold (pct)
	uint8_t pct_used;           ///< Percentage used (pct), can exceed 100
	uint8_t eg_crit_warn_sum;   ///< Endurance Group Critical Warning Summary
	uint8_t rsvd7[25];          ///< Reserved...
	uint8_t rsvd8;              ///< Reserved...
};

/**
 * Command Opcodes -- for Admin Commands
 *
 * @enum nvme_opc_adm
 */
enum nvme_opc_adm {
	NVME_OPC_ADM_DELETE_IO_SQ            = 0x0,  ///< Delete I/O Submission Queue
	NVME_OPC_ADM_CREATE_IO_SQ            = 0x1,  ///< Create I/O Submission Queue
	NVME_OPC_ADM_GET_LOG_PAGE            = 0x2,  ///< Get Log Page
	NVME_OPC_ADM_DELETE_IO_CQ            = 0x4,  ///< Delete I/O Completion Queue
	NVME_OPC_ADM_CREATE_IO_CQ            = 0x5,  ///< Create I/O Completion Queue
	NVME_OPC_ADM_IDENTIFY                = 0x6,  ///< Identify
	NVME_OPC_ADM_ABORT                   = 0x8,  ///< Abort
	NVME_OPC_ADM_SFEAT                   = 0x9,  ///< Set Features
	NVME_OPC_ADM_GFEAT                   = 0xa,  ///< Get Features
	NVME_OPC_ADM_ASYNC_EVENT_REQUEST     = 0xc,  ///< Async Event Request
	NVME_OPC_ADM_NS_MANAGEMENT           = 0xd,  ///< Namespace Management
	NVME_OPC_ADM_FIRMWARE_COMMIT         = 0x10, ///< Firmware Commit
	NVME_OPC_ADM_FIRMWARE_IMAGE_DOWNLOAD = 0x11, ///< Firmware Image Download
	NVME_OPC_ADM_DEVICE_SELF_TEST        = 0x14, ///< Device Self-test
	NVME_OPC_ADM_NS_ATTACHMENT           = 0x15, ///< Namespace Attachment
	NVME_OPC_ADM_KEEP_ALIVE              = 0x16, ///< Keep Alive
	NVME_OPC_ADM_DSEND                   = 0x19, ///< Directive Send
	NVME_OPC_ADM_DRECV                   = 0x1a, ///< Directive Receive
	NVME_OPC_ADM_VIRTUALIZATION_MGMT     = 0x1c, ///< Virtualization Management
	NVME_OPC_ADM_MI_SEND                 = 0x1d, ///< NVMe-MI Send
	NVME_OPC_ADM_MI_RECV                 = 0x1e, ///< NVMe-MI Receive
	NVME_OPC_ADM_CAPACITY_MGMT           = 0x20, ///< Capacity Management
	NVME_OPC_ADM_LOCKDOWN                = 0x24, ///< Lockdown
	NVME_OPC_ADM_DOORBELL_BUFFER_CONFIG  = 0x7c, ///< Doorbell buffer Config
	NVME_OPC_ADM_FABRICS_COMMANDS        = 0x7f, ///< Fabrics Commands
	NVME_OPC_ADM_FORMAT                  = 0x80, ///< Format
	NVME_OPC_ADM_SECURITY_SEND           = 0x81, ///< Security Send
	NVME_OPC_ADM_SECURITY_RECV           = 0x82, ///< Security Recv
	NVME_OPC_ADM_SANITIZE                = 0x84, ///< Sanitize
	NVME_OPC_ADM_GET_LBA_STATUS          = 0x86, ///< Get LBA Status
};

/**
 * Controller or Namespace Structure (CNS)
 *
 * @enum nvme_idfy
 */
enum nvme_idfy {
	NVME_IDFY_NS                = 0x0,  ///< Identify namespace
	NVME_IDFY_CTRLR             = 0x1,  ///< Identify controller
	NVME_IDFY_NSLIST            = 0x2,  ///< Active Namespace ID list
	NVME_IDFY_NSDSCR            = 0x3,  ///< Namespace ident. descr. list for active ns
	NVME_IDFY_SETL              = 0x4,  ///< ...
	NVME_IDFY_NS_IOCS           = 0x5,  ///< Identify namespace, command-set specific
	NVME_IDFY_CTRLR_IOCS        = 0x6,  ///< ...
	NVME_IDFY_NSLIST_IOCS       = 0x7,  ///< ...
	NVME_IDFY_NSLIST_ALLOC      = 0x10, ///< ...
	NVME_IDFY_NS_ALLOC          = 0x11, ///< ...
	NVME_IDFY_CTRLR_NS          = 0x12, ///< ...
	NVME_IDFY_CTRLR_SUB         = 0x13, ///< ...
	NVME_IDFY_CTRLR_PRI         = 0x14, ///< ...
	NVME_IDFY_CTRLR_SEC         = 0x15, ///< ...
	NVME_IDFY_NSGRAN            = 0x16, ///< ...
	NVME_IDFY_UUIDL             = 0x17, ///< ...
	NVME_IDFY_NSLIST_ALLOC_IOCS = 0x1a, ///< ...
	NVME_IDFY_NS_ALLOC_IOCS     = 0x1b, ///< ...
	NVME_IDFY_IOCS              = 0x1c, ///< ...
};

/**
 * Command Set Identifiers
 *
 * @enum nvme_csi
 */
enum nvme_csi {
	NVME_CSI_NVM = 0x0, ///< NVM Command Set Identifier
	NVME_CSI_KVS = 0x1, ///< KVS Command Set Identifier
	NVME_CSI_ZNS = 0x2, ///< ZNS Command Set Identifier
};

/**
 * doc...
 *
 * @struct
 */
struct nvme_dsm_range {
	uint32_t cattr; ///< Context attributes
	uint32_t nlb;   ///< Length in logical blocks
	uint64_t slba;  ///< Starting LBA
};

/**
 * Command Opcodes for the NVM Command-Set
 *
 * @enum nvme_opc_nvm
 */
enum nvme_opc_nvm {
	NVME_OPC_NVM_FLUSH                = 0x0,  ///< Flush
	NVME_OPC_NVM_WRITE                = 0x1,  ///< Write
	NVME_OPC_NVM_READ                 = 0x2,  ///< Read
	NVME_OPC_NVM_WRITE_UNCORRECTABLE  = 0x4,  ///< Write Uncorrectable
	NVME_OPC_NVM_COMPARE              = 0x5,  ///< Compare
	NVME_OPC_NVM_WRITE_ZEROES         = 0x8,  ///< Write Zeroes
	NVME_OPC_NVM_DATASET_MANAGEMENT   = 0x9,  ///< Dataset Management
	NVME_OPC_NVM_VERIFY               = 0xc,  ///< Verify
	NVME_OPC_NVM_RESERVATION_REGISTER = 0xd,  ///< Reservation Register
	NVME_OPC_NVM_RESERVATION_REPORT   = 0xe,  ///< Reservation Report
	NVME_OPC_NVM_RESERVATION_ACQUIRE  = 0x11, ///< Reservation Acquire
	NVME_OPC_NVM_RESERVATION_RELEASE  = 0x15, ///< Reservation Release
	NVME_OPC_NVM_SCOPY                = 0x19, ///< Simple Copy
};

/**
 * Command Opcodes for the ZNS Command-Set
 *
 * @enum nvme_opc_zns
 */
enum nvme_opc_zns {
	NVME_OPC_ZNS_MGMT_SEND = 0x79, ///< Zone Management Send
	NVME_OPC_ZNS_MGMT_RECV = 0x7a, ///< Zone Management Receive
	NVME_OPC_ZNS_APPEND    = 0x7d, ///< Zone Append
};

/**
 * This is a doc description
 *
 * @enum nvme_zns_zsa
 */
enum nvme_zns_zsa {
	NVME_ZNS_ZSA_CLOSE               = 0x0,  ///< ...
	NVME_ZNS_ZSA_FINISH              = 0x1,  ///< ...
	NVME_ZNS_ZSA_OPEN                = 0x3,  ///< ...
	NVME_ZNS_ZSA_RESET               = 0x4,  ///< ...
	NVME_ZNS_ZSA_OFFLINE             = 0x5,  ///< ...
	NVME_ZNS_ZSA_SET_DESCR_EXTENSION = 0x10, ///< ...
	NVME_ZNS_ZSA_ZRWA_FLUSH          = 0x11, ///< ...
};

/**
 * This is a doc description
 *
 * @enum nvme_zns_zra
 */
enum nvme_zns_zra {
	NVME_ZNS_ZRA_REPORT_ZONES          = 0x0, ///< ...
	NVME_ZNS_ZRA_EXTENDED_REPORT_ZONES = 0x1, ///< ...
};

/**
 * This is a doc description
 *
 * @enum nvme_zns_zras
 */
enum nvme_zns_zras {
	NVME_ZNS_ZRAS_LIST_ALL      = 0x0, ///< List all zones
	NVME_ZNS_ZRAS_LIST_EMPTY    = 0x1, ///< List the zones in the ZSE:Empty state
	NVME_ZNS_ZRAS_LIST_IOPEN    = 0x2, ///< List all zones in the ZSIO:Implicitly Opened state
	NVME_ZNS_ZRAS_LIST_EOPEN    = 0x3, ///< List all zones in the ZSEO:Explicitly Opened state
	NVME_ZNS_ZRAS_LIST_CLOSED   = 0x4, ///< List all zones in the ZSC:Closed state
	NVME_ZNS_ZRAS_LIST_FULL     = 0x5, ///< List the zones in the ZSF:Full state
	NVME_ZNS_ZRAS_LIST_READONLY = 0x6, ///< List the zones in the ZSRO: Read Only state
	NVME_ZNS_ZRAS_LIST_OFFLINE  = 0x7, ///< List the zones in the ZSO:Offline state
	NVME_ZNS_ZRAS_LIST_ATTR     = 0x9, ///< List all zones
};

/**
 * Command Opcodes for the KVS Command-Set
 *
 * @enum nvme_opc_kvs
 */
enum nvme_opc_kvs {
	NVME_OPC_KVS_STORE    = 0x1,  ///< Store Key-Value pair
	NVME_OPC_KVS_RETRIEVE = 0x2,  ///< Retrieve Key-Value pair
	NVME_OPC_KVS_DELETE   = 0x10, ///< Delete Key-Value pair
	NVME_OPC_KVS_EXIST    = 0x14, ///< Check if key exists
	NVME_OPC_KVS_LIST     = 0x6,  ///< List keys
};

/**
 * NVM Write Command
 *
 * @struct
 */
struct nvme_nvm_write {
	uint8_t opc;       ///< Command Opcode
	uint8_t rsvd_cdw0; ///< Command Opcode
	uint16_t cid;      ///< Command Identifier
	uint32_t nsid;     ///< Namespace Identifier"
	uint32_t cdw02;    ///< Command Dword 02
	uint32_t cdw03;    ///< Command Dword 03
	uint32_t cdw04;    ///< Command Dword 04
	uint32_t cdw05;    ///< Command Dword 05
	uint32_t cdw06;    ///< Command Dword 06
	uint32_t cdw07;    ///< Command Dword 07
	uint32_t cdw08;    ///< Command Dword 08
	uint32_t cdw09;    ///< Command Dword 09
	uint64_t slba;     ///< Starting LBA
	struct {
		uint32_t nlb    : 16; ///< Number of Logical Blocks
		uint32_t rsvd2  : 4;  ///< Reserved
		uint32_t dtype  : 4;  ///< Directtive Type
		uint32_t stc    : 1;  ///< Storage Tag Check
		uint32_t rsvd1  : 1;  ///< Reserved
		uint32_t prinfo : 4;  ///< Protection Information
		uint32_t fua    : 1;  ///< Force Unit Access
		uint32_t lr     : 1;  ///< Limited Retry
	} bits1;
	uint8_t dspec; ///< Directive Specific
	uint8_t rsvd1; ///< Reserved
	struct {
		uint8_t rsvd : 8; ///< Reserved
	} bits2;
	uint32_t cdw14; ///< Command Dword 14
	struct {
		uint32_t lbat  : 16; ///< Logical Block Application Tag
		uint32_t lbatm : 16; ///< Logical Block Application Tag Mask
	} bits3;
};

/**
 * NVM Read Command
 *
 * @struct
 */
struct nvme_nvm_read {
	uint8_t opc;       ///< Command Opcode
	uint8_t rsvd_cdw0; ///< Command Opcode
	uint16_t cid;      ///< Command Identifier
	uint32_t nsid;     ///< Namespace Identifier"
	uint32_t cdw02;    ///< Command Dword 02
	uint32_t cdw03;    ///< Command Dword 03
	uint32_t cdw04;    ///< Command Dword 04
	uint32_t cdw05;    ///< Command Dword 05
	uint32_t cdw06;    ///< Command Dword 06
	uint32_t cdw07;    ///< Command Dword 07
	uint32_t cdw08;    ///< Command Dword 08
	uint32_t cdw09;    ///< Command Dword 09
	uint64_t slba;     ///< Starting LBA
	struct {
		uint32_t nlb    : 16; ///< Number of Logical Blocks
		uint32_t rsvd2  : 4;  ///< Reserved
		uint32_t dtype  : 4;  ///< Directtive Type
		uint32_t stc    : 1;  ///< Storage Tag Check
		uint32_t rsvd1  : 1;  ///< Reserved
		uint32_t prinfo : 4;  ///< Protection Information
		uint32_t fua    : 1;  ///< Force Unit Access
		uint32_t lr     : 1;  ///< Limited Retry
	} bits1;
	uint8_t dspec; ///< Directive Specific
	uint8_t rsvd1; ///< Reserved
	struct {
		uint8_t rsvd : 8; ///< Reserved
	} bits2;
	uint32_t cdw14; ///< Command Dword 14
	struct {
		uint32_t lbat  : 16; ///< Logical Block Application Tag
		uint32_t lbatm : 16; ///< Logical Block Application Tag Mask
	} bits3;
};

/**
 * NVM Write Uncorrectable Command
 *
 * @struct
 */
struct nvme_nvm_write_uncor {
	uint8_t opc;       ///< Command Opcode
	uint8_t rsvd_cdw0; ///< Command Opcode
	uint16_t cid;      ///< Command Identifier
	uint32_t nsid;     ///< Namespace Identifier"
	uint32_t cdw02;    ///< Command Dword 02
	uint32_t cdw03;    ///< Command Dword 03
	uint32_t cdw04;    ///< Command Dword 04
	uint32_t cdw05;    ///< Command Dword 05
	uint32_t cdw06;    ///< Command Dword 06
	uint32_t cdw07;    ///< Command Dword 07
	uint32_t cdw08;    ///< Command Dword 08
	uint32_t cdw09;    ///< Command Dword 09
	uint64_t slba;     ///< Starting LBA
	struct {
		uint32_t nlb        : 16; ///< Number of Logical Blocks
		uint32_t rsvd_cdw12 : 16; ///< Reserved
	} bits1;
	uint32_t cdw13; ///< Command Dword 13
	uint32_t cdw14; ///< Command Dword 14
	uint32_t cdw15; ///< Command Dword 15
};

/**
 * NVM Write Zeroes Command
 *
 * @struct
 */
struct nvme_nvm_write_zeroes {
	uint8_t opc;       ///< Command Opcode
	uint8_t rsvd_cdw0; ///< Command Opcode
	uint16_t cid;      ///< Command Identifier
	uint32_t nsid;     ///< Namespace Identifier"
	uint32_t cdw02;    ///< Command Dword 02
	uint32_t cdw03;    ///< Command Dword 03
	uint32_t cdw04;    ///< Command Dword 04
	uint32_t cdw05;    ///< Command Dword 05
	uint32_t cdw06;    ///< Command Dword 06
	uint32_t cdw07;    ///< Command Dword 07
	uint32_t cdw08;    ///< Command Dword 08
	uint32_t cdw09;    ///< Command Dword 09
	uint64_t slba;     ///< Starting LBA
	struct {
		uint32_t nlb        : 16; ///< Number of Logical Blocks
		uint32_t rsvd_cdw12 : 16; ///< Reserved
	} bits1;
	uint32_t cdw13; ///< Command Dword 13
	uint32_t cdw14; ///< Command Dword 14
	uint32_t cdw15; ///< Command Dword 15
};
