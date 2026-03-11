// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree

#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define nl cout << "\n"
#define dbg(var) cout << #var << "=" << var << " "
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define srt(v) sort(v.begin(), v.end())         // sort
#define mxe(v) *max_element(v.begin(), v.end()) // find max element in vector
#define mne(v) *min_element(v.begin(), v.end()) // find min element in vector
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed
#define bin(x, y) bitset<y>(x)
using namespace std;
int MOD = 1e9 + 7; // Hardcoded, directly change from here for functions!

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }
// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr);
};

class Solution
{
public:
    vector<vector<int>> findVertical(Node *root)
    {
        if (root == NULL)
            return {};

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Node *, pair<int, int>>> todo;

        todo.push({root, {0, 0}});

        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();

            Node *temp = p.first;

            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(temp->data);

            if (temp->left)
            {
                todo.push({temp->left, {x - 1, y + 1}});
            }

            if (temp->right)
            {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto p : nodes)
        {
            vector<int> col;

            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
};

void printResult(const vector<vector<int>> &result)
{
    for (auto level : result)
    {
        for (auto node : level)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve()
{
    // Create sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    // Create solution object
    Solution solution;

    // Call vertical order traversal
    vector<vector<int>> verticalTraversal = solution.findVertical(root);

    // Print result
    cout << "Vertical Traversal:" << endl;
    printResult(verticalTraversal);

    return 0;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
