class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int size = nums.size();
        float avg = 0.0;
        float sum = 0.0;
        int minMoves = 0;
        int search_value = 0;
        sort(nums.begin(), nums.end());

        search_value = nums[(size - 1) /2];

        for(int i =0; i<size; i++){
            minMoves += abs(search_value - nums[i]);
        }

        return minMoves;

    }
};