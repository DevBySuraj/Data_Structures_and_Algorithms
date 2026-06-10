class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>s;
        for(int x: nums){
            s.insert(x);
        }
        return nums.size() != s.size();
    }
};