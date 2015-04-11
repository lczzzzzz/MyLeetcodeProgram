#include <iostream>

using namespace std;
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
                if ((m + n) % 2)
                {
                    double median = findMedian(A,0,m,B,0,n,(m + n + 1) / 2);
                    return median;
                }
                else
                {
                    double median = 1.0 * (findMedian(A,0,m,B,0,n,(m + n ) / 2)
                                                +findMedian(A,0,m,B,0,n,(m + n) / 2 + 1)) / 2;
                    cout<<findMedian(A,0,m,B,0,n,(m + n ) / 2)<<" "<<findMedian(A,0,m,B,0,n,(m + n) / 2 + 1)<<endl;
                    return median;
                }
    }

    int findMedian(int A[],int beginA,int m,int B[],int beginB,int n,int k)
    {
        if ((n <= 0) || (A[beginA] >= B[beginB + n - 1]))
        {
            if (n <= 0)
            {
                n = 0;
            }
            if (k > n)
                return A[beginA + k - n - 1];
            else
                return B[beginB + k - 1];
        }
        else if ((m <= 0) || (B[beginB] >= A[beginA + m - 1]))
        {
            if (m <= 0)
            {
                m = 0;
            }
            if (k > m)
                return B[beginB + k - m - 1];
            else
                return A[beginA + k - 1];
        }
        else if (k == 1)
        {
            return (A[beginA] < B[beginB])?A[beginA]:B[beginB];
        }
        else if (k == 0)
        {
            return (A[beginA + m - 1] > B[beginB + n - 1])?A[beginA + m - 1]:B[beginB + n - 1];
        }
        else
        {
            int p = m / 2 + beginA;

            int i;
            for (i = beginB;i < n + beginB;i++)
            {
                if (B[i] >= A[p])
                    break;
            }

            if ((i - beginB + p - beginA) >= k)
            {
                cout<<beginA<<" "<<m / 2<<" "<<beginB<<" "<<i - beginB<<" "<<k<<endl;
                return findMedian(A,beginA,m / 2,B,beginB,i - beginB,k);
            }
            else
            {
                cout<<p<<" "<<m - m / 2<<" "<<i<<" "<<n - i<<" "<<k - (i - beginB + p - beginA)<<endl;
                return findMedian(A,p,m - m / 2,B,i,n - i + beginB,k - (i - beginB + p - beginA));
            }
        }
    }
};

int main()
{
    Solution s;
    int A[]={2,3,5,7,8,9,10};
    int B[]={1,4,6};
    s.findMedianSortedArrays(A,7,B,3);
    return 0;
}
