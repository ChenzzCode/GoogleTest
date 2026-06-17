#include <gtest/gtest.h>
#include <string>

// 要测试的函数
std::string Greet(const std::string& name) {
    return "Hello, " + name + "!";
}

int Add(int a, int b) {
    return a + b;
}

std::string GetName() {
    return "hello world";
}

// 最简单的测试用例
TEST(FunctionTest, GreetFunction) {
    EXPECT_EQ(Greet("Alice"), "Hello, Alice!");
    EXPECT_EQ(Greet("Bob"), "Hello, Bob!");
}

TEST(FunctionTest, AddFunction) {
    EXPECT_EQ(Add(2, 3), 5);
    EXPECT_EQ(Add(-1, 1), 0);
    EXPECT_EQ(Add(0, 0), 0);
}

// 另一个测试套件
TEST(StringTest, BasicOperations) {
    std::string str = "hello";
    
    EXPECT_EQ(str.length(), 5);
    EXPECT_EQ(str + " world", "hello world");
    EXPECT_NE(str, "goodbye");
}

TEST(FunctionTest, GetNameFunction) {
    EXPECT_EQ(GetName(), "hello world");

}

TEST(my_test, expect_use) {
    EXPECT_EQ(1, 1);
    EXPECT_NE(1, 2);
    EXPECT_GT(5, 3);
    EXPECT_LE(1, 5);
}

TEST(my_test, assert_use) {
    ASSERT_TRUE(1 > 0);
    ASSERT_FALSE(1 < 0);
    EXPECT_NEAR(1.0/3.0, 0.3333333, 0.0001);
}

int main(int argc, char **argv) {
    // 初始化 gtest
    testing::InitGoogleTest(&argc, argv);
    
    std::cout << "🎯 开始运行测试..." << std::endl;
    
    // 运行所有测试
    return RUN_ALL_TESTS();
}
