class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        int m=heights.size();
        int maxi=0;
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty() && heights[s.top()]>heights[i])
            {
                int n=s.top();
                s.pop();
                if(s.empty())
                {
                    maxi=max(maxi,heights[n]*(i));
                }
                else
                {
                    maxi=max(maxi,heights[n]*(i-s.top()-1));
                }
            }
            s.push(i);
        }
        while(!s.empty())
        {
            int n=s.top();
            s.pop();
            if(s.empty())
            {
                maxi=max(maxi,heights[n]*(m));
            }
            else
            {
                maxi=max(maxi,heights[n]*(m-s.top()-1));
            }
        }return maxi;
    }
};
