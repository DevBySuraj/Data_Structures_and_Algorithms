class Solution {
public:
    int mySqrt(int x) {

        int left = 0;
        int right = x/2;
        long long mid =0;
        int ans = 0;   
        if(x == 0 || x == 1) return x; 
        while(left <= right){
            mid = (left + right)/2;

            if(mid*mid == x) return mid;

            else if(mid*mid < x){
                left = mid + 1;
                ans = mid;
            }
            else 
                right = mid - 1;
        }

        return ans;

    }
};