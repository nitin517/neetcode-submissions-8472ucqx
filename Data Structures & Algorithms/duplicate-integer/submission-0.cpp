class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end())return true;
            else mp[nums[i]]++;
        }
        return false;
        
    }
};