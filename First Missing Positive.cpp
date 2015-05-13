#include <iostream>
#include <limits>
#include <limits.h>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> flag;
        flag.resize(nums.size() + 1);

        if (nums.size() == 0)
        {
            return 1;
        }
        int i = 1;
        for (int i = 0;i < flag.size();i++)
        {
            flag[i] = false;
        }

        for (int i = 0;i < nums.size();i++)
        {
            if ((nums[i] > 0) && (nums[i] <= nums.size()))
                flag[nums[i]] = true;
        }

        for (i = 1;i < flag.size();i++)
        {
            if (!flag[i])
                return i;
        }

        return i;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
