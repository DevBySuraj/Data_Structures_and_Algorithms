class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        int count = 0;
        for(auto x : nums){
            mp[x]++;
        }
        int max_freq = INT_MIN;
        for(auto y : mp){
            max_freq = max(max_freq, y.second);
        }
        int curr_freq = 0;
        for(auto z: mp){
            curr_freq = z.second;
            if(curr_freq == max_freq){
                count += max_freq;
            }
        }
        return count;
}
};