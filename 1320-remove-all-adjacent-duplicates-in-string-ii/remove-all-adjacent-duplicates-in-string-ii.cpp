class Solution {
public:
    string removeDuplicates(string s, int k) {
        int len = s.length();

        stack<pair<char,int>> st;
        string ans = "";
        for(int i =0; i<len; i++){
            if(st.empty()){
                st.push({s[i], 1});
                continue;
            }

            if(s[i] == st.top().first){
                int occ = st.top().second;
                st.pop();
                st.push({s[i], occ + 1});
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