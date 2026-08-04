class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        while(i<version1.size() || j<version2.size())
        {
        string a="";
        string b="";
            while(i<version1.size() && version1[i]!='.') {a=a+version1[i]; i++;}
            while(j<version2.size() && version2[j]!='.') {b=b+version2[j]; j++;}
            int v1;
            int v2;
            if(a.empty()) v1=0; else v1=stoi(a);
            if(b.empty()) v2=0;else v2=stoi(b);
            if(v1>v2)  return 1;
            if(v1<v2) return -1;
            i++; j++;
        }
        return 0;
    }
};
