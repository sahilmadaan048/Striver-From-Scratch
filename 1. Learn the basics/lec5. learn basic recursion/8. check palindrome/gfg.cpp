#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    int reverse = 0;
  
    // Copy of the original number so that the original
    // number remains unchanged while finding the reverse
    int temp = abs(n);
    while (temp != 0) {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }
    
    // If reverse is equal to the original number,
    // the number is palindrome
    return (reverse == abs(n));
}

int main() {
    int n = 12321;
    if (isPalindrome(n) == 1) {
        cout << "True";
    }
    else {
        cout << "False";
    }
    return 0;
}