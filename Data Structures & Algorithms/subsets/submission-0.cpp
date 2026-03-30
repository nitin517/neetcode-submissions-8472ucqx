class Solution {
public:
    vector<vector<int>>ans;
    void f(vector<int>&nums,vector<int>temp,int ind){
        if(ind>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        f(nums,temp,ind+1);
        temp.pop_back();
        f(nums,temp,ind+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        f(nums,{},0);
        return ans;
        
    }
};
