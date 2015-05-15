#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> rockStack;
        int totalRock = 0;
        int re = 0;

        if (height.size() == 0)
            return re;

        while (height[0] == 0)
        {
            height.erase(height.begin());
        }

        if (height.size() == 0)
            return re;

        rockStack.push_back(0);
        for (int i = 1;i < height.size();i++)
        {
            if ((height[i] < height[rockStack[rockStack.size() - 1]]) || (height[i] == 0))
            {
                rockStack.push_back(i);
            }
            else
            {
                int temp = i;
                while ((rockStack.size() != 0)&&(height[rockStack[rockStack.size() - 1]] < height[i]))
                {
                    temp = rockStack[rockStack.size() - 1];
                    rockStack.pop_back();
                    totalRock += height[temp];
                }

                if (rockStack.size() == 0)
                {
                    re += (i - temp - 1) * height[temp] - totalRock + height[temp];
                    totalRock = 0;
                    rockStack.push_back(i);
                }
                else
                {
                     re += (i  - temp) * height[i] - totalRock;
                     totalRock = 0;

                     for (int j = temp;j <= i;j++)
                     {
                         rockStack.push_back(j);
                         height[j] = height[i];
                     }

                     for (int i = 0;i < height.size();i++)
                     {
                         cout<<height[i]<<" ";
                     }

                     cout<<endl;
                }
            }
        }

        return re;
    }
};


int main()
{
    Solution s;
    vector<int> height = {0};
    cout<<s.trap(height);
    cout << "Hello world!" << endl;
    return 0;
}
