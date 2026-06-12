class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        int i = 0;
        int j = 0;
        unordered_set<int> s;
        while(j<size){
            int absolute = abs(i-j);
            // else s.insert(nums[j]);
            // absolute > k resolved here by shrinking from left
            while(absolute > k && i<size){
                s.erase(nums[i]);
                i++;
                absolute = abs(i-j);
            }

            if(s.count(nums[j]))
            {
                return true;
            }

            s.insert(nums[j]);               

            //absolute < k and absolute = k resolved here
            // if(s.count(nums[j])) return true;
            j++;
            

        }
        return false;
    }
};