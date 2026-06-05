class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // no two pointer
        // sliding window no as -ve no
        //kadane no as no tracking of any ending look like to me or no min.max,product here asked exact equal to k
        // then why prefix sum??
        int size = nums.size();
        int total_sum = 0;
        int running_sum = 0;
        int res = 0;
        for(int x : nums){
            total_sum += x;
        }
        unordered_map<int,int> mp;
        mp[0] = 1;
        int freq = 0;
        for(int i = 0; i<size; i++){
            running_sum += nums[i];
            int ques = running_sum - k;
            int freq = mp[ques];
            res += freq;
            mp[running_sum]++;
        }
        return res;
    }
};