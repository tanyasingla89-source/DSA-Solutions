class Solution {
public:
int findmax(vector<int>& piles)
{
    int maxi=INT_MIN;
    for(int i=0;i<piles.size();i++)
    {
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findmax(piles);
        while(low<=high)
        {
            int mid=(low+high)/2;
            long long sum=0;
            for(int i=0;i<piles.size();i++){
            sum=sum+(piles[i]+mid-1)/mid;
        }
        if(sum<=h) high=mid-1;
        else low=mid+1;
        }
        return low;
    }
};
