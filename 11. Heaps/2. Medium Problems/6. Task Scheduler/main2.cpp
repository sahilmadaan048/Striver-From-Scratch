class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        vector<int> freq(26, 0);
        for(char task : tasks) freq[task - 'A']++;

        int maxFreq = *max_element(freq.begin(), freq.end());
        int countMax = count(freq.begin(), freq.end(), maxFreq);

        int partCount = maxFreq - 1;
        int partLength = K + 1;  // use K instead of n
        int emptySlots = partCount * partLength + countMax;

        return max((int)tasks.size(), emptySlots);
    }
};
