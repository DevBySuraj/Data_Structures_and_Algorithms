class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>first;
        set<int>second;
        vector<int>output;
        for(int x : nums1){
            first.insert(x);
        }

        for(int x : nums2){
            second.insert(x);
        }

        for(int x: first){
            if(second.find(x) != second.end()){
                output.push_back(x);
            }
        }
        return output;
    }
};