#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    typedef map<int,int>::iterator mapIt;
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        map<int,int> value;
        vector<vector<int> > result;
        for (int i = 0;i <num.size();i++)
        {
            mapIt it= value.find(num[i]);
            if (it == value.end())
            {
                value.insert(pair<int,int>(num[i],1));
            }
            else
            {
                it->second++;
            }
        }
        for (mapIt it1 = value.begin();it1 != value.end();it1++)
        {
            mapIt it2;
            if (it1->second > 1)
            {
                it2 = it1;
            }
            else
            {
                it2 = it1;
                it2++;
            }
            for (it2;it2 != value.end();it2++)
            {
                int temp = it1-> first + it2 -> first;
                mapIt it3 = value.find(-1 * temp);
                if (it3 == value.end())
                    continue;
                else if ((it1 == it2) && (it3 == it2) && (it1->second < 3))
                    continue;
                else if ((it1 == it3) && (it1->second < 2))
                    continue;
                else if ((it2 == it3) && (it2->second < 2))
                    continue;
                else if (it3 -> first < it2 -> first)
                    continue;
                else
                {
                    vector<int> temp;
                    temp.push_back(it1 -> first);
                    temp.push_back(it2 -> first);
                    temp.push_back(it3 -> first);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }

};

int main()
{
    Solution s;
    //vector<int> num = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    /*num.push_back();
    num.push_back();
    num.push_back();
    num.push_back();*/
    vector<int> num = {0};
    vector<vector<int> > result = s.threeSum(num);
   for (int i = 0;i < result.size();i++)
    {
        for (int j = 0;j <result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
