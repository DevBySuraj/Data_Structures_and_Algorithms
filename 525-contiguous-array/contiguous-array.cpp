class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> f;
        int ones = 0, zeros = 0;
        int res = 0, diff = 0;

        for(int i=0; i<size; i++){
            if(nums[i] == 0) zeros++;
            else ones++;

            diff = zeros - ones;
            
            // if diff =0 the while array from 0 index is correct
            if(diff == 0){
                res = max(res, i+1);
                continue;
            }


            // if the diff is in the map then get f[diff] and calculate i-index the res only
            // if find not used, then the diff value will be changed from first occurence to latest occurence
            if(f.find(diff) != f.end()){
                int index = f[diff];
                res = max(res, i-index);
            }
            else{
                // one time first diff occurence index insertion in the map
                // will not be updated the next time
                f[diff] = i;
            }
        }
        return res;
    }
};