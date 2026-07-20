class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        long long mid = 0;
        int ans = 0;
        int h = x/2;
        if(x == 1 || x==0) return x;
        while(l<=h){
            mid = (l+h)/2;
            if(mid * mid == x){
                return mid;
            }

            else if((mid * mid) < x){
                l = mid + 1;
                ans = mid;
            }
            else{
                h = mid - 1;
            }
        }
        return ans;
    }
};