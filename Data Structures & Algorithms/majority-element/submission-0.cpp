class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int cnt=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0){
                ans=nums[i];
                cnt=0;
            }
            else{
                if(nums[i]==ans){
                    cnt++;
                }
                else cnt--;
            }
        }
        return ans;
        
    }
};