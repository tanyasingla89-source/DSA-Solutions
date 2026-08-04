class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s="1";
        for(int i=0;i<n-1;i++)
        {
            char ch=s[0];
            int count=0;
            int j=0;
            string nw="";
            while(j<s.size())
            {
                if(s[j]==ch){count++; j++;}
                else{ nw=nw+to_string(count)+ch; ch=s[j]; count=0;}
                }
                nw=nw+to_string(count)+ch;
                s=nw;
            }
           return s;

        }
        
    
};
