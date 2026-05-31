class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int min_end = nums[0];
        int max_end = nums[0];

        int res = nums[0];

        for(int i = 1; i<nums.size(); i++){
            min_end = min(min_end + nums[i], nums[i]);

            max_end = max(max_end + nums[i], nums[i]);

            res = max(res, max(abs(min_end), max_end));
        }

        return abs(res);
    }
};