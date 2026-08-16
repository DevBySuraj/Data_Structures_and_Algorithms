class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int start1,start2,end1,end2;
        vector<vector<int>> output;

        for(int i =0; i<firstList.size(); i++){
            for(int j = 0; j<secondList.size(); j++){
                if(firstList[i][0] < secondList[j][0]){
                    start1 = firstList[i][0];
                    end1 = firstList[i][1];
                    start2 = secondList[j][0];
                    end2 = secondList[j][1];
                }
                else{
                    start1 = secondList[j][0];
                    end1 = secondList[j][1];
                    start2 = firstList[i][0];
                    end2 = firstList[i][1];

                }

                if(end1 >= start2){
                    int start = max(start1, start2);
                    int end = min(end1, end2);
                    output.push_back({start,end});
                }
            }
        }
        return output;
    }
};