class Solution {
public:
    int longestSubstring(string s, int k) {
        int size = s.length();
        int ans = 0;

        for(int uniqueChar = 1; uniqueChar <= 26; uniqueChar++){
            
            int low = 0;
            int high = 0;
            int actUniqueChar = 0;
            int charAtLeastK = 0;
            int freq[26] = {0};

            while(high < size){
                int idx = s[high] - 'a';

                if(freq[idx] == 0) // first occurence
                actUniqueChar++;

                freq[idx]++;

                if(freq[idx]== k)
                charAtLeastK++;


                while(actUniqueChar > uniqueChar){
                    int id = s[low] - 'a';

                    if(freq[id] == k)
                    charAtLeastK--;

                    freq[id]--;   //ORDER MATTERS CHECK FIRST THEN REDUCE FREQ

                    if(freq[id] == 0)
                    actUniqueChar--;

                    low++;
                }

                if(actUniqueChar == charAtLeastK){
                    ans = max(ans, high - low + 1);
                }
                high++;
            }
        }

        return ans;
    }
};