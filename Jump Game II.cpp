#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int result = 0;
        unsigned int n = 0;
        while ((n < nums.size()) && (nums[n] + n < nums.size() - 1))
        {
            unsigned int max = nums[n];
            int maxPos = n;
            for (unsigned int i = n + 1;i <= n + nums[n];i++)
            {
                if (i + nums[i] > max)
                {
                    max = i + nums[i];
                    maxPos = i;
                }
            }

            n = maxPos;
            result++;
        }
        if ((nums.size() == 1) && (nums[0] == 0))
            return 0;
        return result + 1;
    }
};


int main()
{
    Solution s;
    vector<int> nums = {2,3,1,1,4};
    cout<<s.jump(nums);
    cout << "Hello world!" << endl;
    return 0;
}
