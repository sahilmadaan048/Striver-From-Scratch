// https://leetcode.com/problems/trapping-rain-water/description/


// https://takeuforward.org/data-structure/trapping-rainwater/

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n=height.size(),area=0;
        stack<int>stk;
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() && height[i]>height[stk.top()])
            {
                int j=stk.top();
                stk.pop();
                if(!stk.empty())
                {
                    int h=min(height[stk.top()],height[i])-height[j];
                    int b=i-stk.top()-1;
                    area+=(b*h);
                }
            }
            stk.push(i);
        }             
        return area;             
    }
};