class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        int max_ans = INT_MIN;
        for(int x : arr){
            mp[x]++;
        }

        for(int i =0; i<arr.size(); i++){
            if(arr[i] == mp[arr[i]]){
                max_ans = max(max_ans, arr[i]);
            }
        }

        if(max_ans == INT_MIN) return -1;
        return max_ans;
    }   
};