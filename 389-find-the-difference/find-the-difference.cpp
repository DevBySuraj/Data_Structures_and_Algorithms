class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp_s;
        unordered_map<char,int> mp_t;

        for(char x : s){
            mp_s[x]++;
        }
        for(char x : t){
            mp_t[x]++;
        }

        for(char x : t){
            if(mp_t[x] > mp_s[x]) return x;
        }

        return 'x';
    }
};