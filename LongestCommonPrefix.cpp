#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        if (strs.size() == 0)
            return "";
        else if (strs[0] == "")
            return "";
        prefix.append(strs[0]);
        for (int j = 0;j < strs[0].size();j++)
        {
            for (int i = 1;i < strs.size();i++)
            {
                if ((j < strs[i].size()) && (strs[0][j] == strs[i][j]))
                {
                    continue;
                }
                else
                {
                    return prefix.substr(0,j);
                }
            }
        }
        return prefix;
    }
};

int main()
{
    Solution s;
    vector<string> strs;
    strs.push_back("ab");
    strs.push_back("abcc");
    //strs.push_back("");
    s.longestCommonPrefix(strs);
    cout << "Hello world!" << endl;
    return 0;
}
