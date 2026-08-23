class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> note;
        unordered_map<char,int> mag;

        for(char x : ransomNote){
            note[x]++;
        }

        for(char x : magazine){
            mag[x]++;
        }

        for(const auto&[key,value] : note){
            if(mag.find(key) != mag.end()){
                if(value > mag[key]) return false;
            }
            else return false;
        }
        return true;
    }
};