// https://leetcode.com/problems/next-permutation/description/

// https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        next_permutation(nums.begin(), nums.end());

        return;
    }   
};

/*







#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}






*/

