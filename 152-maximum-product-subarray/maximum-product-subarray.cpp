class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int min_end = nums[0];
        int max_end = nums[0];
        int ans = nums[0];


        for(int i =1; i<size; i++){
            int v1 = max_end * nums[i];
            int v2 = min_end * nums[i];
            int v3 = nums[i];
            max_end = max(v1, max(v2, v3));
            min_end = min(v1, min(v2,v3));
            ans = max(ans, max(min_end, max_end));
        }
        return ans;
    }
};