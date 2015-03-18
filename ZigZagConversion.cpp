#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        vector<string> result;
        int i = 0;
        bool isUp = false;
        for (int j = 0;j < nRows;j++)
        {
            result.push_back("");
        }
        //cout << result.size();
        for (int j = 0;j < s.size();j++)
        {
            if (i == 0)
            {
                result[i].push_back(s[j]);
                isUp = false;
            }
            else if (i == nRows - 1)
            {
                result[i].push_back(s[j]);
                isUp = true;
            }
            else
            {
                result[i].push_back(s[j]);
            }


            if (nRows == 1)
            {
                i = 0;
            }
            else
            {
                 i = isUp?i - 1:i + 1;
            }
        }

        string outputString;
        for (int j = 0;j <nRows;j++)
        {
            //cout<<result[j]<<endl;
            outputString.append(result[j]);
        }
        return outputString;
    }
};


int main()
{
    Solution s;
    cout<<s.convert("AB",1);
    return 0;
}
