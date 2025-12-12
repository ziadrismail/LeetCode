class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        memset(child, 0, sizeof(child));
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
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
    
    bool search(string word) {
        TrieNode* node = root;
        for (auto &c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) {
                return false;
            }
            node = node->child[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (auto &c : prefix) {
            int idx = c - 'a';
            if (!node->child[idx]) {
                return false;
            }
            node = node->child[idx];
        }
        return true;
    }
};

/**
    N -> # of calls
    L -> input string length
    Space: O(NxL)
    Time: O(L) for each call -> O(NxL)
 */
