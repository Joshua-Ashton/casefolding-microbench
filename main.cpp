#include <benchmark/benchmark.h>
#include "test_cpp_helpers.h"
#include <cassert>

// Disable freq scaling before running:
// sudo cpupower frequency-set --governor performance

/////////////////////
// memcpy
/////////////////////

static void memcmp_ascii_eq(benchmark::State &state)
{
        const char *test_string = "JO2dUrHCkpmyErqvmotU7gkRfugl4vdmjX6oYwRRlFBPGbUc7xwW8z5svnbL2zEn0KWi3sZ5Yt4xMuV9bEOQWBwzJD0v81HTn8yweDkkHPMuBY44EzczeNpn577Nazj7vnFdkQtfS9KJI9gtJSH05zUnhY1vsodEjHvItarHpAEk33lpRIVU27dnpXxbRiwNSNvgrOnLQwOCiXk2K0bml9CfR6u0tDXNh8bGqzTBetcKvAaf7IpyMzrMEvVj5FRhOuo4OIb311m40KcM7hFjftKNwTxl86B3eJWd1JAQ8HuNXHFLde26eqTg7HUvwxUhIvKyOtRkU0TY1xb8Kmq1GEcAvNwCLJILuHQ02YJCn0D4CFRtDl7SbAZXMJtRwYtpnJg1xGMMR0si8ZrgN6B2BxIj9z0tcFWrhiYDcFnG82cbchypy8NadvDB43dzQP3mk7CNqmA7iMOyqZbpzTrlOylshpGLZmnL8wXBcVpkDjRVz0s4osOhW4C8pNsuBUdK";
        size_t test_string_len = strlen(test_string);
        assert(strlen(test_string) == 512);

        for (auto _ : state)
        {
                int ret = test_memcmp(test_string, test_string, test_string_len);
                assert(ret == 0);
        }
}
BENCHMARK(memcmp_ascii_eq);

static void memcmp_ascii_immediately_neq(benchmark::State &state)
{
        const char *test_string1 = "JO2dUrHCkpmyErqvmotU7gkRfugl4vdmjX6oYwRRlFBPGbUc7xwW8z5svnbL2zEn0KWi3sZ5Yt4xMuV9bEOQWBwzJD0v81HTn8yweDkkHPMuBY44EzczeNpn577Nazj7vnFdkQtfS9KJI9gtJSH05zUnhY1vsodEjHvItarHpAEk33lpRIVU27dnpXxbRiwNSNvgrOnLQwOCiXk2K0bml9CfR6u0tDXNh8bGqzTBetcKvAaf7IpyMzrMEvVj5FRhOuo4OIb311m40KcM7hFjftKNwTxl86B3eJWd1JAQ8HuNXHFLde26eqTg7HUvwxUhIvKyOtRkU0TY1xb8Kmq1GEcAvNwCLJILuHQ02YJCn0D4CFRtDl7SbAZXMJtRwYtpnJg1xGMMR0si8ZrgN6B2BxIj9z0tcFWrhiYDcFnG82cbchypy8NadvDB43dzQP3mk7CNqmA7iMOyqZbpzTrlOylshpGLZmnL8wXBcVpkDjRVz0s4osOhW4C8pNsuBUdK";
        const char *test_string2 = "7xwW8z5svnbL2zEn0KWi3sZ5Yt4xMuV9bEOQWBwzJD0v81HTn8yweDkkHPMuBY44EzczeNpn577Nazj7vnFdkQtfS9KJI9gtJSH05zUnhY1vsodEjHvItarHpAEk33lpRIVU27dnpXxbRiwNSNvgrOnLQwOCiXk2K0bml9CfR6u0tDXNh8bGqzTBetcKvAaf7IpyMzrMEvVj5FRhOuo4OIb311m40KcM7hFjftKNwTxl86B3eJWd1JAQ8HuNXHFLde26eqTg7HUvwxUhIvKyOtRkU0TY1xb8Kmq1GEcAvNwCLJILuHQ02YJCn0D4CFRtDl7SbAZXMJtRwYtpnJg1xGMMR0si8ZrgN6B2BxIj9z0tcFWrhiYDcFnG82cbchypy8NadvDB43dzQP3mk7CNqmA7iMOyqZbpzTrlOylshpGLZmnL8wXBcVpkDjRVz0s4osOhW4C8pNsuBUdKJO2dUrHCkpmyErqvmotU7gkRfugl4vdmjX6oYwRRlFBPGbUc";
        assert(strlen(test_string1) == strlen(test_string2));
        size_t test_string_len = strlen(test_string1);

        for (auto _ : state)
        {
                int ret = test_memcmp(test_string1, test_string2, test_string_len);
                assert(ret != 0);
        }
}
BENCHMARK(memcmp_ascii_immediately_neq);

