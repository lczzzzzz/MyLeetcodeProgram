#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>



using namespace std;


class Solution {
    typedef unordered_map<string,int>::iterator PosIt;
    unordered_map<string,int> posMap;
    unordered_map<string,int> posMapInuse;
public:
    vector<int> findSubstring(string S, vector<string> &L) {

        vector<int> re;
        re.clear();
        if ((S.size() == 0) || (L.size() == 0) || (L[0].size() == 0))
            return re;
        for (int i = 0;i < L.size();i++)
        {
            /*PosIt it = posMap.find(L[i]);
            if (it == posMap.end())
            {
                posMap.insert(pair<string,int>(L[i],1));
            }
            else
            {
                it -> second++;
            }*/

            posMap[L[i]]++;
        }

        int segmentSize = L[0].size();
        int searchLenth = S.size() - L.size() * L[0].size();
        for (int i = 0;i <= searchLenth;i++)
        {
            int nowPos = i;
            int nowNum = 0;
            posMapInuse.clear();
            while (nowNum <= L.size())
            {
                PosIt it = posMap.find(S.substr(nowPos,segmentSize));
                if (it == posMap.end())
                    break;
                else if (posMapInuse[it -> first] > it -> second)
                {
                    break;
                }
                else
                {
                    posMapInuse[it -> first]++;
                    nowNum++;
                    nowPos += segmentSize;
                }
            }

            if (nowNum == L.size())
            {
                re.push_back(i);
            }
        }
        return re;
    }
};


int main()
{
    Solution s;
    string S = "a";
    vector<string> L = {"a","b"};
    cout << "Hello world!" << endl;
    vector<int> result = s.findSubstring(S,L);
    for (int i = 0;i < result.size();i++)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}
