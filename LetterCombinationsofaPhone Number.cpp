#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<string> result;
public:
    vector<string> letterCombinations(string digits) {
        string now;
        if (digits.size() == 0)
            return result;
        DFS(digits,now);
        return result;
    }
    void DFS(string digits,string now)
    {
        if (digits.size() > 0)
        {
            if (digits[0] - '0' < 7)
            {
                for (int i =  0;i < 3;i++)
                {
                    char c = 'a' + (digits[0] - '0' - 2) * 3  + i;
                    now.push_back(c);
                    DFS(digits.substr(1,digits.size() - 1),now);
                    now.pop_back();
                }
            }
            else
            {
                switch (digits[0])
                {
                    case '7':
                    {
                        for (char c = 'p';c <= 's';c++)
                        {
                            now.push_back(c);
                            DFS(digits.substr(1,digits.size() - 1),now);
                            now.pop_back();
                        }
                    }
                    break;
                    case '8':
                    {
                        for (char c = 't';c <= 'v';c++)
                        {
                            now.push_back(c);
                            DFS(digits.substr(1,digits.size() - 1),now);
                            now.pop_back();
                        }
                    }
                    break;
                    default:
                    {
                        for (char c = 'w';c <= 'z';c++)
                        {
                            now.push_back(c);
                            DFS(digits.substr(1,digits.size() - 1),now);
                            now.pop_back();
                        }
                    }
                }
            }
        }
        else
        {
            result.push_back(now);
        }
    }
};

int main()
{
    Solution s;
    vector<string> result  = s.letterCombinations("7");
    for (int i = 0;i < result.size();i++)
    {
        cout<<result[i]<<endl;
    }

    cout << "Hello world!" << endl;
    return 0;
}
