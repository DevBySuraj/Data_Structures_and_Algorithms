class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        mp[0] = 1;  
        int current_sum = 0;
        int remain = 0;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            current_sum +=nums[i];
            remain = current_sum - k;
            count+= mp[remain];
            mp[current_sum]++;
        }
        return count;
    }
};