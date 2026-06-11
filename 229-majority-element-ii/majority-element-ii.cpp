class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        unordered_map<int,int> mp;

        for(int x : nums){
            mp[x]++;
        }

        for(auto it : mp){
            if(it.second > (n/3)){
                output.push_back(it.first);
            }
        }
        return output;
    }
};