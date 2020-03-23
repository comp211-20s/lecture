#include "gtest/gtest.h"

extern "C" {
#include "copy.h"
}

TEST(copy, return_dest) {
    char src[] = "hello";
    char dst[sizeof(src)];
    void *rv = copy(dst, src, sizeof(src));
    ASSERT_EQ(rv, dst);
}

TEST(copy, string) {
    char src[] = "hello";
    char dst[sizeof(src)];
    copy(dst, src, sizeof(src));
    ASSERT_STREQ(dst, src);
}
