#include <gtest/gtest.h>

// Deklaracja funkcji z src
void hello();

TEST(Exercise1Test, BasicTest) {
    std::cout<<"Hello, Gtest!"<<std::endl;
    EXPECT_EQ(1 + 1, 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