static void memcmp_unicode_eq(benchmark::State &state)
{
        const char *test_string = "ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺa";
        size_t test_string_len = strlen(test_string);
        assert(strlen(test_string) == 512);

        for (auto _ : state)
        {
                int ret = test_memcmp(test_string, test_string, test_string_len);
                assert(ret == 0);
        }
}
BENCHMARK(memcmp_unicode_eq);

static void memcmp_unicode_immediately_neq(benchmark::State &state)
{
        const char *test_string1 = "ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺa";
        const char *test_string2 = "🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺaἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙";
        assert(strlen(test_string1) == strlen(test_string2));
        assert(strlen(test_string1) == 512);
        size_t test_string_len = strlen(test_string1);

        for (auto _ : state)
        {
                int ret = test_memcmp(test_string1, test_string2, test_string_len);
                assert(ret != 0);
        }
}
BENCHMARK(memcmp_unicode_immediately_neq);

/////////////////////
// utf8_strncasecmp
/////////////////////

static void utf8_strncasecmp_ascii_eq(benchmark::State &state)
{
        const char *test_string = "JO2dUrHCkpmyErqvmotU7gkRfugl4vdmjX6oYwRRlFBPGbUc7xwW8z5svnbL2zEn0KWi3sZ5Yt4xMuV9bEOQWBwzJD0v81HTn8yweDkkHPMuBY44EzczeNpn577Nazj7vnFdkQtfS9KJI9gtJSH05zUnhY1vsodEjHvItarHpAEk33lpRIVU27dnpXxbRiwNSNvgrOnLQwOCiXk2K0bml9CfR6u0tDXNh8bGqzTBetcKvAaf7IpyMzrMEvVj5FRhOuo4OIb311m40KcM7hFjftKNwTxl86B3eJWd1JAQ8HuNXHFLde26eqTg7HUvwxUhIvKyOtRkU0TY1xb8Kmq1GEcAvNwCLJILuHQ02YJCn0D4CFRtDl7SbAZXMJtRwYtpnJg1xGMMR0si8ZrgN6B2BxIj9z0tcFWrhiYDcFnG82cbchypy8NadvDB43dzQP3mk7CNqmA7iMOyqZbpzTrlOylshpGLZmnL8wXBcVpkDjRVz0s4osOhW4C8pNsuBUdK";
        size_t test_string_len = strlen(test_string);
        assert(strlen(test_string) == 512);

        struct unicode_map *um = utf8_load(UNICODE_AGE(12, 1, 0));
        struct qstr str_1 = QSTR_INIT((unsigned char *)test_string, (uint32_t)test_string_len);
        struct qstr str_2 = QSTR_INIT((unsigned char *)test_string, (uint32_t)test_string_len);
        for (auto _ : state)
        {
                int ret = test_utf8_strncasecmp(um, &str_1, &str_2);
                assert(ret == 0);
        }
}
BENCHMARK(utf8_strncasecmp_ascii_eq);

