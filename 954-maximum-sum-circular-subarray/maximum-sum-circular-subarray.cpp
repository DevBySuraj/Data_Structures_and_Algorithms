class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_end = nums[0];
        int max_res = nums[0];
        int min_res = nums[0];
        int n = nums.size();
        int min_end = nums[0];
        int sum = nums[0];

        int res = nums[0];

        for(int i = 1; i<n; i++){
            sum += nums[i]; 
            max_end = max(max_end + nums[i], nums[i]);
            max_res = max(max_res, max_end);

            min_end = min(min_end + nums[i], nums[i]);
            min_res = min(min_res, min_end);
            // cout<<max_res<<endl;
        }
        int v1 = sum - min_res;
        res = max(max_res, v1);

        if(v1 == 0 ) return max_res;
        return res;
    }
};