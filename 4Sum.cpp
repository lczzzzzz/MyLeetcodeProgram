#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if (num.size() < 4)
            return result;
        sort(num.begin(),num.end(),cmp);
        for (int i = 0;i < num.size() - 3;i++)
        {
            if ((i > 0) && (num[i - 1] == num[i]))
                continue;
            for (int j =  i + 1;j < num.size() - 2;j++)
            {
                if  ((j  > i + 1) && (num[j - 1] == num[j]))
                    continue;
                int q,p,temp;
                q = j + 1;
                p = num.size() - 1;
                while (q < p)
                {
                    temp = num[i] + num[j] + num[q] + num[p];
                    if (temp > target)
                    {
                        p--;
                    }
                    else if (temp < target)
                    {
                        q++;
                    }
                    else
                    {
                         vector <int> tempResult;
                         tempResult.push_back(num[i]);
                         tempResult.push_back(num[j]);
                         tempResult.push_back(num[q]);
                         tempResult.push_back(num[p]);
                         if (!testDuli(tempResult,result))
                         {
                            result.push_back(tempResult);
                         }
                         p--;
                    }
                }
            }
        }

            return result;

    }

    static bool cmp(int a,int b)
    {
        return a < b;
    }

    bool testDuli(vector<int> &temp,vector<vector<int> > &result)
    {
        if (result.size() > 0)
        {
            for (int i = 0;i < 4;i++)
            {
                if (result[result.size() - 1][i] != temp[i])
                    return false;
            }
            return true;
        }
        return false;
    }

};

int main()
{
    Solution s;
    vector<int> num = {5,5,3,5,1,-5,1,-2};
    vector<vector<int> > result = s.fourSum(num,0);
    cout<<result.size()<<endl;
    for (int i = 0;i < result.size();i++)
    {
        for (int j = 0;j < 4;j++)
        {
            cout<< result[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
