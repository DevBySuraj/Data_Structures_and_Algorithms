class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        priority_queue<pair<int,int>> pq;
        vector<string> output(n);
        for(int i = 0; i<n; i++){
            pq.push({score[i], i});
        }

        for(int i = 0; i<n; i++){
            auto [score, index] = pq.top();

            if(i == 0){
                output[index] = "Gold Medal";
            }
            else if(i == 1){
                output[index] = "Silver Medal";
            }
            else if(i == 2){
                output[index] = "Bronze Medal";
            }
            else{
                output[index] = to_string(i+1);
            }
            pq.pop();
        }

        return output;
    }
};