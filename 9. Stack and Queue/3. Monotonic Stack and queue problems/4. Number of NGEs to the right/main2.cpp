class Solution {
  public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        int n = arr.size();
        vector<int> temp(n, 0);

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) count++;
            }
            temp[i] = count;
        }

        vector<int> ans;
        for (int idx : indices) ans.push_back(temp[idx]);
        return ans;
    }
};
