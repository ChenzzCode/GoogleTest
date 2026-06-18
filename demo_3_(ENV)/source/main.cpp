#include <gtest/gtest.h>
#include <iostream>
#include <chrono>
#include <fstream>

// 全局测试环境类 - 必须继承 testing::Environment
class GlobalTestEnvironment : public testing::Environment {
public:
    // 在所有测试开始前执行（只执行一次）
    virtual void SetUp() override {
        std::cout << "🌍 全局测试环境初始化" << std::endl;
        std::cout << "================================" << std::endl;
        
        start_time = std::chrono::steady_clock::now();
        
        // 模拟全局初始化工作
        database_connected = ConnectToDatabase();
        config_loaded = LoadConfiguration();
        test_file_created = CreateTestFile();
        
        std::cout << "✅ 数据库连接: " << (database_connected ? "成功" : "失败") << std::endl;
        std::cout << "✅ 配置文件加载: " << (config_loaded ? "成功" : "失败") << std::endl;
        std::cout << "✅ 测试文件创建: " << (test_file_created ? "成功" : "失败") << std::endl;
    }
    
    // 在所有测试结束后执行（只执行一次）
    virtual void TearDown() override {
        auto end_time = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
            end_time - start_time);
        
        std::cout << "================================" << std::endl;
        std::cout << "🌍 全局测试环境清理" << std::endl;
        std::cout << "⏱️  测试总耗时: " << duration.count() << " 毫秒" << std::endl;
        
        // 模拟全局清理工作
        DisconnectDatabase();
        CleanupTestFile();
        
        std::cout << "✅ 数据库已断开连接" << std::endl;
        std::cout << "✅ 测试文件已清理" << std::endl;
    }
    
    // 全局状态访问方法
    static bool IsDatabaseConnected() { return database_connected; }
    static bool IsConfigLoaded() { return config_loaded; }
    
private:
    // 模拟全局操作
    bool ConnectToDatabase() {
        std::cout << "连接数据库中..." << std::endl;
        return true;
    }
    
    bool LoadConfiguration() {
        std::cout << "加载配置文件中..." << std::endl;
        return true;
    }
    
    bool CreateTestFile() {
        std::ofstream file("test_temp.txt");
        if (file) {
            file << "临时测试文件内容";
            file.close();
            return true;
        }
        return false;
    }
    
    void DisconnectDatabase() {
        database_connected = false;
    }
    
    void CleanupTestFile() {
        remove("test_temp.txt");
    }
    
    std::chrono::steady_clock::time_point start_time;
    
    // 全局状态
    static bool database_connected;
    static bool config_loaded;
    static bool test_file_created;
};

// 初始化静态成员
bool GlobalTestEnvironment::database_connected = false;
bool GlobalTestEnvironment::config_loaded = false;
bool GlobalTestEnvironment::test_file_created = false;

// 普通的测试用例
TEST(DatabaseTest, ConnectionStatus) {
    // 可以检查全局环境的状态
    EXPECT_TRUE(GlobalTestEnvironment::IsDatabaseConnected());
    EXPECT_TRUE(GlobalTestEnvironment::IsConfigLoaded());
}

TEST(APITest, BasicFunctionality) {
    // 假设这些测试依赖于全局的数据库连接
    EXPECT_TRUE(GlobalTestEnvironment::IsDatabaseConnected());
    
    // 模拟一些测试逻辑
    int result = 2 + 3;
    EXPECT_EQ(result, 5);
}

// 文件操作测试
TEST(FileTest, FileExistence) {
    // 检查测试文件是否存在（依赖全局环境创建的文件）
    std::ifstream file("test_temp.txt");
    bool file_exists = file.good();
    file.close();
    EXPECT_TRUE(file_exists);
}

int main(int argc, char **argv) {
    // 初始化 gtest
    testing::InitGoogleTest(&argc, argv);
    
    // 注册全局测试环境 - 必须步骤！
    testing::AddGlobalTestEnvironment(new GlobalTestEnvironment);
    
    std::cout << "🚀 开始运行测试套件..." << std::endl;
    int result = RUN_ALL_TESTS();
    std::cout << "🎉 测试套件运行完成" << std::endl;
    
    return result;
}
















