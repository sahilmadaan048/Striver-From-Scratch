// https://takeuforward.org/plus/dsa/problems/number-of-distinct-substrings-in-a-string?tab=editorial

// https://takeuforward.org/data-structure/number-of-distinct-substrings-in-a-string-using-trie/

                                
#include <iostream>
#include <set>
#include <string>
using namespace std;

// Function to count all distinct
// substrings of a given string
set<string> countDistinctSubstrings(const string& s) {
    // Set to store
    // distinct substrings
    set<string> st;

    // Length of the
    // input string
    int n = s.length();

    // Iterate over each
    // character in the string
    for (int i = 0; i < n; i++) {
        // Initialize an empty string
        // to store the current substring
        string str = "";

        // Iterate over the remaining characters 
        // in the string starting from index i
        for (int j = i; j < n; j++) {
            // Append the current
            // character to the substring
            str += s[j];

            // Insert the current
            // substring into the set
            st.insert(str);
        }
    }

    // Return the set containing
    // all distinct substrings
    return st;
}

int main() {
    string s = "striver";
    cout << "Given String: " << s << endl;

    // Call the function to
    // count distinct substrings
    set<string> substrings = countDistinctSubstrings(s);
    int count = 0;
    // Print the distinct substrings
    cout << "Distinct Substrings:" << endl;
    for (const auto& substr : substrings) {
        cout << substr << endl;
        count ++;
    }
    // Count + 1 as we have to count
    // the empty string as well
    cout << "Number of distinct substrings: "<< count + 1<< endl;

    return 0;
}
                                
/*
Time Complexity: O(N*N) where N is the number of characters in the given word. The implementation has two nested loops:

The outer loop iterates over each character of the string, leading to O(N) iterations.
The inner loop iterates over the remaining characters in the string for each character, also leading to O(N) iterations in the worst case.
Space Complexity : O(N*N)where N is the number of characters in the given word. The size of the set to store distinct substrings can grow up to O(N*N) in the worst case where all substrings are distinct. Each substring stored in the set occupies space proportional to its length, but the total space occupied by all substrings will limit to O(N*N).

*/