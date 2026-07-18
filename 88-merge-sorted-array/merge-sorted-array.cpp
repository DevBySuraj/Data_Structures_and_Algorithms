class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i =0;
        int j = 0;
        vector<int> output;
        while(j<n && i<m){

            if(nums1[i] <= nums2[j]){
                output.push_back(nums1[i]);
                i++;
            }
            else{
                output.push_back(nums2[j]);
                j++;
            }
        }
        while(j<n){
            output.push_back(nums2[j]);
            j++;
        }
        while(i<m){
            output.push_back(nums1[i]);
            i++;
        }

        for(int i =0; i<m+n; i++){
            nums1[i] = output[i];
        }
    }
};