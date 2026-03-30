class Solution {
public:
    int ans=0;
    void f(vector<int>&nums,int temp,int ind){
        if(ind>=nums.size()){
            ans+=temp;
            return;
        }
        temp=temp^ nums[ind];
        f(nums,temp,ind+1);
        temp=temp^nums[ind];
        f(nums,temp,ind+1);
    }
    int subsetXORSum(vector<int>& nums) {
        f(nums,0,0);
        return ans;
        
    }
};