class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        memset(child, 0, sizeof(child));
        isEnd = false;
    }
};

class Solution {
private:
    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* node = root;
        for (auto &c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    bool can_build(string word) {
        TrieNode* node = root;
        for (auto &c : word) {
            int idx = c - 'a';
            if (!node->child[idx]->isEnd) {
                return false;
            }
            node = node->child[idx];
        }
        return true;
    }

public:
    string longestWord(vector<string>& words) {
        for (auto &word : words) {
            insert(word);
        } 

        string ans = "";
        for (auto &word : words) {
            if (can_build(word)) {
                if (ans.size() < word.size()) {
                    ans = word;
                } else if (ans.size() == word.size() && word < ans) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};

/*
    Time: O(S)
    Space: O(S)
*/
