class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> output;
        set<int> s;

        for(auto x : nums){
            if(s.find(x) != s.end()){
                output.push_back(x);
            }
            s.insert(x);
        }

        return output;
    }
};