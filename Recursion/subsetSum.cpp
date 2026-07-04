class Solution{   
public:
bool print(vector<int>&arr, int target,int n,int i,int sum)
{
    if(i==n)
    {
        if(sum==target) return true;
        return false;
    }
    sum+=arr[i];
    if(print(arr,target,n,i+1,sum)) return true;
    sum-=arr[i];
    if(print(arr,target,n,i+1,sum)) return true;
    return false;
}
    bool isSubsetSum(vector<int>arr, int target){
      bool m= print(arr,target,arr.size(),0,0);
      return m;
    }
};
