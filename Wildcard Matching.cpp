#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> > f(s.size() + 1,vector<bool>(p.size() + 1));

        f[0][0] = true;
        int sn = s.size();
        int pn = p.size();

        for (int i = 1;i <= pn;i++)
        {
            f[0][i] = f[0][i - 1] && (p[i - 1] == '*');
        }

        for (int i = 1;i <= sn;i++)
        {
            f[i][0] = false;
        }

        for (int i = 1; i <= sn;i++)
        {
            for (int j = 1;j <= pn;j++)
            {
                if (p[j - 1] != '*')
                {
                    f[i][j] = f[i - 1][j - 1] && ((p[j - 1] == s[i - 1]) || (p[j - 1] == '?'));
                }
                else
                {
                    f[i][j] = f[i][j - 1] || f[i - 1][j];
                }
            }
        }

        return f[sn % 2][pn];
    }
};
int main()
{
    string s = "bbbaab";
    string p = "a**?***";
    Solution so;
    cout<<so.isMatch(s,p)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
