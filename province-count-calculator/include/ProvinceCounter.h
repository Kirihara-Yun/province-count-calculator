#ifndef PROVINCE_COUNTER_H
#define PROVINCE_COUNTER_H

#include <vector>

/**
 * @brief 省份数量统计工具类
 * @details 实现两种经典算法（DFS、并查集）统计无向图的连通分量个数，
 *          对应“省份数量”问题：由直接/间接相连的城市构成省份，统计总数
 */
class ProvinceCounter {
public:
    /**
     * @brief 基于深度优先遍历（DFS）的省份数量统计
     * @param isConnected n×n的邻接矩阵，isConnected[i][j]=1表示城市i和j直接相连
     * @return int 省份总数
     */
    int countByDFS(std::vector<std::vector<int>>& isConnected);

    /**
     * @brief 基于并查集（Union-Find）的省份数量统计
     * @param isConnected n×n的邻接矩阵，isConnected[i][j]=1表示城市i和j直接相连
     * @return int 省份总数
     */
    int countByUnionFind(std::vector<std::vector<int>>& isConnected);

private:
    /**
     * @brief DFS递归辅助函数：遍历单个连通分量的所有节点
     * @param isConnected 邻接矩阵
     * @param visited 访问状态标记数组
     * @param city 当前遍历的城市下标
     * @param n 城市总数
     */
    void dfs(std::vector<std::vector<int>>& isConnected, std::vector<bool>& visited, int city, int n);

    /**
     * @brief 并查集查找函数（带路径压缩）
     * @param parent 父节点数组
     * @param x 待查找的节点
     * @return int 节点x的根节点
     */
    int find(std::vector<int>& parent, int x);

    /**
     * @brief 并查集合并函数
     * @param parent 父节点数组
     * @param x 待合并的节点1
     * @param y 待合并的节点2
     */
    void unionSet(std::vector<int>& parent, int x, int y);
};

#endif // PROVINCE_COUNTER_H