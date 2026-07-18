class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int,int> mp;

        for(int x : nums){
            mp[x]++;
        }

        for(auto it : mp){
            if(it.second > 1) return it.first;
        }

        return 0;
    }
};