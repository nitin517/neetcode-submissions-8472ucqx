class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);

            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int node) {
            if(parent[node] == node)
                return node;

            return parent[node] = find(parent[node]);
        }

        void unite(int x, int y) {
            int px = find(x);
            int py = find(y);

            if(px == py)
                return;

            if(rank[px] > rank[py]) {
                parent[py] = px;
            }
            else if(rank[px] < rank[py]) {
                parent[px] = py;
            }
            else {
                parent[px] = py;
                rank[py]++;
            }
        }
    };

    bool validTree(int n, vector<vector<int>>& edges) {

        // A tree with n nodes must have exactly n-1 edges
        if(edges.size() != n - 1)
            return false;

        DSU dsu(n);

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Already connected -> cycle
            if(dsu.find(u) == dsu.find(v))
                return false;

            dsu.unite(u, v);
        }

        return true;
    }
};