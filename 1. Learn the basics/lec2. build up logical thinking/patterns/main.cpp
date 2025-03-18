// pattern based interview
#include <iostream>
using namespace std;

void print1(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

void print5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (n - i + 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n - i + 1); j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print7(int n)
{
    // priting spaces
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }

        // printing stars
        for (int j = 1; j <= (2 * i + 1); j++)
        {
            cout << "*";
        }

        // printing spaces agwain
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void print8(int n)
{
    // priting spaces
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }

        // printing stars
        for (int j = 1; j <= (2 * n - 2 * i - 1); j++)
        {
            cout << "*";
        }

        // printing spaces agwain
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void print9(int n)
{
    // priting spaces
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }

        // printing stars
        for (int j = 1; j <= (2 * i + 1); j++)
        {
            cout << "*";
        }

        // printing spaces agwain
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }
        cout << endl;
    }

    // priting spaces
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }

        // printing stars
        for (int j = 1; j <= (2 * n - 2 * i - 1); j++)
        {
            cout << "*";
        }

        // printing spaces agwain
        for (int j = 0; j < i + 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void print10(int n)
{
    for (int i = 1; i <= (2 * n - 1); i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void print11(int n)
{

    int start = 1;
    for (int i = 0; i < n; i++)
    {

        if (i % 2 == 0)
            start = 1;
        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}

void print12(int n)
{
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        // numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // space
        for (int j = 0; j <= space; j++)
        {
            cout << " ";
        }

        // numbers
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        space -= 2;
    }
}

void print13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

void print14(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << (char)(j + 64) << " "; // typecasting
        }
        cout << endl;
    }
}

void print15(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= (n - i + 1); j++)
        {
            cout << (char)(j + 64) << " "; // typecasting
        }
        cout << endl;
    }
}

void print16(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << (char)(i + 64) << " "; // typecasting
        }
        cout << endl;
    }
}

void print17(int n)
{
    // priting spaces
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }

        // printing CHARACTERS
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;

        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }

        // printing spaces agwain
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void print18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

void print19(int n)
{
    int initial_spaces = 0;
    for (int i = 0; i < n; i++)
    {

        // stars
        for (int j = 1; j <= (n - i); j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < initial_spaces; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 1; j <= (n - i); j++)
        {
            cout << "*";
        }

        initial_spaces += 2;
        cout << endl;
    }

    initial_spaces = 2 * n - 2;
    for (int i = 1; i <= n; i++)
    {

        // stars
        for (int j = 1; j <= (i); j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 0; j < initial_spaces; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 1; j <= (i); j++)
        {
            cout << "*";
        }

        initial_spaces -= 2;
        cout << endl;
    }
}

void print20(int n)
{
    int spaces = 2 * n - 2;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;

        if (i > n)
            stars = 2 * n - i;

        // stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        // spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }

        cout << endl;
        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}

void print21(int n, int m)
{
    // fill the stars in the boundary only
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                cout << "*";
            }
            else
                cout << " ";
        }
        cout << endl;
    }
}

void print22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int down = (2 * n - 2) - i;
            cout << n-(min(min(top, down), min(left, right))) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // print1(n,m);

    // print2(n);

    // print3(n);

    // print4(n);

    // print5(n);

    // print6(n);

    // print7(n);

    // print8(n);

    // print9(n);

    // print10(n);

    // print11(n);

    // print12(n);

    // print13(n);

    // print14(n);

    // print15(n);

    // print16(n);

    // print17(n);

    // print18(n);

    // print19(n) ;

    // print20(n);

    // print21(n,m);

    print22(n);

    return 0;
}