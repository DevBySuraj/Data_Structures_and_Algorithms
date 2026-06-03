#include<stack>
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int record = 0;
        vector<int> records;
        int sum = 0;

        for(int i = 0; i<operations.size(); i++){
            if(operations[i] == "+")
            {
                int t = st.top();
                st.pop();
                int sum = st.top() + t;
                st.push(t);
                st.push(sum);

            }

            else if(operations[i] == "D"){
                st.push(2*(st.top()));
            }

            else if(operations[i] == "C"){
                st.pop();
            }

            else{
                st.push(stoi(operations[i]));
            }
        }

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};