class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> output;

        for(int i = 0;  i< size - 2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int target = -(nums[i]);
            int x = i+1;
            int y = size - 1;

            while(x < y){
                int sum = nums[x] + nums[y];
                if(sum < target){
                    x++;
                }

                else if(sum > target){
                    y--;
                }
                else {

                    output.push_back({nums[i], nums[x], nums[y]});
                    x++;
                    y--;

                    while(x<size && nums[x] == nums[x-1]) x++;

                    while(y>=0 && nums[y] == nums[y+1]) y--;
                }
            }
        }
        return output;
    }

};