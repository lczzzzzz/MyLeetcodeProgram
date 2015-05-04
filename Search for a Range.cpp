#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int i = binarySearch(A,0,n - 1,target);
        vector<int> result;
        if (i == -1)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        int j;
        for (j = i - 1;j >= 0;j--)
        {
            if (A[i] != A[j])
            {
                result.push_back(j + 1);
                break;
            }
        }

        if (j == -1)
        {
            result.push_back(0);
        }

        for (j = i + 1;j < n;j++)
        {
            if (A[i] != A[j])
            {
                result.push_back(j - 1);
                break;
            }
        }

        if (j == n)
        {
            result.push_back(n - 1);
        }

        return result;
    }

    int binarySearch(int A[],int a,int b,int target)
    {
        int mid = (a + b) / 2;
        if (a >b)
            return -1;
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

int main()
{
    Solution s;
    int A[] = {5, 7, 7, 8, 8, 10};
    vector<int > result = s.searchRange(A,1,0);

    for (int i = 0;i < result.size();i++)
    {
        cout<<result[i]<<" ";
    }
    cout << "Hello world!" << endl;
    return 0;
}
