class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>output;
        int current_start = intervals[0][0];
        int current_end = intervals[0][1];
        int next_start = 0;
        int next_end = 0;
        int size = intervals.size();

        if(size == 1) return intervals;

        for(int i = 1; i<size; i++){
            next_start = intervals[i][0];
            next_end = intervals[i][1];
            if(current_end >= next_start){ // they overlap
                // current_end = next_end;
                current_end = max(current_end, next_end);
                if(i == size -1)
                output.push_back({current_start, current_end}); //pushes the current interval and
            }
            else{
                output.push_back({current_start, current_end}); //pushes the current interval and
                // moves to next interval
                current_start = intervals[i][0];
                current_end = intervals[i][1];

                if(i == size - 1)
                output.push_back({current_start, current_end}); //pushes the current interval
            }
        }
        return output;
    }
};