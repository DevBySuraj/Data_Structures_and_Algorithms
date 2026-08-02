class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> output(nums1.size(), -1);
        for(int i =0; i<nums1.size(); i++){
            int element1 = nums1[i];

            for(int j = 0; j<nums2.size(); j++){
                if(element1 == nums2[j]){

                    for(int k = j+1; k<nums2.size(); k++){
                        if(element1 < nums2[k]){
                        output[i] = nums2[k];
                        break;
                        }
                    }
                    break; // breaks j loop
                }
            }
        }
        return output;
    }
};