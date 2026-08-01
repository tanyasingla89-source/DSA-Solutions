class Solution {
public:
    int myAtoi(string s) {
        int j=0;
        while(j<s.size() && s[j]==' ')
        {
            j++;
        }
        int sign=1;
        if(j<s.size() && (s[j]=='-' || s[j]=='+')){ 
            if(s[j]=='-') {sign=-1;}
        j++;}
        long long result=0;
        while(j<s.size() && s[j]>='0' && s[j]<='9')
        {
            result=result*10+(s[j]-'0');
            if(result*sign<INT_MIN) return INT_MIN;
            if(result*sign>INT_MAX) return INT_MAX;
            j++;
        }
        return (long long)result*sign;

    }
};
