class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>output;

        int i =0, j = 0;
        while(i<firstList.size() && j<secondList.size()){
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            // ans pushing
            if(start <= end){
                output.push_back({start,end});
            }

            //pointer movement
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return output;
    }

};