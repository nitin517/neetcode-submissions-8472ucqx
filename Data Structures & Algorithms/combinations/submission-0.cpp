class Solution {
public:
    vector<vector<int>>ans;
    void f(int num,vector<int>temp,int n,int k){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        for(int i=num;i<=n;i++){
            temp.push_back(i);
            f(i+1,temp,n,k-1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        f(1,{},n,k);
        return ans;
        
    }
};