class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int res = 0;

        mp[0] = 1; // for sum = 0 it appear one time as for empty subarray
                // in case if whole subarray upto sum is k, so sum - k = 0

        for(int i =0; i<size; i++){
            //running sum or sum at index i 
            sum += nums[i];
            int remain = sum - k;

            //ask from hash map have it(how many times) seen remain in any of the previous sum frequeciues stored
            res += mp[remain];
            mp[sum]++; //stores the current sum till i will be used as sum - k for other indexes 
        }
        return res;
    }
};