class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_end = nums[0];
        int min_res = nums[0];
        int total_sum = nums[0];

        int max_end = nums[0];
        int max_res = nums[0];

        int ans = INT_MIN;


        for(int i = 1; i<nums.size(); i++){
            total_sum += nums[i];

            max_end = max(max_end + nums[i], nums[i]);
            max_res = max(max_res, max_end);

            min_end = min(min_end + nums[i], nums[i]);
            min_res = min(min_res, min_end);
        }
        if(min_res == total_sum) return max_res;
        return max(max_res, total_sum - min_res);

    }
};