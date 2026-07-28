class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int size = intervals.size();
        int current_start = intervals[0][0];
        int current_end = intervals[0][1];
        int next_start = 0;
        int next_end = 0;


        if(size == 1) return intervals;

        vector<vector<int>> output;

        for(int i = 1; i<size; i++){
            next_start = intervals[i][0];
            next_end = intervals[i][1];
            if(current_end >= next_start){ //overlaps here condition
                current_end = max(current_end, next_end);
                // if the whole array overlaps we will end here
                if(i == size - 1){
                    output.push_back({current_start, current_end});
                }
            }

            else{ // if the current intervals breaks we will push current merged intervals 
            //and move to next intervals 
                output.push_back({current_start, current_end});

                current_start = intervals[i][0];
                current_end = intervals[i][1];

                if(i == size - 1)
                output.push_back({current_start, current_end});
            }
            }
        return output;
    }
};