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
    bool isLeaf(Node *root)
    {
        return !root->left and !root->right;
    }

    void addLeftBoundary(Node *root, vector<int> &res)
    {
        Node* curr = root->left;
        while(curr) {
            if(!isLeaf(curr)) {
                res.push_back(curr->data);
            }
            if(curr->left) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
    }

    void addRightBoundary(Node *root, vector<int> % res)
    {
        vector<int> temp;
        Node* curr = root->right;
        while(curr) {
            if(!isLeaf(curr)) {
                temp.push_back(curr->data);
            }

            if(curr->right) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }

        for(int i=temp.size()-1; i>=0; i--) {
            res.push_back(temp[i]);
        }

    }

    void addLeaves(Node *root, vector<int> &res)
    {
        if(isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if(root->left) {
            addLeaves(root->left, res);
        }
        if(root->right) {
            addLeaves(root->right, res);
        }
    }

    vector<int> printBoundary(Node *root)
    {
        vector<int> res;

        if (!root)
        {
            return res;
        }

        if (!isLeaf(root))
        {
            res.push_back(root->data);
        }

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

void printResult(const vector<int> &result)
{
    for (auto &val : result)
    {
        cout << val << " ";
    }
    cout << "\n";
}


void solve()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
