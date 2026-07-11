class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int curr_sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0;
        for(int i = 0; i<size; i++){
            curr_sum += nums[i];

            int remain = curr_sum - k;
            ans += mp[remain];
            mp[curr_sum]++;
        }
        return ans;
    }
};