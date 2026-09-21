class Solution {
public:

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int steps = 1;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string word = q.front();
                q.pop();

                if (word == endWord)
                    return steps;

                for (int i = 0; i < word.size(); i++) {

                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        word[i] = ch;

                        if (wordSet.find(word) != wordSet.end()) {

                            q.push(word);
                            wordSet.erase(word);
                        }
                    }

                    word[i] = original;
                }
            }

            steps++;
        }

        return 0;
    }
};