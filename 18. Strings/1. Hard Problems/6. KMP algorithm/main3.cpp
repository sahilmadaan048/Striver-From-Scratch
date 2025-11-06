// https://www.youtube.com/watch?v=sODA1BzFvsE

// https://www.youtube.com/watch?v=6gQR8TaFXMw

// https://takeuforward.org/data-structure/kmp-algorithm-or-lps-array

#include <bits/stdc++.h>
using namespace std;

// Class that contains the KMP algorithm and LPS array construction
class Solution {
public:
    // Function to compute the LPS (Longest Prefix Suffix) array
    vector<int> computeLPS(string pattern) {
        // Create LPS array initialized with 0
        vector<int> lps(pattern.length(), 0);

        // Length of the previous longest prefix which is also a suffix
        int len = 0;

        // Start from the second character of the pattern
        int i = 1;

        // Loop to fill the LPS array
        while (i < pattern.length()) {
            // If current character matches the character at len
            if (pattern[i] == pattern[len]) {
                // Increase length of current matching prefix
                len++;
                // Assign it to lps[i]
                lps[i] = len;
                // Move to next index
                i++;
            } else {
                // If mismatch and len is not 0, try shorter previous prefix
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    // If no prefix match found, set lps[i] to 0
                    lps[i] = 0;
                    // Move to next index
                    i++;
                }
            }
        }
        // Return the complete LPS array
        return lps;
    }

    // Function to search pattern in text using KMP
    vector<int> KMP(string text, string pattern) {
        // Preprocess the pattern and compute LPS array
        vector<int> lps = computeLPS(pattern);
        // Vector to store the starting indices of all matches
        vector<int> result;
        // Pointers for text and pattern
        int i = 0;
        int j = 0;

        // Loop through the text
        while (i < text.length()) {
            // If characters match, move both pointers
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            // If the whole pattern is matched
            if (j == pattern.length()) {
                // Store the index of match
                result.push_back(i - j);

                // Use LPS to continue searching
                j = lps[j - 1];
            }
            // If mismatch occurs after some matches
            else if (i < text.length() && text[i] != pattern[j]) {
                // Use LPS to avoid unnecessary comparisons
                if (j != 0) {
                    j = lps[j - 1];
                } else {

                    // Move forward in text if j is at start
                    i++;
                }
            }
        }
        // Return all found indices
        return result;
    }
};

// Main function to test the KMP search
int main() {
    // Define the text string
    string text = "ababcababcabc";
    // Define the pattern to search
    string pattern = "abc";

    // Create an object of the Solution class
    Solution sol;

    // Call the KMP function to get all match indices
    vector<int> matches = sol.KMP(text, pattern);

    // Output the results
    cout << "Pattern found at indices: ";
    for (int idx : matches) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}

/*

longest common proper prefix suffix array

*/