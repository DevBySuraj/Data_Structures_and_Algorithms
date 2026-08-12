class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> output;
        for(int x : nums){
            mp[x]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto &[val, freq] : mp){
            pq.push({freq,val});
        }

        for(int j = 0; j<k; j++){
            auto [f, v] = pq.top();
            output.push_back(v);
            pq.pop();
        }

        return output;


    }
};