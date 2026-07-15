class Solution {
public:
    void sortColors(vector<int>& arr) {
                int size = arr.size();
        
        int i =0, j =0;
        while(j<size){
            if(arr[j] == 0){
                swap(arr[j], arr[i]);
                i++;
                j++;
            }
            
            else j++;
            
        }
        
        j=i;
        
        while(j<size){
            if(arr[j] == 1){
                swap(arr[j], arr[i]);
                i++;
                j++;
            }
        
            else j++;
    }
    }
};