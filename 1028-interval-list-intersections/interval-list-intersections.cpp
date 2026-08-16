class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int start1,start2,end1,end2;
        vector<vector<int>> output;
        bool first = false;
        int i = 0, j =0;
        while(i< firstList.size() &&  j<secondList.size()){
            if(firstList[i][0] < secondList[j][0]){
                start1 = firstList[i][0];
                end1 = firstList[i][1];
                start2 = secondList[j][0];
                end2 = secondList[j][1];
                first = true;
            }
            else{
                start1 = secondList[j][0];
                end1 = secondList[j][1];
                start2 = firstList[i][0];
                end2 = firstList[i][1];
                first = false;
            }

            if(end1 >= start2){
                output.push_back({max(start1, start2), min(end1, end2)});
            }

            if(first == true){
                if(j == secondList.size() - 1) i++;
                else if(end1 < secondList[j+1][0]) i++;
                else j++; // >= case
            }
            else{// first == false
                if(i == firstList.size() - 1) j++;
                else if(end1 < firstList[i+1][0]) j++;
                else i++; // >= case
            }


        }

  
        return output;
    }
};