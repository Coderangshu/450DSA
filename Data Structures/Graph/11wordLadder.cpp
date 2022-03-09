class Solution {
public:
    
    // Simple BFSing through  the dictionary words with beginWord as start node
    // and endWord as the target node in the graph
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ladder = 1;
        while (!q.empty()) {
            // going through all the nodes in the level
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string word = q.front();
                q.pop();
                if (word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                // Procedure to search through set for the
                // next neighbor of the current word
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        // if word found in dict push word into
                        // queue as it is the next neighbor of
                        // the current word
                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                        }
                     }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};
