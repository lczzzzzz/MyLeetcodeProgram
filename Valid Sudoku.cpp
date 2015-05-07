#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0;i < 9;i++)
        {
            bool flagC[10];
            bool flagR[10];
            for (int k = 0;k < 10;k++)
            {
                flagC[k] = false;
                flagR[k] = false;
            }
            for (int j = 0;j < 9;j++)
            {
                if (board[i][j] != '.')
                {
                    if (!flagC[board[i][j] - '0'])
                    {
                        flagC[board[i][j] - '0'] = true;
                    }
                    else
                    {
                        return false;
                    }
                }

                if (board[j][i] != '.')
                {
                    if (!flagR[board[j][i] - '0'])
                    {
                        flagR[board[j][i] - '0'] = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        for (int i = 0;i < 7;i += 3)
            for (int j = 0;j < 7;j += 3)
            {
                if (!testSquare(i,j,board))
                    return false;
            }

        return true;
    }

    bool testSquare(int a,int b,vector<vector<char> > &board)
    {
        bool flag[10];
        for (int i = 0;i < 10;i++)
        {
            flag[i] = false;
        }

        for (int i = a;i < a + 3;i++)
            for (int j = b;j < b + 3;j++)
            {
                if (board[i][j] != '.')
                {
                    if (!flag[board[i][j] - '0'])
                    {
                        flag[board[i][j] - '0'] = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }

            return true;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
