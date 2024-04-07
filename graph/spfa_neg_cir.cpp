#include <bits/stdc++.h>

typedef long long i64;

const int INF = 0x3f3f3f3f;

int n, m;

bool spfa_better() {
    using edge = std::pair<int ,int>;
    std::cin >> n >> m;
    std::vector<std::vector<edge>> G(n);
    while(m --) {
        int a, b, z;
        std::cin >> a >> b >> z;
        G[a - 1].emplace_back(b - 1, z);
    } 
    // 建图

    std::vector<int> dist(n, 0);
    std::vector<int> pre(n, -1);
    std::vector<bool> inQueue(n, true);
    std::queue<int> queue;
    for (int i = 0; i < n; i++) {
        queue.emplace(i);
    }

    int idx = 0; // 计数器

    auto detectCycle = [&]() {
        std::vector<int> vec;
        std::vector<bool> inStack(n, false);
        std::vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                for (int j = i; j != -1; j = pre[j]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        vec.push_back(j);
                        inStack[j] = true;
                    } else {
                        if (inStack[j]) return true;
                        break;
                    }
                }
                for (int j : vec) inStack[j] = false;
                vec.clear();
            }
        }
        return false;
    };

    while(!queue.empty()) {
        int u = queue.front();
        queue.pop();
        inQueue[u] = false;
        for (auto [v, w] : G[u]) {
            if (dist[u] + w < dist[v]) {
                pre[v] = u;
                dist[v] = dist[u] + w;
                if (++idx == n) {
                    idx = 0;
                    if (detectCycle()) return true;
                }
                if (!inQueue[v]) {
                    queue.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }

    if (detectCycle()) return true;
    return false;
}

int main() {    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    if (spfa_better()) std::cout << "Yes" <<std::endl;
    else std::cout << "No" << std::endl;
    return 0;
}

