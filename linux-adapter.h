/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2023 Joshua Ashton
 * All rights reserved.
 */

#ifndef LINUX_ADAPTER_H
#define LINUX_ADAPTER_H

#ifndef __cplusplus
#pragma GCC diagnostic ignored "-Wpointer-sign"
#endif

#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>

typedef int8_t s8;
typedef uint8_t u8;
typedef int16_t s16;
typedef uint16_t u16;
typedef int32_t s32;
typedef uint32_t u32;
typedef int64_t s64;
typedef uint64_t u64;

#define kmalloc(x, y) malloc
#define kzalloc(x, y) calloc(x, 1)
#define kfree(x) free(x)

#define EXPORT_SYMBOL(x)
#define EXPORT_SYMBOL_GPL(x)
#define MODULE_LICENSE(x)

#define symbol_request(x) (&x)
#define symbol_put(x)

#define ERR_PTR(err)    ((void *)((long)(err)))
#define PTR_ERR(ptr)    ((long)(ptr))
#define IS_ERR(ptr)     ((unsigned long)(ptr) > (unsigned long)(-1000))

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

#define __pure                          __attribute__((__pure__))

/* mini dcache */

/* The hash is always the low bits of hash_len */
#ifdef __LITTLE_ENDIAN
 #define HASH_LEN_DECLARE u32 hash; u32 len
 #define bytemask_from_count(cnt)	(~(~0ul << (cnt)*8))
#else
 #define HASH_LEN_DECLARE u32 len; u32 hash
 #define bytemask_from_count(cnt)	(~(~0ul >> (cnt)*8))
#endif

/*
 * "quick string" -- eases parameter passing, but more importantly
 * saves "metadata" about the string (ie length and the hash).
 *
 * hash comes first so it snuggles against d_parent in the
 * dentry.
 */
struct qstr {
	union {
		struct {
			HASH_LEN_DECLARE;
		};
		u64 hash_len;
	};
	const unsigned char *name;
};

#define QSTR_INIT(n,l) { { { .len = l } }, .name = n }

#endif