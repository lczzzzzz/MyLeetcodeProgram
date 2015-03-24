#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<string> gewei;
        vector<string> shiwei;
        vector<string> baiwei;
        vector<string> qianwei;

        gewei.push_back("");
        shiwei.push_back("");
        baiwei.push_back("");
        qianwei.push_back("");
        for (int i = 1;i <= 3;i++)
        {
            string ge,shi,bai,qian;
            for (int j = 1;j <=i;j++)
            {
                ge.push_back('I');
                shi.push_back('X');
                bai.push_back('C');
                qian.push_back('M');
            }
            gewei.push_back(ge);
            shiwei.push_back(shi);
            baiwei.push_back(bai);
            qianwei.push_back(qian);
        }
            gewei.push_back("IV");
            shiwei.push_back("XL");
            baiwei.push_back("CD");
            gewei.push_back("V");
            shiwei.push_back("L");
            baiwei.push_back("D");
        for (int i = 1;i <= 3;i++)
        {
            string ge,shi,bai;
            ge.push_back('V');
            shi.push_back('L');
            bai.push_back('D');
            for (int j = 1;j <=i;j++)
            {
                ge.push_back('I');
                shi.push_back('X');
                bai.push_back('C');
            }
            gewei.push_back(ge);
            shiwei.push_back(shi);
            baiwei.push_back(bai);
        }

        gewei.push_back("IX");
        shiwei.push_back("XC");
        baiwei.push_back("CM");

        vector<vector<string>> calResults;
        calResults.push_back(gewei);
        calResults.push_back(shiwei);
        calResults.push_back(baiwei);
        calResults.push_back(qianwei);
        string result;
        int i = 0;
        while (num > 0)
        {
            int j = num % 10;
            num = num / 10;
            //cout<<calResults[i][1];
            result.insert(0,calResults[i][j]);
            //cout<<result;
            i++;
        }
        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Solution s;
    cout<<s.intToRoman(9);
    return 0;
}
