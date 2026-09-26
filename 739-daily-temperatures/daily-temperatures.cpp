class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size);

        stack<pair<int,int>> st;

        for(int i = size-1; i>=0; i--){
            while(!st.empty() && st.top().first <= temperatures[i])
                st.pop();

            // if(!st.empty()){
            // auto [temp, index] = st.top();
            // value = index - i;
            // }

            ans[i] = st.empty() ? 0 : st.top().second - i ;
            st.push({temperatures[i], i});
        }
        return ans;
    }
};