static void utf8_strncasecmp_ascii_immediately_neq(benchmark::State &state)
{
        const char *test_string1 = "JO2dUrHCkpmyErqvmotU7gkRfugl4vdmjX6oYwRRlFBPGbUc7xwW8z5svnbL2zEn0KWi3sZ5Yt4xMuV9bEOQWBwzJD0v81HTn8yweDkkHPMuBY44EzczeNpn577Nazj7vnFdkQtfS9KJI9gtJSH05zUnhY1vsodEjHvItarHpAEk33lpRIVU27dnpXxbRiwNSNvgrOnLQwOCiXk2K0bml9CfR6u0tDXNh8bGqzTBetcKvAaf7IpyMzrMEvVj5FRhOuo4OIb311m40KcM7hFjftKNwTxl86B3eJWd1JAQ8HuNXHFLde26eqTg7HUvwxUhIvKyOtRkU0TY1xb8Kmq1GEcAvNwCLJILuHQ02YJCn0D4CFRtDl7SbAZXMJtRwYtpnJg1xGMMR0si8ZrgN6B2BxIj9z0tcFWrhiYDcFnG82cbchypy8NadvDB43dzQP3mk7CNqmA7iMOyqZbpzTrlOylshpGLZmnL8wXBcVpkDjRVz0s4osOhW4C8pNsuBUdK";
        const char *test_string2 = "7xwW8z5svnbL2zEn0KWi3sZ5Yt4xMuV9bEOQWBwzJD0v81HTn8yweDkkHPMuBY44EzczeNpn577Nazj7vnFdkQtfS9KJI9gtJSH05zUnhY1vsodEjHvItarHpAEk33lpRIVU27dnpXxbRiwNSNvgrOnLQwOCiXk2K0bml9CfR6u0tDXNh8bGqzTBetcKvAaf7IpyMzrMEvVj5FRhOuo4OIb311m40KcM7hFjftKNwTxl86B3eJWd1JAQ8HuNXHFLde26eqTg7HUvwxUhIvKyOtRkU0TY1xb8Kmq1GEcAvNwCLJILuHQ02YJCn0D4CFRtDl7SbAZXMJtRwYtpnJg1xGMMR0si8ZrgN6B2BxIj9z0tcFWrhiYDcFnG82cbchypy8NadvDB43dzQP3mk7CNqmA7iMOyqZbpzTrlOylshpGLZmnL8wXBcVpkDjRVz0s4osOhW4C8pNsuBUdKJO2dUrHCkpmyErqvmotU7gkRfugl4vdmjX6oYwRRlFBPGbUc";
        assert(strlen(test_string1) == strlen(test_string2));
        assert(strlen(test_string1) == 512);
        size_t test_string_len = strlen(test_string1);

        struct unicode_map *um = utf8_load(UNICODE_AGE(12, 1, 0));
        struct qstr str_1 = QSTR_INIT((unsigned char *)test_string1, (uint32_t)test_string_len);
        struct qstr str_2 = QSTR_INIT((unsigned char *)test_string2, (uint32_t)test_string_len);
        for (auto _ : state)
        {
                int ret = test_utf8_strncasecmp(um, &str_1, &str_2);
                assert(ret == 1);
        }
}
BENCHMARK(utf8_strncasecmp_ascii_immediately_neq);

static void utf8_strncasecmp_unicode_eq(benchmark::State &state)
{
        const char *test_string = "ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺa";
        size_t test_string_len = strlen(test_string);
        assert(strlen(test_string) == 512);

        struct unicode_map *um = utf8_load(UNICODE_AGE(12, 1, 0));
        struct qstr str_1 = QSTR_INIT((unsigned char *)test_string, (uint32_t)test_string_len);
        struct qstr str_2 = QSTR_INIT((unsigned char *)test_string, (uint32_t)test_string_len);
        for (auto _ : state)
        {
                int ret = test_utf8_strncasecmp(um, &str_1, &str_2);  
                assert(ret == 0);
        }
}
BENCHMARK(utf8_strncasecmp_unicode_eq);

