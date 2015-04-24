#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        bool find = false;
        if ((num.size() == 0) || (num.size() == 1))
            return;
        int i;
        for (i = num.size() - 2;i >= 0;i--)
        {
            int min = num[i + 1];
            int k = i + 1;
            for (int j = i + 1;j < num.size();j++)
            {
                if ((num[j] > num[i]) && (min >= num[j]))
                {
                    min = num[j];
                    k =j;
                    find = true;
                }
            }

            if (find)
            {
                int temp = num[k];
                num[k] = num[i];
                num[i] = temp;
                break;
            }
        }

        sort(num.begin() + 1 + i ,num.end());
    }
};

int main()
{
    Solution s;
    vector<int> num = {1,3,2};

    s.nextPermutation(num);

    for (int i = 0;i < num.size();i++)
    {
        cout<<num[i]<<" ";
    }

    cout << "Hello world!" << endl;
    return 0;
}
