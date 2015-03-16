#include <iostream>
#include <algorithm>
//#include <hash_map>

using namespace std;
//using namespace __gnu_cxx;

class Solution {
//typedef hash_map<char,int>::iterator mapIterator;
public:
    int lengthOfLongestSubstring(string s) {
        //hash_map<char,int> substr;
        int substr[1024];
        int maxLength = 0;
        unsigned int  i = 0;

        for (int j = 0;j < 1000;j++)
        {
            substr[j] = -1;
        }

        int length = 0;
        unsigned int temp;

        for (int j = 0;j < s.size();j++)
            for (int k = j;k < s.size();k++)
            {
                temp = char(s[k]);
                if (substr[temp] == -1)
                {
                    substr[temp] = k;
                    length++;
                    maxLength = maxLength < length?length:maxLength;
                    i++;
                }
                else
                {
                    temp = s[k];
                    for (int q = 0;q < 1000;q++)
                    {
                        substr[q] = -1;
                    }
                    length = 0;
                    break;
                }
            }
        maxLength = maxLength < length?length:maxLength;
        return maxLength;
    }
};
int main()
{
    Solution s;
    cout<<s.lengthOfLongestSubstring("gnhfljxmsudswvlxog");
    return 0;
}
