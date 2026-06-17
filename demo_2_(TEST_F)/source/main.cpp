#include <gtest/gtest.h>
#include <iostream>



class MyApp {
public:
    MyApp() = default;
    ~MyApp() = default;
    void add (int b) {
        a += b;
    }
    int get () {
        return a;
    }

public:
    int a{};
};


class MyAppTest : public testing::Test {
protected:
    void SetUp() override {
        std::cout << "局部测试环境setup" << std::endl;
        if (!m_test) {
            m_test = new MyApp();
        }
    }
    void TearDown() override {
        std::cout << "局部测试环境清除" << std::endl;
        if (m_test) {
            delete m_test;
            m_test = nullptr;
        }
    }
    MyApp* m_test;

};

TEST_F(MyAppTest, initTest) {
    EXPECT_EQ(m_test->get(), 0);
}

TEST_F(MyAppTest, addTest) {
    EXPECT_EQ(m_test->get(), 0);
    m_test->add(1);
    EXPECT_EQ(m_test->get(), 1);
}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);

    std::cout << "开始测试--------" << std::endl;
    return RUN_ALL_TESTS();

}

