#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sstream>
#include <math.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        string sDividend;
        char temp[20];
        sprintf(temp,"%d",dividend);
        sDividend = temp;
        string sDivisor;
        sprintf(temp,"%d",divisor);
        sDivisor = temp;

        if (divisor == 0)
        {
            return INT_MAX;
        }

        string result;

        if ((sDividend[0] == '-') && (sDivisor[0] != '-'))
        {
            result.push_back('-');
            sDividend.erase(0,1);
        }

        if ((sDividend[0] != '-') && (sDivisor[0] == '-'))
        {
            result.push_back('-');
            sDivisor.erase(0,1);
        }

       if ((sDividend[0] == '-') && (sDivisor[0] == '-'))
       {
           sDivisor.erase(0,1);
           sDividend.erase(0,1);
       }
        istringstream divisorInt(sDivisor);
        long long ldivisor;
        divisorInt>>ldivisor;

        istringstream dividendInt(sDividend);
        long long ldividend;
        dividendInt >> ldividend;

        if (ldivisor > ldividend)
        {
            return 0;
        }

         int mod = 0;
         int re = 0;
        for (int i = 0;i < sDividend.size();i++)
        {
            long long  tempmod;
            tempmod = 0;
            for (int j = 0;j < 10;j++)
            {
                tempmod += mod;
            }

            divd(sDividend[i] - '0' + tempmod,ldivisor,re,mod);
            result.push_back(re + '0');
        }

        istringstream issInt(result);
        int resultInt;
        issInt >> resultInt;
        return resultInt;
    }

    void divd(long long  a,int b,int &c,int &d)
    {
        int i = 0;
        long long tempb = 0;
        while (tempb <= a)
        {
            tempb += b;
            i++;
        }

        c = i - 1;
        d = a - tempb + b;
    }
};



int main()
{
    cout << "Hello world!" << endl;
    Solution s;
    cout<<s.divide(-2147483648,-1017100424);
    return 0;
}
