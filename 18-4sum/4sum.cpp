class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        int size = nums.size();
        for(int i = 0; i<size-3; i++){

            if(i>0 && nums[i] == nums[i-1]) continue;

            int first = nums[i];

            for(int j = i+1; j<size-2; j++){
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int second = nums[j];
                
                int m = j+1;
                int n = size - 1;

                while(m<n){
                    int sum = nums[m] + nums[n];
                    long long total_sum = 1LL * first + second + sum;

                    if(total_sum == target){
                        output.push_back({first,second, nums[m], nums[n]});
                        m++;
                        n--;

                        while(m<size && nums[m] == nums[m-1]){
                            m++;
                        }
                        while(n>= 0  && nums[n] == nums[n+1]){
                            n--;
                        }

                    }

                    else if(total_sum > target) n--;
                    else m++;
                }
            }
        }

        return output;
    }
};