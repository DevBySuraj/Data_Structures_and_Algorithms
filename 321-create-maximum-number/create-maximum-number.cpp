class Solution {
public:

    vector<int> maxSubsequence(vector<int>& nums, int k) {

        vector<int> st;
        int drop = nums.size() - k;

        for (int num : nums) {

            while (!st.empty() && drop > 0 && st.back() < num) {
                st.pop_back();
                drop--;
            }

            st.push_back(num);
        }

        st.resize(k);

        return st;
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {

        vector<int> ans;

        int i = 0;
        int j = 0;

        while (i < a.size() || j < b.size()) {

            if (lexicographical_compare(a.begin()+i, a.end(),
                                        b.begin()+j, b.end())) {

                ans.push_back(b[j++]);
            }
            else {
                ans.push_back(a[i++]);
            }
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<int> answer;

        int start = max(0, k - (int)nums2.size());
        int end = min(k, (int)nums1.size());

        for (int take1 = start; take1 <= end; take1++) {

            int take2 = k - take1;

            vector<int> part1 = maxSubsequence(nums1, take1);
            vector<int> part2 = maxSubsequence(nums2, take2);

            vector<int> candidate = merge(part1, part2);

            if (candidate > answer)
                answer = candidate;
        }

        return answer;
    }
};