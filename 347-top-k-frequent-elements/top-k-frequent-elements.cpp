class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<int> output;
        for(int x : nums){
            freq[x]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto &[element, fr] : freq){
            pq.push({fr, element});
        }

        for(int i = 0; i<k; i++){
            auto [freq, value] = pq.top();
            output.push_back(value);
            pq.pop();
        }

        return output;

    }
};