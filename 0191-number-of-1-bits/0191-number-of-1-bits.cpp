class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        for(;n>0;)
        {
            int b=n%2;
            n=n/2;
            if(b==1)
            {
                count++;
            }

        }
        return count;
    }
};