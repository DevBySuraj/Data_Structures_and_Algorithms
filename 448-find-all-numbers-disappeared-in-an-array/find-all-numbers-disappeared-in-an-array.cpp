class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0; i<n; i++){
            int idx = abs(nums[i]) - 1;
            //index for each value, where should it go

            if(nums[idx] > 0)// if the value on the other index is +ve then only negative it, if not then it already negated, it will double negate and make it positive
                nums[idx] *= -1 ;
        }

        for(int i =0; i<n; i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans;

    }
};