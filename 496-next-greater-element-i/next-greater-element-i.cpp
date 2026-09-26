class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top() <= nums2[i])
                st.pop();
            // two case here
            //    1. stack empty
            //    2. greater element found
            ans[i] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        //use map to store next greater as key and value for nums1
        //select only element of nums1 for ans
        unordered_map<int,int> mp;
        for(int j = 0; j<n; j++){
            mp[nums2[j]] = ans[j];
        }

        //match values
        vector<int>fans(nums1.size());
        for(int k =0; k<nums1.size(); k++){
            fans[k] = mp[nums1[k]];
        }

        return fans;
    }
};