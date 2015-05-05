class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        // for (int i = 0;i < nums.size();i++)
        // {
        //     if (target <= nums[i])
        //     {
        //         return i;
        //     }
        // }
        
        return binarySearch(nums,0,nums.size() - 1,target);
    }
    
    int binarySearch(vector<int> &A,int a,int b,int target)
    {
        int mid = (a + b) / 2;
        if (a >b)
            return a;
        else
        {
            if (target > A[mid])
                return binarySearch(A,mid + 1,b,target);
            else if (target < A[mid])
                return binarySearch(A,a,mid - 1,target);
            else
                return mid;
        }
    }
};