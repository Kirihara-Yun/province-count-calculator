#include <iostream>
#include <vector>
#include "../include/ProvinceCounter.h"

/**
 * @brief 执行单个测试用例
 * @param testName 测试名称
 * @param isConnected 邻接矩阵
 * @param expected 预期结果
 */
void runTest(const std::string& testName, std::vector<std::vector<int>>& isConnected, int expected) {
    ProvinceCounter counter;
    int resultDFS = counter.countByDFS(isConnected);
    int resultUF = counter.countByUnionFind(isConnected);

    std::cout << "Test: " << testName << " - ";
    if (resultDFS == expected && resultUF == expected) {
        std::cout << "PASSED" << std::endl;
    } else {
        std::cout << "FAILED" << std::endl;
        std::cout << "  Expected: " << expected << std::endl;
        std::cout << "  DFS Result: " << resultDFS << std::endl;
        std::cout << "  Union-Find Result: " << resultUF << std::endl;
    }
}

int main() {
    // 测试用例1：基础场景（2个省份）
    std::vector<std::vector<int>> case1 = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    runTest("Basic case (2 provinces)", case1, 2);

    // 测试用例2：所有城市相连（1个省份）
    std::vector<std::vector<int>> case2 = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };
    runTest("All cities connected (1 province)", case2, 1);

    // 测试用例3：所有城市独立（3个省份）
    std::vector<std::vector<int>> case3 = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    runTest("All cities isolated (3 provinces)", case3, 3);

    // 测试用例4：边界场景（单个城市）
    std::vector<std::vector<int>> case4 = {{1}};
    runTest("Single city (1 province)", case4, 1);

    // 测试用例5：空矩阵（0个省份）
    std::vector<std::vector<int>> case5 = {};
    runTest("Empty matrix (0 province)", case5, 0);

    // 测试用例6：间接相连场景（1个省份）
    std::vector<std::vector<int>> case6 = {
        {1,0,1},
        {0,1,0},
        {1,0,1}
    };
    runTest("Indirect connection (1 province)", case6, 2);

    return 0;
}