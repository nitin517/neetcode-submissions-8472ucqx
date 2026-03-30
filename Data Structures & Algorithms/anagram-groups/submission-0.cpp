class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>>ans;
        vector<bool>vis(n,0);
        vector<vector<int>>v(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<strs[i].size();j++){
                int ind=strs[i][j]-'a';
                v[i][ind]+=1;
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<string>temp;
                temp.push_back(strs[i]);
                vis[i]=1;
                for(int j=i+1;j<n;j++){
                    bool f=0;
                for(int k=0;k<26;k++){
                    if(v[j][k]!=v[i][k]){
                        f=1;
                        break;
                    }
                }
                if(f==0){
                    temp.push_back(strs[j]);
                    vis[j]=1;
                }

            }
            ans.push_back(temp);

            }
            
        }
        return ans;

        
    }
};
