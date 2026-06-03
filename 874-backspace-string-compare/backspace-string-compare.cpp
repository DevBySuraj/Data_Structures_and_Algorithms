#include<stack>
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> first;
        stack<char>second;
        string l = "";
        string m = "";
        for(auto x : s){
            if(x == '#'){
                if(!first.empty())
                first.pop();
            }
            else{
                first.push(x);
            }
        }

        for(auto x : t){
            if(x == '#'){
                if(!second.empty())
                second.pop();
            }
            else{
                second.push(x);
            }
        }

        while(!first.empty()){
            l.push_back(first.top());
            first.pop();
        }
        while(!second.empty()){
            m.push_back(second.top());
            second.pop();
        }

        // if(l == m){
        //     return true;
        // }
        // return false;

        return l == m;
    }
};