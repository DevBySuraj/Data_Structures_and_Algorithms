class Solution {
public:
    string removeOuterParentheses(string s) {
        int size = s.length();
        stack<char> st;

        string ans = "";
        string primitive = "";
        for(int i =0; i<size; i++){
            if(s[i] == '('){
                st.push(s[i]);
                primitive.push_back(s[i]);
                continue;
            }
            if(!st.empty() && s[i] == ')'){ 
                primitive.push_back(s[i]); // not st.top as it coitains ( not )
                st.pop();
            }
            if(st.empty()){
                primitive.erase(0,1);
                primitive.pop_back();
                ans = ans + primitive;
                primitive = "";
            }

        }
        return ans;
    }
};