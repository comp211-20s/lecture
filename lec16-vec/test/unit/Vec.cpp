#include "gtest/gtest.h"

extern "C" {
#include "stdint.h"
#include "Vec.h"
}

TEST(Vec, value) {
    Vec v = Vec_value(10, sizeof(int16_t));
    ASSERT_EQ(0, v.length);
    ASSERT_EQ(10, v.capacity);
    ASSERT_STREQ((char*)v.buffer, "");
    Vec_drop(&v);
}

TEST(Vec, drop) {
    Vec v = Vec_value(10, sizeof(int16_t));
    Vec_drop(&v);
    ASSERT_EQ(0, v.length);
    ASSERT_EQ(0, v.capacity);
    ASSERT_EQ(nullptr, v.buffer);
}

TEST(Vec, ref) {
    Vec v = Vec_value(10, sizeof(int16_t));
    ASSERT_EQ(v.buffer, Vec_ref(&v, 0));
    Vec_drop(&v);
}

TEST(Vec, set) {
    Vec v = Vec_value(1, sizeof(int16_t));

    int16_t x = 1;
    Vec_set(&v, 0, &x);
    ASSERT_EQ(1, v.length);

    int16_t *buffer = (int16_t*)v.buffer;
    ASSERT_EQ(x, buffer[0]);

    Vec_drop(&v);
}

TEST(Vec, get) {
    Vec v = Vec_value(1, sizeof(int16_t));
    // Dig into the abstraction to predefine some data
    int16_t *buffer = (int16_t*)v.buffer;
    buffer[0] = 1;
    v.length = 1;

    int16_t value = 0;
    Vec_get(&v, 0, &value);
    ASSERT_EQ(1, value);

    Vec_drop(&v);
}

// TODO: Contractual Tests


