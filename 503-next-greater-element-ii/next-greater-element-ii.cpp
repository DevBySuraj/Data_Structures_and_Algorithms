class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        stack<int> st;  
        vector<int> ans(size);

        for(int i = size - 2; i>=0; i--){
            st.push(nums[i]);
        }

        for(int i = size -1; i>=0; i--){
            while(!st.empty() && st.top() <= nums[i]) st.pop();

            ans[i] = st.empty() ? -1 : st.top();

            st.push(nums[i]);
        }
        return ans;
    }
};