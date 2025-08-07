// binary search approach

class Solution {
public:
    vector<vector<int>> findPairsWithGivenSum(ListNode* head, int target) {
        vector<pair<int, int>> nodes; // {value, index}
        int index = 0;

        for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
            nodes.push_back({curr->val, index++});
        }

        // Sort nodes by value for binary search
        sort(nodes.begin(), nodes.end());

        vector<vector<int>> result;

        for (int i = 0; i < nodes.size(); ++i) {
            int remaining = target - nodes[i].first;

            // Binary search for remaining value in the rest of the array
            int low = i + 1, high = nodes.size() - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (nodes[mid].first == remaining) {
                    // Check index order (to preserve a before b)
                    if (nodes[i].second < nodes[mid].second) {
                        result.push_back({nodes[i].first, nodes[mid].first});
                    }
                    
                    // Handle duplicates (go both left and right from mid)
                    int left = mid - 1;
                    while (left > i && nodes[left].first == remaining) {
                        if (nodes[i].second < nodes[left].second)
                            result.push_back({nodes[i].first, nodes[left].first});
                        left--;
                    }

                    int right = mid + 1;
                    while (right < nodes.size() && nodes[right].first == remaining) {
                        if (nodes[i].second < nodes[right].second)
                            result.push_back({nodes[i].first, nodes[right].first});
                        right++;
                    }

                    break;
                }
                else if (nodes[mid].first < remaining) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        return result;
    }
};
