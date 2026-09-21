class Solution {
public:

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        multiset<long long> small;
        multiset<long long> large;

        // Add an element
        auto add = [&](long long x) {

            if (small.empty() || x <= *small.rbegin()) {
                small.insert(x);
            }
            else {
                large.insert(x);
            }

            // Balance
            if (small.size() > large.size() + 1) {
                auto it = prev(small.end());
                large.insert(*it);
                small.erase(it);
            }
            else if (small.size() < large.size()) {
                auto it = large.begin();
                small.insert(*it);
                large.erase(it);
            }
        };

        // Remove an element
        auto remove = [&](long long x) {

            auto it = small.find(x);

            if (it != small.end()) {
                small.erase(it);
            }
            else {
                it = large.find(x);
                large.erase(it);
            }

            // Balance
            if (small.size() > large.size() + 1) {
                auto temp = prev(small.end());
                large.insert(*temp);
                small.erase(temp);
            }
            else if (small.size() < large.size()) {
                auto temp = large.begin();
                small.insert(*temp);
                large.erase(temp);
            }
        };

        // First window
        for (int i = 0; i < k; i++) {
            add(nums[i]);
        }

        // First median
        if (k % 2 == 1) {
            ans.push_back(*small.rbegin());
        }
        else {
            ans.push_back(
                (*small.rbegin() + *large.begin()) / 2.0
            );
        }

        // Sliding window
        for (int right = k; right < nums.size(); right++) {

            // Remove outgoing
            remove(nums[right - k]);

            // Add incoming
            add(nums[right]);

            // Median
            if (k % 2 == 1) {
                ans.push_back(*small.rbegin());
            }
            else {
                ans.push_back(
                    (*small.rbegin() + *large.begin()) / 2.0
                );
            }
        }

        return ans;
    }
};