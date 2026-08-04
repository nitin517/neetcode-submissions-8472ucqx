class Solution {
public:
    int a[4]={1,-1,0,0};
    int b[4]={0,0,1,-1};
    int ans=0;
    void dfs(int x,int y,int n,int m,
         vector<vector<int>>& grid,
         vector<vector<int>>& vis){

    vis[x][y]=1;

    for(int i=0;i<4;i++){

        int nx=x+a[i];
        int ny=y+b[i];

        if(nx<0 || ny<0 || nx>=n || ny>=m){
            ans++;
        }

        else if(grid[nx][ny]==0){
            ans++;
        }

        else if(!vis[nx][ny]){
            dfs(nx,ny,n,m,grid,vis);
        }
    }


    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        return ans;



        
    }
};