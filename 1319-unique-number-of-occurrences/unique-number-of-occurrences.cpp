class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mp_ans;
        for(int x : arr){
            mp[x]++;
        }
        for(auto it : mp){
            mp_ans[it.second]++;
        }

        if(mp.size() == mp_ans.size()) return true;
        return false;
    }
};