class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int size = nums.size();
        int sum = nums[0];
        for(int i =1; i<size; i++){
            sum += nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};