#include <gtest/gtest.h>
#include "intVector.hpp"

TEST(ptr_ref_const, basic_test) {
 IntVector vec;
 EXPECT_EQ(vec.getOne(), 2);
}

//##############################

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
