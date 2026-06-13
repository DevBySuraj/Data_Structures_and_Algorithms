class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int j =0;
        int i =0;
        for(i =0; i<n; i++){
            j=0;
            if(arr[i] == 0){
                for(j = n-1; j>i+1; j--){
                    arr[j] = arr[j-1];
                }
                arr[j] = 0;
                i++;
            }
        }
    }
};