static void utf8_strncasecmp_unicode_immediately_neq(benchmark::State &state)
{
        const char *test_string1 = "ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺa";
        const char *test_string2 = "🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺaἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙";
        assert(strlen(test_string1) == strlen(test_string2));
        assert(strlen(test_string1) == 512);
        size_t test_string_len = strlen(test_string1);

        struct unicode_map *um = utf8_load(UNICODE_AGE(12, 1, 0));
        struct qstr str_1 = QSTR_INIT((unsigned char *)test_string1, (uint32_t)test_string_len);
        struct qstr str_2 = QSTR_INIT((unsigned char *)test_string2, (uint32_t)test_string_len);
        for (auto _ : state)
        {
                int ret = test_utf8_strncasecmp(um, &str_1, &str_2);
                assert(ret == 1);
        }
}
BENCHMARK(utf8_strncasecmp_unicode_immediately_neq);

static void utf8_strncasecmp_unicode_cased(benchmark::State &state)
{
        const char *test_string1 = "ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔa";
        const char *test_string2 = "ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺA";
        assert(strlen(test_string1) == strlen(test_string2));
        assert(strlen(test_string1) == 512);
        size_t test_string_len = strlen(test_string1);

        struct unicode_map *um = utf8_load(UNICODE_AGE(12, 1, 0));
        struct qstr str_1 = QSTR_INIT((unsigned char *)test_string1, (uint32_t)test_string_len);
        struct qstr str_2 = QSTR_INIT((unsigned char *)test_string2, (uint32_t)test_string_len);
        for (auto _ : state)
        {
                int ret = test_utf8_strncasecmp(um, &str_1, &str_2);
                assert(ret == 0);
        }
}
BENCHMARK(utf8_strncasecmp_unicode_cased);

/////////////////////
// utf8_strncasecmp_folded
/////////////////////

static void utf8_strncasecmp_folded_doesnt_work(benchmark::State &state)
{
        const char *test_string_cf = "ἠἠἠἠ";
        const char *test_string = "ἠἠἠἠ";
        //printf("%s\n", test_string_cf); // <- Encoding seems correct...
        size_t test_string_len = strlen(test_string);
        assert(strlen(test_string_cf) == strlen(test_string));

        struct unicode_map *um = utf8_load(UNICODE_AGE(12, 1, 0));
        struct qstr str_cf_1 = QSTR_INIT((unsigned char *)test_string_cf, (uint32_t)test_string_len);
        struct qstr str_2 = QSTR_INIT((unsigned char *)test_string, (uint32_t)test_string_len);
        for (auto _ : state)
        {
                // Josh:
                // This test does not work, yet the same thing with test_utf8_strncasecmp does.
                // Seems like utf8_strncasecmp_folded is just broken.
                int ret = test_utf8_strncasecmp_folded(um, &str_cf_1, &str_2);
                // Returns 1 for some reason.
                assert(ret == 0);
        }
}
BENCHMARK(utf8_strncasecmp_folded_doesnt_work);

