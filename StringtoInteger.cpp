#include <iostream>

using namespace std;
class Solution {
public:
    int atoi(string str) {
            int flag = 1;
            while (str[0] == ' ')
            {
                   str.erase(str.begin());

                    if (str.size() == 0)
                    {
                        return 0;
                    }
            }
            if (str[0] == '-')
            {
                str.erase(str.begin());
                flag = -1;
            }
            else if (str[0] == '+')
            {
                str.erase(str.begin());
            }

            long result;
            if (str.size() == 0)
            {
                return 0;
            }

            while ((str[0] <= '0') || (str[0] > '9'))
            {
                if (str[0] == '0')
                {
                    str.erase(str.begin());

                    if (str.size() == 0)
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }

            }

            result = str[0] - '0';
            for (int i = 1;i < str.size();i++)
            {
                if ((str[i] < '0') || (str[i] > '9'))
                {
                    return result * flag;
                }
                result = result * 10 + str[i] - '0';
                if (flag * result < -2147483648)
                    return -2147483648;
                if (flag * result > 2147483647)
                    return 2147483647;
            }
            return result * flag;
    }
};
int main()
{
    Solution s;
    cout<<s.atoi("1");
    cout << "Hello world!" << endl;
    return 0;
}
