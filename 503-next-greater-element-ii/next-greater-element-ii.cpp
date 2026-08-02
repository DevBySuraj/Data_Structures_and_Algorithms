class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> stack_output(n); // output for the nums 2
        for(int i = 2*(n) - 1;  i>=0; i--){
            while(!s.empty()  && nums[i%n] >= s.top()){
                s.pop();
            }

            if(i<n){
            stack_output[i] =  s.empty() ? -1 : s.top();
            }
            s.push(nums[i%n]);

        }

        return stack_output;
    }
};