static void utf8_strncasecmp_folded_ascii_eq(benchmark::State &state)
{
        const char *test_string_cf = "jo2durhckpmyerqvmotu7gkrfugl4vdmjx6oywrrlfbpgbuc7xww8z5svnbl2zen0kwi3sz5yt4xmuv9beoqwbwzjd0v81htn8ywedkkhpmuby44ezczenpn577nazj7vnfdkqtfs9kji9gtjsh05zunhy1vsodejhvitarhpaek33lprivu27dnpxxbriwnsnvgronlqwocixk2k0bml9cfr6u0tdxnh8bgqztbetckvaaf7ipymzrmevvj5frhouo4oib311m40kcm7hfjftknwtxl86b3ejwd1jaq8hunxhflde26eqtg7huvwxuhivkyotrku0ty1xb8kmq1gecavnwcljiluhq02yjcn0d4cfrtdl7sbazxmjtrwytpnjg1xgmmr0si8zrgn6b2bxij9z0tcfwrhiydcfng82cbchypy8nadvdb43dzqp3mk7cnqma7imoyqzbpztrloylshpglzmnl8wxbcvpkdjrvz0s4osohw4c8pnsubudk";
        const char *test_string = "JO2dUrHCkpmyErqvmotU7gkRfugl4vdmjX6oYwRRlFBPGbUc7xwW8z5svnbL2zEn0KWi3sZ5Yt4xMuV9bEOQWBwzJD0v81HTn8yweDkkHPMuBY44EzczeNpn577Nazj7vnFdkQtfS9KJI9gtJSH05zUnhY1vsodEjHvItarHpAEk33lpRIVU27dnpXxbRiwNSNvgrOnLQwOCiXk2K0bml9CfR6u0tDXNh8bGqzTBetcKvAaf7IpyMzrMEvVj5FRhOuo4OIb311m40KcM7hFjftKNwTxl86B3eJWd1JAQ8HuNXHFLde26eqTg7HUvwxUhIvKyOtRkU0TY1xb8Kmq1GEcAvNwCLJILuHQ02YJCn0D4CFRtDl7SbAZXMJtRwYtpnJg1xGMMR0si8ZrgN6B2BxIj9z0tcFWrhiYDcFnG82cbchypy8NadvDB43dzQP3mk7CNqmA7iMOyqZbpzTrlOylshpGLZmnL8wXBcVpkDjRVz0s4osOhW4C8pNsuBUdK";
        size_t test_string_len = strlen(test_string);
        assert(strlen(test_string_cf) == strlen(test_string));
        assert(strlen(test_string) == 512);

        struct unicode_map *um = utf8_load(UNICODE_AGE(12, 1, 0));
        struct qstr str_cf_1 = QSTR_INIT((unsigned char *)test_string_cf, (uint32_t)test_string_len);
        struct qstr str_2 = QSTR_INIT((unsigned char *)test_string, (uint32_t)test_string_len);
        for (auto _ : state)
        {
                int ret = test_utf8_strncasecmp_folded(um, &str_cf_1, &str_2);
                assert(ret == 0);
        }
}
BENCHMARK(utf8_strncasecmp_folded_ascii_eq);

static void utf8_strncasecmp_folded_ascii_immediately_neq(benchmark::State &state)
{
        const char *test_string_cf1 = "jo2durhckpmyerqvmotu7gkrfugl4vdmjx6oywrrlfbpgbuc7xww8z5svnbl2zen0kwi3sz5yt4xmuv9beoqwbwzjd0v81htn8ywedkkhpmuby44ezczenpn577nazj7vnfdkqtfs9kji9gtjsh05zunhy1vsodejhvitarhpaek33lprivu27dnpxxbriwnsnvgronlqwocixk2k0bml9cfr6u0tdxnh8bgqztbetckvaaf7ipymzrmevvj5frhouo4oib311m40kcm7hfjftknwtxl86b3ejwd1jaq8hunxhflde26eqtg7huvwxuhivkyotrku0ty1xb8kmq1gecavnwcljiluhq02yjcn0d4cfrtdl7sbazxmjtrwytpnjg1xgmmr0si8zrgn6b2bxij9z0tcfwrhiydcfng82cbchypy8nadvdb43dzqp3mk7cnqma7imoyqzbpztrloylshpglzmnl8wxbcvpkdjrvz0s4osohw4c8pnsubudk";
        const char *test_string2 = "7xwW8z5svnbL2zEn0KWi3sZ5Yt4xMuV9bEOQWBwzJD0v81HTn8yweDkkHPMuBY44EzczeNpn577Nazj7vnFdkQtfS9KJI9gtJSH05zUnhY1vsodEjHvItarHpAEk33lpRIVU27dnpXxbRiwNSNvgrOnLQwOCiXk2K0bml9CfR6u0tDXNh8bGqzTBetcKvAaf7IpyMzrMEvVj5FRhOuo4OIb311m40KcM7hFjftKNwTxl86B3eJWd1JAQ8HuNXHFLde26eqTg7HUvwxUhIvKyOtRkU0TY1xb8Kmq1GEcAvNwCLJILuHQ02YJCn0D4CFRtDl7SbAZXMJtRwYtpnJg1xGMMR0si8ZrgN6B2BxIj9z0tcFWrhiYDcFnG82cbchypy8NadvDB43dzQP3mk7CNqmA7iMOyqZbpzTrlOylshpGLZmnL8wXBcVpkDjRVz0s4osOhW4C8pNsuBUdKJO2dUrHCkpmyErqvmotU7gkRfugl4vdmjX6oYwRRlFBPGbUc";
        assert(strlen(test_string_cf1) == strlen(test_string2));
        assert(strlen(test_string_cf1) == 512);
        size_t test_string_len = strlen(test_string_cf1);

        struct unicode_map *um = utf8_load(UNICODE_AGE(12, 1, 0));
        struct qstr str_cf_1 = QSTR_INIT((unsigned char *)test_string_cf1, (uint32_t)test_string_len);
        struct qstr str_2 = QSTR_INIT((unsigned char *)test_string2, (uint32_t)test_string_len);
        for (auto _ : state)
        {
                int ret = test_utf8_strncasecmp_folded(um, &str_cf_1, &str_2);
                assert(ret == 1);
        }
}
BENCHMARK(utf8_strncasecmp_folded_ascii_immediately_neq);

