/**
 * NVMe
 *
 * Library bundle header for NVMe
 *
 * The bundle-header provides a single point of entry for library users to include. This is done
 * such that all the other headers do not have to:
 *
 * - Include other headers (See Rob Pike)
 * - Use include-guard
 * - Use C++ extern
 *
 * Additionally, this allows for composition when using the NVMe library. In case the
 * library user have another definition for e.g. integer types, or only wants a subset etc. then
 * they can compose utilization that serves them best.
 *
 * ------------------------------------------------------------------------------------------------
 * Copyright (C) Simon A. F. Lund <os@safl.dk>
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * @file libnvme.h
 * ------------------------------------------------------------------------------------------------
 * NOTE: This file is auto-generated using yace: https://github.com/safl/yace
 */
#ifndef __LIBNVME_H
#define __LIBNVME_H

#ifdef __cplusplus
extern "C" {
#endif

#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <libnvme_prep.h>
#include <libnvme_core.h>
#include <libnvme_pp.h>

#ifdef __cplusplus
}
#endif

#endif /* __LIBNVME_H */
