class Solution {
public:
    string getPermutation(int n, int k) {
        int fac=1;
        vector<int>ans;
        for(int i=1;i<n;i++)
        {
            fac=fac*i;
            ans.push_back(i);
        }
        ans.push_back(n);
        k=k-1;
        string s="";
        while(ans.size()>0)
        {
            s+=to_string(ans[k/fac]);
            ans.erase(ans.begin()+(k/fac));
            if(ans.size()==0) break;
            k=k%fac;
            fac=fac/ans.size();
        }
        return s;
    }
};
