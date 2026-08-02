class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> stack_output(nums2.size()); // output for the nums 2
        vector<int>output(nums1.size());
        for(int i = nums2.size() - 1;  i>=0; i--){
            while(!s.empty()  && nums2[i] > s.top()){
                s.pop();
            }

            stack_output[i] =  s.empty() ? -1 : s.top();
            s.push(nums2[i]);

        }

        unordered_map<int, int> mp;

        for(int j = nums2.size() - 1; j>=0; j--){
            mp[nums2[j]] = stack_output[j];
        }

        for(int k = 0; k<nums1.size(); k++){
            if(mp.find(nums1[k]) != mp.end()){
                output[k] = mp[nums1[k]];
            }
        }

        return output;
    }
};