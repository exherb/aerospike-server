/*
 * write.h
 *
 * Copyright (C) 2016 Aerospike, Inc.
 *
 * Portions may be licensed to Aerospike, Inc. under one or more contributor
 * license agreements.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/
 */

#pragma once

//==========================================================
// Includes.
//

#include "citrusleaf/alloc.h"

#include "base/predexp.h"
#include "base/transaction.h"


//==========================================================
// Forward declarations.
//

struct as_transaction_s;
struct cl_msg_s;
struct predexp_eval_base_s;


//==========================================================
// Typedefs & constants.
//

typedef void (*iops_cb)(void* udata, int result);

typedef struct iops_origin_s {
	struct cl_msg_s* msgp;
	struct predexp_eval_base_s* predexp;
	iops_cb cb;
	void* udata;
} iops_origin;


//==========================================================
// Public API.
//

transaction_status as_write_start(struct as_transaction_s* tr);

static inline void
iops_origin_destroy(iops_origin* origin)
{
	predexp_destroy(origin->predexp);
	cf_free(origin->msgp);
}
