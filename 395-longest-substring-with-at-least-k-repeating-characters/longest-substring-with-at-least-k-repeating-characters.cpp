class Solution {
public:
    int longestSubstring(string s, int k) {

        if(s.length() < k)
            return 0;

        unordered_map<char,int> freq;

        for(char c : s)
            freq[c]++;

        for(auto [ch, count] : freq) {

            if(count < k) {

                int ans = 0;
                string left = "";
                string right = "";

                // split around invalid character
                for(char c : s) {

                    if(c == ch) {
                        ans = max(ans, longestSubstring(left, k));
                        left = "";
                    }
                    else {
                        left += c;
                    }
                }

                ans = max(ans, longestSubstring(left, k));

                return ans;
            }
        }

        return s.length();
    }
};