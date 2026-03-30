class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            int tar=nums[i]-k;
            if(tar==0)ans++;
            if(mp.find(tar)!=mp.end()){
                ans+=mp[tar];
            }
            mp[nums[i]]++;

        }
        return ans;
        
    }
};