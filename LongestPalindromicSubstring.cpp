#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 0;
        int resultBegin = -1;
        int resultEnd = -1;
            for (int i = 0;i < s.size();i++)
            {
                int j = i;
                int k = i;
                while ((j >= 0) && (k < s.size()) && (s[j] == s[k]))
                {
                    j--;
                    k++;
                }
                if (k - j - 1 > maxLength)
                {
                    maxLength = max(k - j - 1,maxLength);
                    resultBegin = j + 1;
                    resultEnd = k - 1;
                }

                j = i - 1;
                k = i;

                while ((j >= 0) && (k < s.size()) && (s[j] == s[k]))
                {
                    j--;
                    k++;
                }
                if (k - j - 1 > maxLength)
                {
                    maxLength = max(k - j - 1,maxLength);
                    resultBegin = j + 1;
                    resultEnd = k - 1;
                }
            }
        string result;
        for (int q = resultBegin;q <= resultEnd;q++)
        {
            result.push_back(s[q]);
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.longestPalindrome("bb");

    return 0;
}
