class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low = 0, high = 0;
        int size = nums.size();
        double sum = 0;
        double avg = 0;
        double ans = INT_MIN;
        while(high < size){
            sum += nums[high];
            int wind_size = high - low + 1;

            while(wind_size > k){
                sum -= nums[low];
                low++;
                wind_size = high - low + 1;
            }

            if(wind_size == k){
                avg = sum/k;
                ans = max(ans, avg);
            }
            high++;
        }
        return ans;
    }
};