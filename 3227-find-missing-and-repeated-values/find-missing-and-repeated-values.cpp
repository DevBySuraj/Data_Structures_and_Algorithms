class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        unordered_map<int, int> mp;
        vector<int> output;
        vector<int> ans(2);
        int last = rows*rows;
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                mp[grid[i][j]]++;
                output.push_back(grid[i][j]);
            }
        }

        for(auto it : mp){
            if(it.second > 1){
                ans[0] = it.first;
                break;
            }
        }
        sort(output.begin(), output.end());
        int i;
        for(i = 1; i<output.size(); i++){
            if(output[i] - output[i-1] > 1){
                ans[1] = output[i] - 1;
                break;
            }
        }
        if(i == output.size()){
            ans[1] = last;
        }

    if(output[0] != 1){
        ans[1] = 1;
    }

        return ans;
    }
};