// https://www.geeksforgeeks.org/problems/lcm-and-gcd4516/1
// https://takeuforward.org/data-structure/find-gcd-of-two-numbers/


/*

we will use euclidean algorithm => the gcd of two numbers remain same when the smaller number is subtracted from the larger number

so we will continue doing so untul one of the number becomes 0,
then the other number will become the gcd of the 2 numbers

*/

#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int a = 10;
    int b = 20;
    int gcd = __gcd(a, b); 
    cout << gcd << endl;
}   


void solve2(){
    int a = 10;
    int b = 20;

    while(a and b) {
        if(a>b){
            a%=b;
        }else{
            b%=a;
        }
    }

    if(a==0) cout<<b;
    else cout << a;
}   


int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve2();
    }
    return 0;
}

    