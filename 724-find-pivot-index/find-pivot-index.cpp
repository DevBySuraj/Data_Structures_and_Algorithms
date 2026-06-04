class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();

        int prefix = 0;
        int suffix = 0;
        int total_sum = 0;
        for(auto x : nums){
            total_sum += x;
        }
        for(int i = 0; i<size; i++){
            if(i == 0){
                prefix = 0;
                suffix = total_sum - prefix - nums[i];
                if(prefix == suffix) return i;
                continue;
            }

            prefix = prefix + nums[i-1];
            suffix = total_sum - prefix - nums[i];

            if(prefix == suffix) return i;
        }
        return -1;
    }
};