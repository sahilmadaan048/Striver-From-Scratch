#include<iostream>
#include<vector>

using namespace std;
const int N = 1e5+1;
int main() {
    vector<int> arr = {1, 2, 4, 5, 5};
    vector<int> hash(N);
    for(int i=0; i<arr.size(); i++) {
        hash[arr[i]]++;
    } 
    for(auto ele: arr) {
        cout << ele << " : " << hash[ele] << endl;
    }
    return 0;
}
