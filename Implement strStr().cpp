#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if (!strcmp(needle,""))
            return 0;
        int length = strlen(haystack) - strlen(needle);
        for (int i = 0;i <= length;i++)
        {
            if (haystack[i] == needle[0])
            {
                int j = 1;
                for (;j < strlen(needle);j++)
                {
                    if (haystack[i + j] != needle[j])
                        break;
                }

                if (j == strlen(needle))
                    return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout<<s.strStr("a","");
    cout << "Hello world!" << endl;
    return 0;
}
