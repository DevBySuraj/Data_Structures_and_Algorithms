class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        int size = nums2.size();
        vector<int> out(nums1.size());
        vector<int> output(nums2.size());
        for(int i = size-1; i>=0; i--){
            while(!s.empty() && nums2[i] > s.top()){
                s.pop();
            }

            output[i] = s.empty() ? -1 : s.top();

            s.push(nums2[i]);
        }

        unordered_map<int,int> mp;
        for(int i = size-1; i>=0; i--){
            mp[nums2[i]] = output[i];
        }

        for(int i =0; i<nums1.size(); i++){
            if(mp.find(nums1[i]) != mp.end()){
                out[i] = mp[nums1[i]];
            }
        }
        return out;
    }
};