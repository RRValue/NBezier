#include <NBezier/vector.h>

#include <gtest/gtest.h>

TEST(Vector, Init)
{
    const Vector3 v = {1.0f, 2.0f, 3.0f};

    EXPECT_EQ(v.a[0], 1.0f);
    EXPECT_EQ(v.a[1], 2.0f);
    EXPECT_EQ(v.a[2], 3.0f);
}
