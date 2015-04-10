#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (int i = 0;i <s.size();i++)
        {
            if ((s[i] == '{') || (s[i] == '[') || (s[i] == '('))
            {
                stack.push_back(s[i]);
            }
            else
            {
                if (stack.size() == 0)
                {
                    return false;
                }

                char temp;
                switch (s[i])
                {
                    case ')':temp = '(';break;
                    case '}':temp = '{';break;
                    case ']':temp = '[';break;
                }
                if (temp == stack[stack.size() - 1])
                {
                    stack.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }

        if (stack.size() == 0)
            return true;
        else
            return false;
    }
};
int main()
{
    string s = "()";
    Solution so;
    cout<<so.isValid(s);
    cout << "Hello world!" << endl;
    return 0;
}
