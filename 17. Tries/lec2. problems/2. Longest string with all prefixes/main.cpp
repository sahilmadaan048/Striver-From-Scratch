// https://takeuforward.org/plus/dsa/problems/longest-word-with-all-prefixes

/*
Given a string array nums of length n. A string is called a complete string if every prefix of this string is also present in the array nums. Find the longest complete string in the array nums.

If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None" (without quotes).


Examples:
Input : nums = [ "n", "ni", "nin", "ninj" , "ninja" , "nil" ]

Output : ninja

Explanation : The word "ninja" is the longest word which has all its prefixes present in the array.

Input : nums = [ "ninja" , "night" , "nil" ]

Output : None

Explanation : There is no string that has all its prefix present in array. So we return None.


*/


struct Node
{
    // Array to store links to child nodes,
    // each index represents a letter
    Node *links[26];
    // Flag indicating if the node
    // marks the end of a word
    bool flag = false;

    // Check if the node contains
    // a specific key (letter)
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    // Insert a new node with a specific
    // key (letter) into the Trie
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // Get the node with a specific
    // key (letter) from the Trie
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // Set the current node
    // as the end of a word
    void setEnd()
    {
        flag = true;
    }

    // Check if the current node
    // marks the end of a word
    bool isEnd()
    {
        return flag;
    }
};
class Trie {
    private: Node *root; 
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0;i<word.size();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
        }
        node->setEnd(); 
    }
    bool checkIfAllPrefixExists(string word) {
        Node *node = root;
        bool flag = true; 
        for(int i = 0;i<word.size();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]); 
                flag = flag & node->isEnd(); 
            }
            else {  
                return false; 
            } 
        }
        return flag; 
    }
};

class Solution {
public:
    string completeString(vector<string>& a) {
        Trie* obj = new Trie();
        for(auto word : a) obj->insert(word); 
        string longest = ""; 
        for(auto word: a) {
            if(obj->checkIfAllPrefixExists(word)) {
                if(word.size() > longest.size()) {
                    longest = word; 
                }
                else if(word.size() == longest.size() && word < longest) {
                    longest = word; 
                }
            }
        }
        if(longest == "") return "None"; 
        return longest; 
    }
};