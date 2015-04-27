#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        int tempLong = 0;
        vector<int> pos;
        vector<bool> re;
        re.resize(s.size());

        for (int i = 0;i < s.size();i++)
        {
            re[i] = false;
        }

        for (int i = 0;i < s.size();i++)
        {
            if (s[i] == '(')
            {
                pos.push_back(i);
            }
            else
            {
                if (pos.size() > 0)
                {
                    int j = pos[pos.size() - 1];
                    pos.pop_back();
                    re[j] = true;
                    re[i] = true;
                }
            }
        }

        for (int i = 0;i < re.size();i++)
        {
            if (re[i])
            {
                tempLong++;
            }
            else
            {
                longest = longest > tempLong?longest:tempLong;
                tempLong = 0;
            }
        }
        longest = longest > tempLong?longest:tempLong;
        return longest;
    }
};

int main()
{
    Solution s;
    cout<<s.longestValidParentheses(")()())()()(");
    return 0;
}
