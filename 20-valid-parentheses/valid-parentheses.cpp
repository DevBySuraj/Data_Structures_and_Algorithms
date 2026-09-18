class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length() == 1) return false;
        if(s[0] == ')' || s[0] == ']' || s[0] =='}' ) return false;

        for(int i =0; i<s.length(); i++){
            if(s[i] == '(' || s[i] ==  '{' || s[i] ==  '[') {
                st.push(s[i]);
                continue;
            }

            if(!st.empty() && s[i] == ')' && st.top() == '(')
                st.pop();
            else if(!st.empty() && s[i] == ']' && st.top() == '[')
                st.pop();
            else if(!st.empty() && s[i] == '}' && st.top() == '{')
                st.pop();  
            else return false;  
        }
        return st.empty();
    }
};