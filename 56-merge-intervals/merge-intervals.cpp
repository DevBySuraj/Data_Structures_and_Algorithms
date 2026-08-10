class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int size = intervals.size();
        if(size == 1){
            return intervals;
        }

        vector<vector<int>> output;

        int current_start = intervals[0][0];
        int current_end = intervals[0][1];

        for(int i = 1; i<size; i++){
            int next_start = intervals[i][0];
            int next_end = intervals[i][1];

            if(current_end >= next_start){
                current_end = max(current_end, next_end); // two cases
            }

            else{
                output.push_back({current_start, current_end});

                current_start = intervals[i][0];
                current_end = intervals[i][1];
            }
        }
        output.push_back({current_start, current_end});

    return output;
    }
};