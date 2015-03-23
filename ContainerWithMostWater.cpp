#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size();
        int maxContainer = 0;
        while (j > i)
        {
            maxContainer = max(maxContainer,(j - i) * (height[i] < height[j]?height[i]:height[j]));
            height[i] < height[j]?i++:j--;
        }
        return maxContainer;
    }
};


int main()
{
    vector<int> t;
    /*for (int i = 15000;i >= 0;i--)
    {
        t.push_back(i);
    }*/
    t.push_back(1);
    t.push_back(2);
    t.push_back(4);
    t.push_back(3);
    Solution s;
    cout<<s.maxArea(t);

    cout << "Hello world!" << endl;
    return 0;
}
