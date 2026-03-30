class Solution {
public:
    vector<vector<int>>ans;
    void f(vector<int>&a,vector<int>temp,int target,int ind){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(ind>=a.size()|| target<0)return;
        temp.push_back(a[ind]);
        f(a,temp,target-a[ind],ind+1);
        temp.pop_back();
        int next=ind+1;
        while(next<=a.size() && a[next]==a[ind])next++;
        f(a,temp,target,next);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        f(candidates,{},target,0);
        return ans;

        
    }
};
