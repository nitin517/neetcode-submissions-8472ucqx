class Solution {
public:
    vector<vector<int>>ans;
    void f(vector<int>&nums,vector<int>temp,int target,int ind){
       if(target==0){
        ans.push_back(temp);
        return;
       }
       if(ind>=nums.size() || target<0)return;
       temp.push_back(nums[ind]);
       f(nums,temp,target-nums[ind],ind);
       temp.pop_back();
       f(nums,temp,target,ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        f(nums,{},target,0);
        return ans;
        
    }
};
