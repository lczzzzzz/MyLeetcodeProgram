#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<string> result;
public:
    vector<string> generateParenthesis(int n) {
        string s;
        DFS(n,s,0);
        return result;
    }

    void DFS(int n,string s,int m)
    {
        string tempStr;
        if (n > 0)
        {
            tempStr = s;

            tempStr.push_back('(');
            DFS(n - 1,tempStr,m + 1);

            if (m != 0)
            {
                tempStr = s;
                tempStr.push_back(')');
                DFS(n,tempStr,m - 1);
            }
        }
        else
        {
            for (int q = 0;q < m;q++)
            {
                s.push_back(')');
            }
            result.push_back(s);
        }
    }
};



int main()
{
    Solution s;
    vector<string> r = s.generateParenthesis(3);
    for (int i = 0;i < r.size();i++)
    {
        cout<<r[i]<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
