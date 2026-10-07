class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int move = 0;
        int min_move = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){ 
                st.push(s[i]);
                continue;
            }
            

            if(!st.empty() && s[i] == ')') st.pop();
            else move++;

        }
        min_move = st.size() + move;
        return min_move;
    }
};