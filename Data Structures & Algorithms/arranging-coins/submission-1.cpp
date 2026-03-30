class Solution {
public:
    int arrangeCoins(int n) {
        long long i=0;
        long long j=n;
        while(i<=j){
            long long mid=i+(j-i)/2;
            long long t=mid*(mid+1)/2;
            if(t==n)return mid;
            if(t>n){
                j=mid-1;
            }
            else i=mid+1;
        }
        return j;
        
    }
};