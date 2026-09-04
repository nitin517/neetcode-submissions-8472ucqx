class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);

        // Build graph
        for(auto p : prerequisites) {
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);
        }

        // reach[u][v] = u is prerequisite of v
        vector<vector<bool>> reach(
            numCourses,
            vector<bool>(numCourses, false)
        );

        // BFS from every node
        for(int u = 0; u < numCourses; u++) {

            queue<int> q;
            vector<bool> vis(numCourses, false);

            q.push(u);
            vis[u] = true;

            while(!q.empty()) {

                int node = q.front();
                q.pop();

                for(int next : adj[node]) {

                    if(!vis[next]) {

                        vis[next] = true;
                        reach[u][next] = true;

                        q.push(next);
                    }
                }
            }
        }

        // Answer queries
        vector<bool> ans;

        for(auto q : queries) {
            ans.push_back(reach[q[0]][q[1]]);
        }

        return ans;
    }
};