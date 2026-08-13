class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int size = intervals.size();
        if(size == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> output;
        vector<vector<int>> ans;
        int current_start;
        int current_end;
        bool insert = false;
        for(int i = 0; i<size; i++){
            current_start = intervals[i][0];
            if(insert == false && current_start >= newInterval[0]){
                insert = true;
                output.push_back(newInterval);
            }
            output.push_back(intervals[i]);
        }

        //if the interval is at the end
        if(insert == false) output.push_back(newInterval);


        current_start = output[0][0];
        current_end =   output[0][1];

        for(int j = 1; j<size + 1; j++){
            int next_start = output[j][0];
            int next_end = output[j][1];

            if(current_end >= next_start){
                current_end = max(current_end, next_end);
            }
            else{
                ans.push_back({current_start, current_end});
                current_start = output[j][0];
                current_end = output[j][1];
            }
        }
        ans.push_back({current_start,current_end});

    return ans;
    }

};