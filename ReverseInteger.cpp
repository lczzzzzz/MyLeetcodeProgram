#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class Solution {
public:
    int reverse(int x) {
            string number;
            stringstream ss;
            string result;

            ss<<x;
            ss>>number;
            if (number[0] == '-')
            {
                result.push_back('-');
                number.erase(number.begin());
            }

            for (int i = number.size() - 1;i >= 0 ;i--)
            {
                result.push_back(number[i]);
            }

            stringstream rss;
            int resultNumber;
            rss<<result;
            rss>>resultNumber;

            if ((resultNumber == 2147483647) || (resultNumber == -2147483646))
                return 0;

          //  int resultNumber = stoi(result);
            return resultNumber;
    }
};

int main()
{
    Solution s;
    cout<<s.reverse(-123);
    cout << "Hello world!" << endl;
    return 0;
}
