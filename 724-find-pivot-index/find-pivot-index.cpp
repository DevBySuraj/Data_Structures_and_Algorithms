class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto x : nums){
            sum+= x;
        }
        int prefix = 0;
        int suffix = sum - prefix - nums[0];
        if(suffix == prefix) return 0;
        
        for(int i = 1; i<n; i++){
            prefix = prefix + nums[i-1];
            suffix = sum - prefix - nums[i];

            if(prefix == suffix) return i;
        }

        return -1;
    }
};