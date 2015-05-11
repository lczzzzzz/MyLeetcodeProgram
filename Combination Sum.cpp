class Solution {
    vector<vector<int> > result;
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> now;
        sort(candidates.begin(),candidates.end());
        DFS(candidates,now,0,target,0);
        return result;
        
    }

    void DFS(vector<int> &candidates,vector<int> now,int sum,int target,int k)
    {
        if (sum > target)
            return;
        else if (sum == target)
        {
            result.push_back(now);
            return;
        }
        else
        {
            for (int i = k;i < candidates.size();i++)
            {
                now.push_back(candidates[i]);
                DFS(candidates,now,sum + candidates[i],target,i);
                now.pop_back();
                if (sum + candidates[i] > target)
                    return;
            }
        }
    }
};