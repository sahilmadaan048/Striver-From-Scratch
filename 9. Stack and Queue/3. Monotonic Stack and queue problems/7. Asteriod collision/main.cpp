// https://leetcode.com/problems/asteroid-collision/description/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int a = asteroids[i];

            if (a > 0) {
                st.push(a);
            } else {
                // Handle collisions
                while (!st.empty() && st.top() > 0 && st.top() < -a) {
                    st.pop();
                }

                if (st.empty() || st.top() < 0) {
                    st.push(a);
                } else if (st.top() == -a) {
                    st.pop(); // both explode
                }
            }
        }

        // Transfer stack to result vector (in reverse order)
        vector<int> res(st.size());
        int i = st.size() - 1;
        while (!st.empty()) {
            res[i--] = st.top();
            st.pop();
        }
        return res;
    }
};
c