#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result;
        string temp;
        if (n <= 0)
        {
            return result;
        }

        result = "1";
        while (n > 1)
        {
            int k = 0;
            while (k < result.size())
            {
                int i = k;
                while ((result[k] == result[i]) && (i < result.size()))
                {
                    i++;
                }

                temp.push_back(i - k + '0');
                temp.push_back(result[k]);
                k = i;
            }

            result = temp;
            temp.clear();
            n--;
        }

        return result;

    }
};


int main()
{
    Solution s;
    cout<<s.countAndSay(5);
    cout << "Hello world!" << endl;
    return 0;
}
