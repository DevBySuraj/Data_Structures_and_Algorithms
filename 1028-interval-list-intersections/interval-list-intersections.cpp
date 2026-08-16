class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int start, end;
        vector<vector<int>> output;
        int i = 0, j =0;
        while(i< firstList.size() &&  j<secondList.size()){
            start = max(firstList[i][0], secondList[j][0]);
            end = min(firstList[i][1], secondList[j][1]);

            if(start <= end) output.push_back({start,end});

            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return output;
    }
};