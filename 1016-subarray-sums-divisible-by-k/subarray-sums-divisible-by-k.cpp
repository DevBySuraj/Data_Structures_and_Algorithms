class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int size = nums.size();

        unordered_map<int,int> mp;
        mp[0] = 1;
        int prefix = 0;
        int count = 0;
        for(int i =0; i<size; i++){
            prefix += nums[i];
            int remainder = prefix%k;
            if(remainder < 0){
                remainder = k + remainder;
            }
            count += mp[remainder];
            cout<<count<<endl;
            mp[remainder]++;
        }
        return count;
    }
};