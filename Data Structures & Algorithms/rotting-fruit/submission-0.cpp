class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int t=q.front().second;
            ans=max(ans,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i];int ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1 && vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    q.push({{nx,ny},t+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0)return -1;
            }
        }
        return ans;
        
    }
};
