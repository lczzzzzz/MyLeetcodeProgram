#include <iostream>
#include <cstring>

using namespace std;
class Solution {
string sstr;
string pstr;
string gstr;

public:
    bool isMatch(const char *s, const char *p) {
            sstr.append(s);
            pstr.append(p);
            return DFS(sstr,pstr,gstr,0,0);
        }
    bool DFS(string s,string p,string g,int length,int j)
    {
        if ((length == s.size()) && (j >= p.size()))
        {
            for (int k = 0;k < s.size();k++)
            {
                if ((s[k] == g[k]) || (g[k] == '.'))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            if (j >= p.size())
            {
                return false;
            }
            if (j + 1 < p.size())
            {
                if (p[j + 1] == '*')
                {
                    for (int i = 0;i + length <= s.size();i++)
                    {
                        cout<<s<<" "<<g<<" "<<length + i<<" "<<j + 2<<endl;
                        if (i != 0)
                        {
                            if ((s[length + i - 1] != g[length + i - 1]) && (g[length + i - 1] != '.'))
                            {
                                return false;
                            }
                        }

                        if (DFS(s,p,g,length + i,j + 2))
                            return true;
                        g.push_back(p[j]);
                    }
                }
                else
                {
                    g.push_back(p[j]);
                    cout<<s<<" "<<g<<" "<<length + 1<<" "<<j + 1<<endl;
                    if ((s[length] != g[length]) && (g[length] != '.'))
                        return false;
                    if (DFS(s,p,g,length + 1,j + 1))
                        return true;
                }
            }
            else
            {
                 g.push_back(p[j]);
                 cout<<s<<" "<<g<<" "<<length + 1<<" "<<j + 1<<endl;
                if ((s[length] != g[length]) && (g[length] != '.'))
                    return false;
                 if (DFS(s,p,g,length + 1,j + 1))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout<<s.isMatch("a","ab*");
    cout << "Hello world!" << endl;
    return 0;
}
