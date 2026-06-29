class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;  // first element is always unique

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {  // new uniqu        // place it at position k
            nums[k]=nums[i];
                k++;
            }
        }

        return k;
    }
};
