class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.length();

        map<char, int> mp;
        char character;
        for(auto x : s){
            mp[x]++;
        }

        for(int i =0; i<size; i++){
            if(mp[s[i]] == 1) return i;
        }
        return -1;
    }
};