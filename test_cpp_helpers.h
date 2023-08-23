#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "unicode.h"

int __attribute__ ((noinline)) test_memcmp(const void *ptr1, const void *ptr2, size_t num);
int __attribute__ ((noinline)) test_utf8_strncasecmp(const struct unicode_map *um, const struct qstr *s1, const struct qstr *s2);
int __attribute__ ((noinline)) test_utf8_strncasecmp_folded(const struct unicode_map *um, const struct qstr *cf, const struct qstr *s1);

#ifdef __cplusplus
}
#endif
