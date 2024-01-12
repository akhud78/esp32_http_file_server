// https://github.com/ThrowTheSwitch/Unity

#include "unity.h"
#include "bar.h"

TEST_CASE("add zeros is zero", "[bar]")
{
    TEST_ASSERT_EQUAL(0, bar_add(0, 0));
}

