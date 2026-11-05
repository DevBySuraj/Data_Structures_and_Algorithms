class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int output = 0;
        bool value = true;
        for(int i =0; i<arr1.size(); i++){

            int first = arr1[i];
            for(int j = 0; j < arr2.size(); j++){

                int diff = abs(first - arr2[j]);
                if(diff <= d){
                    value = false;
                    break;
            }
        }
            if(value == true){
                output++;
            }
            value = true;

    }
    return output;
    }
};