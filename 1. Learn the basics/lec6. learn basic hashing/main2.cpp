#include<iostream>
#include<vector>

using namespace std;
const int N = 1e5+1;
int main() {
    string arr = "abcdcodjqa";
    vector<int> hash(26);
    for(int i=0; i<arr.size(); i++) {
        hash[arr[i]-'a']++;
    } 
    for(auto ele: arr) {
        cout << ele << " : " << hash[(int)(ele-'a')] << endl;
    }
    return 0;
}
