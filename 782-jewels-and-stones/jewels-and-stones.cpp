class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;

        unordered_map<char,int> mp;

        for(auto x : stones){
            mp[x]++;
        }

        for(char x : jewels){
            count += mp[x];
        }
        return count;
    }
};