class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i =0; i<nums.size(); i++){
            int n = nums[i];
            int sod = 0;
            while(n > 0){
                int last_digit = n%10;
                sod += last_digit;
                n = n/10;
            }
            if(sod == i) return i;
        }
        return -1;
    }
};