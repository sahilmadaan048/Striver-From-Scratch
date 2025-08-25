// https://leetcode.com/problems/accounts-merge/description/

// https://takeuforward.org/data-structure/accounts-merge-dsu-g-50/

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n+1); 
        size.assign(n+1, 0);
        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int find(int a) {
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }

    void union_set(int a,  int b) {
        a = find(a);
        b = find(b);

        if(a != b) {
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // if email is same, merge the acoounts

        sort(accounts.begin(), accounts.end());

        int n = accounts.size();

        DSU dsu(n);

        unordered_map<string, int > mpp;

        for(int i=0; i<n; i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                string email = accounts[i][j];
                if(mpp.count(email)) {
                    dsu.union_set(i, mpp[email]);
                }
                else {
                    mpp[email] = i;
                }
            }          
        }

        unordered_map<int, vector<string>> merged;
        for(auto &p : mpp) {
            string email = p.first;
            int accIndex = dsu.find(p.second);
            merged[accIndex].push_back(email);
        }

        vector<vector<string>> ans;
        for(auto p: merged) {
            int idx = p.first;
            vector<string> emails = p.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[idx][0]);
            ans.push_back(emails);
        }

        return ans;
    }
};