class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum+= x;

        int prefix = 0;
        int suffix = 0;
        suffix = sum - nums[0];
        if(prefix == suffix) return 0;



        for(int i = 1; i<nums.size(); i++){
            prefix = prefix + nums[i-1];
            suffix = sum - nums[i] - prefix;

            if(suffix == prefix) return i;
        }

        return -1;
    }
};