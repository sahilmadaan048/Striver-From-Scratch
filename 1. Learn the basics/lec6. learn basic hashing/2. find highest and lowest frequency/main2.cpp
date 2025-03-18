// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution
{
    int cnt(int i, vector<int> &nums, int k)
    {
        int ct = 0, count = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            ct += abs(nums[i] - nums[j]);
            if (ct > k)
                break;
            count++;
        }
        return count;
    }

public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int maxCount = 0, n = nums.size();
        for (int i = n - 1; i >= 0; i--)
        {
            maxCount = max(maxCount, cnt(i, nums, k));
        }
        return maxCount;
    }
};


int main() {
    Solution ob;
    
    return 0;
}