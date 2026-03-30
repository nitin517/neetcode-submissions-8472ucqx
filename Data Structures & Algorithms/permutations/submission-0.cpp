class Solution {
public:
    vector<vector<int>>ans;
    void f(vector<int>&nums,vector<int>temp,map<int,int>mp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end())continue;
            mp[nums[i]]++;
            temp.push_back(nums[i]);
            f(nums,temp,mp);
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        map<int,int>mp;
        f(nums,{},mp);
        return  ans;
    }
};
