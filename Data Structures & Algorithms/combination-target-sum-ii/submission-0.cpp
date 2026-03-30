class Solution {
public:
    set<vector<int>>ans;
    void f(vector<int>&a,vector<int>temp,int target,int ind){
        if(target==0){
            ans.insert(temp);
            return;
        }
        if(ind>=a.size()|| target<0)return;
        temp.push_back(a[ind]);
        f(a,temp,target-a[ind],ind+1);
        temp.pop_back();
        f(a,temp,target,ind+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        f(candidates,{},target,0);
        vector<vector<int>>ans1;
        for(auto it:ans){
            ans1.push_back(it);
        }
        return ans1;

        
    }
};
