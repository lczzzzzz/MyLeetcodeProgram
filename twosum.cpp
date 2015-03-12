#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
struct ValueAndPos
{
    int value;
    int pos;
};
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<ValueAndPos> vap;

        for (vector<int>::iterator it = numbers.begin();it != numbers.end();it++)
        {
            ValueAndPos temp;
            temp.value = *it;
            temp.pos = it - numbers.begin();
            vap.push_back(temp);
        }

        sort(vap.begin(),vap.end(),cmp);
        for (vector<ValueAndPos>::iterator itb = vap.begin();itb != vap.end();itb++)
        {
             for (vector<ValueAndPos>::iterator ite = vap.end() - 1;ite != vap.begin();ite--)
             {
                 if (itb->value + ite->value == target)
                 {
                     vector<int> results;
                     if (itb->pos > ite->pos)
                     {
                         results.push_back(ite->pos);
                         results.push_back(itb->pos);
                     }
                     else
                     {
                         results.push_back(itb->pos);
                         results.push_back(ite->pos);
                     }
                     return results;
                 }
                 else if (itb->value + ite->value < target)
                 {
                     break;
                 }
             }
        }
    }

    static bool cmp(const ValueAndPos &a,const ValueAndPos &b)
    {
        return a.value < b.value;
    }
};
int main()
{
    Solution s;
    vector<int> numbers;
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(4);
    s.twoSum(numbers,6);
    return 0;
}
