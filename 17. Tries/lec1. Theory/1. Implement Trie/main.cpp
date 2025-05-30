// https://takeuforward.org/data-structure/implement-trie-1/

// https://leetcode.com/problems/implement-trie-prefix-tree/description/

struct Node {
    Node * links[26];

    bool flag = false;

    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
        return;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
    
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        int n = word.size();
        for(int i=0; i<n; i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }   

            //move to the next node
            node = node->get(word[i]);
        }
        node->setEnd();
        return;
    }
    
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */