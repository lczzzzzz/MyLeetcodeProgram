#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<vector<int> > result;
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<int> now;
        vector<int> times;
        sort(candidates.begin(),candidates.end());

        int p = 0;
        times.push_back(1);
        for (int i = 1;i < candidates.size();i++)
        {
            if (candidates[p] == candidates[i])
            {
                times[times.size() - 1]++;
            }
            else
            {
                p++;
                candidates[p] = candidates[i];
                times.push_back(1);
            }
        }

        candidates.resize(p + 1);
        DFS(candidates,now,0,target,0,times,0);
        return result;

    }

    void DFS(vector<int> &candidates,vector<int> now,int sum,int target,int k,vector<int> times,int n)
    {
        if (n >= times[k])
            return;
        if (sum > target)
            return;
        else if (sum == target)
        {
            if (result[result.size() - 1] != now)
                result.push_back(now);
            return;
        }
        else
        {
            for (int i = k;i < candidates.size();i++)
            {
                now.push_back(candidates[i]);
                if (i == k)
                    DFS(candidates,now,sum + candidates[i],target,i,times,n + 1);
                else
                    DFS(candidates,now,sum + candidates[i],target,i,times,0);
                now.pop_back();
                if (sum + candidates[i] > target)
                    return;
            }
        }
    }
};



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
