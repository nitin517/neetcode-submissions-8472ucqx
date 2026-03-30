class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int prefix=1;
        int suffix=1;
        int ans1=INT_MIN;
        int ans2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                prefix=1;
                continue;
            }
            prefix*=nums[i];
            ans1=max(ans1,prefix);
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==0){
                suffix=1;
                continue;
            }
            suffix*=nums[i];
            ans2=max(ans2,suffix);
        }
        return max(ans1,ans2)<0? 0:max(ans1,ans2);

    }
};
