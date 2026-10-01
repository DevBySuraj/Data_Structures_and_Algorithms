class Solution {
public:
    int maxDepth(string s) {
        int size = s.length();
        stack<char> st;
        int count = 0;
        int ans = 0;
        for(int i = 0; i<size; i++){
            if(s[i] == '('){
                st.push(s[i]);
                count++;
            }
            if(s[i] == ')' && st.top() == '(' ){
                st.pop();
                count--;
            }
            ans = max(ans, count);
            // cout<<i<<" "<<count<<" "<<ans<<endl;
        }
        return ans;
        
    }
};