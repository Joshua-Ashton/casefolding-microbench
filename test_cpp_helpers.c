#include "test_cpp_helpers.h"
#include "unicode.h"

int __attribute__ ((noinline)) test_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
        return memcmp(ptr1, ptr2, num);
}

int __attribute__ ((noinline)) test_utf8_strncasecmp(const struct unicode_map *um, const struct qstr *s1, const struct qstr *s2)
{
        return utf8_strncasecmp(um, s1, s2);
}

int __attribute__ ((noinline)) test_utf8_strncasecmp_folded(const struct unicode_map *um, const struct qstr *cf, const struct qstr *s1)
{
        return utf8_strncasecmp_folded(um, cf, s1);
}
