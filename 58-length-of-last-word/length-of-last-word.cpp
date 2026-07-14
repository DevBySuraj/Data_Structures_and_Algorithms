class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int count = 0;
        int j = len - 1;

        while(j>=0 && s[j] == ' '){
            // if(s[j] == ' ') j--;
            j--;
        }

        while(j>=0 && s[j] != ' '){
                count++;
                j--;
        }
        return count;
    }
};