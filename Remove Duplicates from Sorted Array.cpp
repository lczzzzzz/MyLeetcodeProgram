#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int p = 0;
        if (n == 0) return NULL;
        for (int i = 1;i < n ;i++)
        {
            if (A[p] != A[i])
            {
                A[p + 1]= A[i];
                p++;
            }
        }

        return p + 1;
    }
};

int main()
{
    Solution s;
    int A[] = {1,1,2};
    cout<<s.removeDuplicates(A,0);
    cout << "Hello world!" << endl;
    return 0;
}
