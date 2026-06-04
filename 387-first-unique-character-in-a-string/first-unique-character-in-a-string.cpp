class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.length();
        vector<int> freq(256,0);

        for(auto x : s){
            freq[x]++;
        }

        for(int i =0; i<size; i++){
            if(freq[s[i]] == 1) return i;
        }
        return -1;
    }
};