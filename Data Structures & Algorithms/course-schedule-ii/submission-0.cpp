class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //we can use topological sorting
        int n=numCourses;
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)q.push(i);
        }
        vector<int>ans;
       while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
       }
       if(ans.size()!=n){
        return {};
       }
       else return ans;
        
    }
};
