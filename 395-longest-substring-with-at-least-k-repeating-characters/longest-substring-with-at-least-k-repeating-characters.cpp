class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;

        // Try every possible number of unique characters
        for (int targetUnique = 1; targetUnique <= 26; targetUnique++) {

            int freq[26] = {0};

            int left = 0;
            int uniqueChars = 0;
            int charsAtLeastK = 0;

            for (int right = 0; right < s.length(); right++) {

                int idx = s[right] - 'a';

                // New character enters the window
                if (freq[idx] == 0)
                    uniqueChars++;

                freq[idx]++;

                // This character has just reached k
                if (freq[idx] == k)
                    charsAtLeastK++;

                // Too many unique characters
                while (uniqueChars > targetUnique) {

                    int leftIdx = s[left] - 'a';

                    // This character was satisfying >= k
                    // and after removal it becomes < k
                    if (freq[leftIdx] == k)
                        charsAtLeastK--;

                    freq[leftIdx]--;

                    // Character completely removed
                    if (freq[leftIdx] == 0)
                        uniqueChars--;

                    left++;
                }

                // Every unique character has frequency >= k
                if (uniqueChars == charsAtLeastK)
                    ans = max(ans, right - left + 1);
            }
        }

        return ans;
    }
};