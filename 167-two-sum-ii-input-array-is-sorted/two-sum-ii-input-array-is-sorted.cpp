class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int i = 0;
        int j = size - 1;

        while(j>i){
            int sum = numbers[i] + numbers[j];

            if(sum > target){
                j--;
            }

            else if(sum < target){
                i++;
            }
            else{
                return {i+1, j+1};
            }
        }

        return {};
    }
};