class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        vector<int> output(size, -1);
        for(int i =0; i<size; i++){
            int count = 0;
            int element = nums[i];

            for(int step = 1; step<size; step++){
                int j = (i+step) % size;

                if(nums[j] > element){
                    output[i] = nums[j];
                    break;
                }

            }
        }
        return output;
    }
};