static void utf8_strncasecmp_folded_unicode_eq(benchmark::State &state)
{
        const char *test_string_cf = "ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔa";
        const char *test_string = "ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔa";
        size_t test_string_len = strlen(test_string);
        assert(strlen(test_string_cf) == strlen(test_string));
        assert(strlen(test_string) == 512);

        struct unicode_map *um = utf8_load(UNICODE_AGE(12, 1, 0));
        struct qstr str_cf_1 = QSTR_INIT((unsigned char *)test_string_cf, (uint32_t)test_string_len);
        struct qstr str_2 = QSTR_INIT((unsigned char *)test_string, (uint32_t)test_string_len);
        for (auto _ : state)
        {
                int ret = test_utf8_strncasecmp_folded(um, &str_cf_1, &str_2);
                assert(ret == 0);
        }
}
BENCHMARK(utf8_strncasecmp_folded_unicode_eq);

static void utf8_strncasecmp_folded_unicode_immediately_neq(benchmark::State &state)
{
        const char *test_string_cf1 = "ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔa";
        const char *test_string2 = "🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺaἠB🐸ⓣ✨уⒺ✨蛙🐸ПaaL✨🐸ἠB🐸ⓣ✨уⒺ✨蛙";
        assert(strlen(test_string_cf1) == strlen(test_string2));
        assert(strlen(test_string_cf1) == 512);
        size_t test_string_len = strlen(test_string_cf1);

        struct unicode_map *um = utf8_load(UNICODE_AGE(12, 1, 0));
        struct qstr str_cf_1 = QSTR_INIT((unsigned char *)test_string_cf1, (uint32_t)test_string_len);
        struct qstr str_2 = QSTR_INIT((unsigned char *)test_string2, (uint32_t)test_string_len);
        for (auto _ : state)
        {
                int ret = test_utf8_strncasecmp_folded(um, &str_cf_1, &str_2);
                assert(ret == 1);
        }
}
BENCHMARK(utf8_strncasecmp_folded_unicode_immediately_neq);

static void utf8_strncasecmp_folded_unicode_cased(benchmark::State &state)
{
        const char *test_string_cf1 = "ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔ✨蛙🐸пaal✨🐸ἠb🐸ⓣ✨уⓔa";
        const char *test_string2 = "ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺ✨蛙🐸ПAAL✨🐸ἨB🐸Ⓣ✨УⒺA";
        assert(strlen(test_string_cf1) == strlen(test_string2));
        assert(strlen(test_string_cf1) == 512);
        size_t test_string_len = strlen(test_string_cf1);

        struct unicode_map *um = utf8_load(UNICODE_AGE(12, 1, 0));
        struct qstr str_cf_1 = QSTR_INIT((unsigned char *)test_string_cf1, (uint32_t)test_string_len);
        struct qstr str_2 = QSTR_INIT((unsigned char *)test_string2, (uint32_t)test_string_len);
        for (auto _ : state)
        {
                int ret = test_utf8_strncasecmp_folded(um, &str_cf_1, &str_2);
                assert(ret == 1);
        }
}
BENCHMARK(utf8_strncasecmp_folded_unicode_cased);

BENCHMARK_MAIN();