class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size();
        for(int i =0; i<size; i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }
        unordered_map<int,int> mp;
        mp[0] = -1;
        int prefix = 0;
        int ans = 0;
        int first_occurence = 0;
        int len = 0;
        for(int i =0; i<size; i++){
            prefix += nums[i];
            if(mp.find(prefix) != mp.end()){
            first_occurence = mp[prefix];
            len = i - first_occurence;
            ans = max(ans, len);
            }
            else mp[prefix] = i;
        }
        return ans;
    }
};