#include "ProvinceCounter.h"

// ------------------- DFS实现 -------------------
int ProvinceCounter::countByDFS(std::vector<std::vector<int>>& isConnected) {
    int n = isConnected.size();
    if (n == 0) return 0; // 边界：空矩阵直接返回0
    
    std::vector<bool> visited(n, false);
    int provinceCount = 0;

    // 遍历所有城市，寻找未访问的连通分量（新省份）
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            provinceCount++;
            dfs(isConnected, visited, i, n); // 遍历该省份的所有关联城市
        }
    }

    return provinceCount;
}

void ProvinceCounter::dfs(std::vector<std::vector<int>>& isConnected, std::vector<bool>& visited, int city, int n) {
    visited[city] = true; // 标记当前城市为已访问

    // 遍历所有城市，找到与当前城市直接相连且未访问的城市
    for (int j = 0; j < n; ++j) {
        if (!visited[j] && isConnected[city][j] == 1) {
            dfs(isConnected, visited, j, n); // 递归遍历关联城市
        }
    }
}

// ------------------- 并查集实现 -------------------
int ProvinceCounter::countByUnionFind(std::vector<std::vector<int>>& isConnected) {
    int n = isConnected.size();
    if (n == 0) return 0; // 边界：空矩阵直接返回0
    
    std::vector<int> parent(n);
    // 初始化并查集：每个城市的父节点为自身
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }

    // 遍历邻接矩阵，合并相连的城市（j从i+1开始避免重复处理）
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isConnected[i][j] == 1) {
                unionSet(parent, i, j);
            }
        }
    }

    // 统计根节点数量（根节点=自身的节点数即为省份数）
    int provinceCount = 0;
    for (int i = 0; i < n; ++i) {
        if (parent[i] == i) {
            provinceCount++;
        }
    }

    return provinceCount;
}

int ProvinceCounter::find(std::vector<int>& parent, int x) {
    // 路径压缩：让节点直接指向根节点，优化后续查找效率
    if (parent[x] != x) {
        parent[x] = find(parent, parent[x]);
    }
    return parent[x];
}

void ProvinceCounter::unionSet(std::vector<int>& parent, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    // 不同根节点则合并（将y的根节点指向x的根节点）
    if (rootX != rootY) {
        parent[rootY] = rootX;
    }
}