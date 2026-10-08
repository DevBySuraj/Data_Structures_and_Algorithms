class Solution {
public:
    string removeDuplicates(string s, int k) {
        int size = s.size();
        stack<pair<char, int>> st;
        string ans = "";
        for(int i = 0; i<size; i++){
            // if(st.empty()){
            //     st.push(s[i], 1);
            // }

            if(!st.empty() && s[i] == st.top().first){
                st.top().second++;
            }
            else{
                st.push({s[i], 1});
            }
            if(st.top().second == k) st.pop();
        }

        while(!st.empty()){
            ans.append(st.top().second, st.top().first);
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;

    }
};