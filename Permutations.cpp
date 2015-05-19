#include <iostream>
#include <vector>

using namespace std;


class Solution {
    vector<vector<int> > result;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flag(nums.size(),false);
        vector<int> re(0);
        DFS(nums,flag,re);
        return result;
    }

    void DFS(vector<int> &nums,vector<bool> flag,vector<int> re)
    {
        if (re.size() == nums.size())
        {
            result.push_back(re);
        }
        else
        {
            for (int i = 0;i < flag.size();i++)
            {
                if (!flag[i])
                {
                    flag[i] = true;
                    re.push_back(nums[i]);
                    DFS(nums,flag,re);
                    flag[i] = false;
                    re.pop_back();
                }
            }
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int> > result = s.permute(nums);
    for (int i = 0;i < result.size();i++)
    {
        for (int j = 0;j < result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
