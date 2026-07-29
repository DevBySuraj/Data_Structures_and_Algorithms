class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> output;

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        int current_start = intervals[0][0];
        int current_end = intervals[0][1];

        int next_start = 0;
        int next_end = 0;
        
        for(int i =1; i<intervals.size(); i++){
            next_start = intervals[i][0];
            next_end  = intervals[i][1];

            if(current_end >= next_start){ //overlapping
                current_start = current_start;
                current_end = max(current_end, next_end);
                continue;
            }

            output.push_back({current_start, current_end}); // here breaks to so push intervals merged till now

            // start a new intervals here
            current_start = next_start;
            current_end = next_end;

        }

        // if all are merged so push the last answer here
        //if all merged and last remaind unmerged push here
        output.push_back({current_start, current_end});

        return output;
    }
};