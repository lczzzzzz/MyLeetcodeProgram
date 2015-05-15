#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string resultString;
        vector<int> result;
        int flag = 1;
        result.resize(num1.size() + num2.size() - 1);
        for (int i = 0;i < result.size();i++)
        {
            result[i] = 0;
        }

        if ((num1.size() == 0) || (num2.size() == 0))
        {
            return resultString;
        }

        if (num1[0] == '-')
        {
            flag *= -1;
            num1.erase(0,1);
        }
        else  if (num1[0] == '+')
        {
            num1.erase(0,1);
        }
        if (num2[0] == '-')
        {
            flag *= -1;
            num2.erase(0,1);
        }
        else if (num2[0] == '+')
        {
            num2.erase(0,1);
        }


        for (int i = num2.size() - 1;i >= 0;i--)
        {
            for (int j = num1.size() - 1;j >= 0;j--)
            {
                result[num2.size() - 1 - i + num1.size() - 1 - j] += (num2[i] - '0') * (num1[j] - '0');
            }
        }


        for (int i = 0; i< result.size() - 1;i++)
        {
            result[i + 1] += result[i] / 10;
            result[i] = result[i] % 10;
        }

        while (result[result.size() - 1] >= 10)
        {
            result.push_back(result[result.size() - 1] / 10);
            result[result.size() - 2] = result[result.size() - 2] % 10;
        }

        if (result[result.size() - 1] == 0)
        {
            resultString.push_back('0');
            return resultString;
        }
        if (flag == -1)
        {
            resultString.push_back('-');
        }
        for (int i = result.size() - 1;i >= 0;i--)
        {
            resultString.push_back(result[i] + '0');
        }

        return resultString;
    }
};
int main()
{
    Solution s;
    string num1 = "-1";
    string num2 = "1";
    cout<<s.multiply(num1,num2);
    cout << "Hello world!" << endl;
    return 0;
}
