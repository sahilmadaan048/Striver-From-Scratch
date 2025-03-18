#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 4, 5, 5};
    unordered_map<int, int> hash;
    
    for (int i = 0; i < arr.size(); i++)
    {
        hash[arr[i]]++;
    }

    for (auto ele : arr)
    {
        cout << ele << " : " << hash[ele] << endl;
    }

    return 0;
}
