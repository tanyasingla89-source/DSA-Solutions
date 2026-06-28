class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++)
        {
            while(!st.empty() && st.top()>0 && asteroids[i]<0)
            {
                    if(st.top()<(abs(asteroids[i])))
                    {
                        st.pop();
                    }
                    else if(st.top()==(abs(asteroids[i])))
                    {
                        st.pop();
                        goto next;
                    }
                    else
                    {
                        goto next;
                    }
            }
            st.push(asteroids[i]);
            next:;

        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
