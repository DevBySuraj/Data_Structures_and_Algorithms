class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete = arr[0];
        // int onedelete = arr[0]; // has no exactly one deleted element
        int onedelete = INT_MIN; //will change later
        int res = arr[0];

        for(int i =1; i<arr.size(); i++){
            //save the previous answers of i index before moving to i+1;
            int prevnodel = nodelete;
            int preonedel = onedelete;

            //no delete normal kadane best ending for max sum
            nodelete = max(nodelete + arr[i],  arr[i]);
            int v1;
            if(onedelete == INT_MIN){
                v1 = arr[i];
            }
            else{
                v1 = onedelete + arr[i];
            }

            onedelete = max(v1, prevnodel);

            res = max(res, max(onedelete, nodelete));
        }

        return res;
    }
};