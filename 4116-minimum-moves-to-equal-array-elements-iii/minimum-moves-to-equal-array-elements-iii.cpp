class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        int min_moves = 0;

        for(int i =0; i<nums.size(); i++){
            min_moves += (max_val-nums[i]);
        }
        return min_moves;
    }
};