class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int best_ending = nums[0];
        int ans = nums[0];

        for(int i = 1; i<size; i++){
            best_ending = max(best_ending + nums[i], nums[i]);
            ans = max(ans, best_ending);
        }
        return ans;
    }
};