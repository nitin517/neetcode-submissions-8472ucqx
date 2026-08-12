class Solution {
public:

    class DSU {
    public:

        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            rank.resize(n, 0);
            parent.resize(n);

            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if(parent[u] == u)
                return u;

            return parent[u] = find(parent[u]);
        }

        void unite(int u, int v) {

            int pu = find(u);
            int pv = find(v);

            if(pu == pv)
                return;

            if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            }
            else if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            }
            else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        DSU d(n + 1);

        for(auto it : edges) {

            int u = it[0];
            int v = it[1];

            if(d.find(u) == d.find(v)) {
                return {u, v};
            }

            d.unite(u, v);
        }

        return {};
    }
};