#include <iostream>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        return binarySearch(A,0,n - 1,target);
    }

    int binarySearch(int A[],int a,int b,int target)
    {
        int mid = (a + b) / 2;

        if (a > b)
                return -1;
        if (A[a] > A[mid])
        {
            if (A[mid] < target)
            {
                if (target > A[b])
                {
                    return binarySearch(A,a,mid,target);
                }
                else
                {
                    return binarySearch(A,mid + 1,b,target);
                }
            }
            else if (A[mid] > target)
            {
                return binarySearch(A,a,mid,target);
            }
            else
            {
                return mid;
            }
        }
        else if (A[a] <= A[mid])
        {
            if (target > A[mid])
            {
                return binarySearch(A,mid + 1,b,target);
            }
            else if (target < A[mid])
            {
                if (target >= A[a])
                    return binarySearch(A,a,mid,target);
                else
                    return binarySearch(A,mid + 1,b,target);
            }
            else
            {
                return mid;
            }
        }
    }
};


int main()
{
    Solution s;
    int A[] = {4,5,6,7,0,1,2};
    cout<<s.search(A,7,0);
    cout << "Hello world!" << endl;
    return 0;
}
