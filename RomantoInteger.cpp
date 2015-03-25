#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0;i < s.size() - 1;i++)
        {
            int k = r2i(s[i]);
            int j = r2i(s[i + 1]);
            k >=j? result+=k:result-=k;
        }
        result += r2i(s[s.size() - 1]);
        return result;
    }

    int r2i(char a)
    {
        switch (a)
        {
            case 'I':return 1;break;
            case 'V':return 5;break;
            case 'X':return 10;break;
            case 'L':return 50;break;
            case 'C':return 100;break;
            case 'D':return 500;break;
            case 'M':return 1000;break;
            default: return 0;
        }
    }
};

int main()
{
    Solution s;
    cout<<s.romanToInt("MCMLXXXIV");
    cout << "Hello world!" << endl;
    return 0;
}
