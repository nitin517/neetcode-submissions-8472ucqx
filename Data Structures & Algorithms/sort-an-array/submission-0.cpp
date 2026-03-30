class Solution {
public:
    vector<int>merge(vector<int>a,vector<int>b){
        int i=0;
        int j=0;
        vector<int>ans;
        int n=a.size();int m=b.size();
        while(i<n && j<m){
            if(a[i]>=b[j]){
                ans.push_back(b[j]);
                j++;
            }
            else{
                ans.push_back(a[i]);
                i++;
            }

        }
            while(i<n){
                ans.push_back(a[i]);
                i++;
            }
            while(j<m){
                ans.push_back(b[j]);
                j++;
            }
        return ans;
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return nums;
        int mid=n/2;
        vector<int>left(nums.begin(),nums.begin()+mid);
        vector<int>right(nums.begin()+mid,nums.end());
        left=sortArray(left);
        right=sortArray(right);
        return merge(left,right);

        
    }
};