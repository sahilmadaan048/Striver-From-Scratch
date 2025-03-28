// https://takeuforward.org/switch-case/switch-case-statements/

// https://www.geeksforgeeks.org/problems/java-switch-case-statement3529/1/

class Solution
{
public:
    double switchCase(int choice, vector<double> &arr)
    {
        switch (choice)
        {
        case 1:
            return M_PI * arr[0] * arr[0];
        case 2:
            return arr[0] * arr[1];
        }
    }
};

//my code