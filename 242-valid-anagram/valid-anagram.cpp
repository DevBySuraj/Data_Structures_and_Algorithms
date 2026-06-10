class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<int,int>mp;
        unordered_map<int,int>mp_ans;
        for(char x : s){
            mp[x]++;
        }
        for(char x : t){
            mp_ans[x]++;
        }

        for(int i = 0; i<t.length(); i++){
            if(mp[t[i]] != mp_ans[t[i]]) return false;
        }

        return true;
    }
};