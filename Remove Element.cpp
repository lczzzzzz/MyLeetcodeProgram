#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i,j;
        i = 0;
        j = n - 1;
        while (i <= j)
        {
            if (A[i] == elem)
            {
                while ((j >= i) && (A[j] == elem))
                {
                    j--;
                }

                if (j < i)
                    break;
                A[i] = A[j];
                j--;
            }
            i++;
        }
        return i;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Solution s;
    int A[] = {1,3,1,3,2};
    cout<<s.removeElement(A,5,1);
    return 0;
}
