                                
#include <iostream>  
#include <string>    
using namespace std;  

struct Node {
    Node* links[26];  
    bool flag = false;  

    bool containsKey(char ch) {  
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch) {  
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {  
        links[ch - 'a'] = node;
    }

    void setEnd() {  
        flag = true;
    }

    bool isEnd() {  
        return flag;
    }
};

int countDistinctSubstrings(string &s) {  
    Node* root = new Node();  
    int cnt = 0;  
    int n = s.size();  
    for (int i = 0; i < n; i++) {  
        Node* node = root;  
        for (int j = i; j < n; j++) {  
            if (!node->containsKey(s[j])) {
                node->put(s[j], new Node());  
                cnt++;  
            }
            node = node->get(s[j]);  
        }
    }
    return cnt + 1;  
  
}

int main() {  
    string s = "striver";  
    cout << "Current String: " << s << endl;
    cout << "Number of distinct substrings: " << countDistinctSubstrings(s) << endl;  
    return 0;  

}
                                
/*

Time Complexity: O(N*N)where N is the length of the input string. This is because for each starting position of the substring, we traverse the entire substring once. However, due to the Trie structure, the actual number of comparisons is reduced as we progress.

Space Complexity : O(N*N) where N is the length of the input string. In the worst-case scenario, where there are no common prefixes among substrings the number of nodes could be as high as the total number of substrings which is bounded by O(N*N).


*/