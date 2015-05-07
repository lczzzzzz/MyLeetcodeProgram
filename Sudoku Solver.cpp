#include <iostream>
#include <vector>

using namespace std;


class Solution {
    bool cFlag[10][10];
    bool rFlag[10][10];
    bool squareFlag[10][10];
    bool find = false;
public:
    void solveSudoku(vector<vector<char> > &board) {

        for (int i = 0;i < 9;i++)
            for (int j = 0;j < 10;j++)
            {
                cFlag[i][j] = false;
                rFlag[i][j] = false;
                squareFlag[i][j] = false;
            }

        for (int i = 0;i < 9;i++)
            for (int j = 0;j < 9;j++)
            {
                if (board[i][j] != '.')
                {
                    setFlag(i,j,board[i][j] - '0');
                }
            }

        DFS(board,0,0);
    }

    void DFS(vector<vector<char> > &board,int i,int j)
    {
            if (i >= 9)
            {
                find = true;
                return;
            }
            if (board[i][j] == '.')
            {
                for (int q = 1;q <= 9;q++)
                {
                    if ((!testDulip(i,j,q)) && (!find))
                    {
                        setFlag(i,j,q);
                        board[i][j] = '0' + q;

                        if (j == 8)
                            DFS(board,i + 1,0);
                        else
                            DFS(board,i,j + 1);

                        if (!find)
                        {
                           board[i][j] = '.';
                           rmFlag(i,j,q);
                        }
                        else
                        {
                            return;
                        }
                    }
                }
            }
            else
            {
                    if (j == 8)
                        DFS(board,i + 1,0);
                    else
                        DFS(board,i,j + 1);
            }
    }

    bool testDulip(int i,int j,int k)
    {
        if (cFlag[i][k])
            return true;
        if (rFlag[j][k])
            return true;

        int n = (i / 3) * 3 + j / 3;
        if (squareFlag[n][k])
            return true;
        return false;
    }
    void setFlag(int i,int j,int k)
    {
        cFlag[i][k] = true;
        rFlag[j][k] = true;
        int n = (i / 3) * 3 + j / 3;
        squareFlag[n][k] = true;
        //cout<<i<<" "<<j<<" "<<k<<" "<<find<<endl;
    }

    void rmFlag(int i,int j,int k)
    {
        cFlag[i][k] = false;
        rFlag[j][k] = false;
        int n = (i / 3) * 3 + j / 3;
        squareFlag[n][k] = false;
    }

    void coutBoard(vector<vector<char> > &board)
    {
        //cout<<board.size();
        for (int i = 0;i < 9;i++)
        {
            for (int j = 0;j < 9;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<endl;
    }
};


int main()
{

    vector<vector<char> > board;
    board.resize(9);
    //cout<<board.size();
    string sboard[] = {"379....14",".6..1..7.",".8...9..5","435..7...",".9..4..2.","...8..436","9..7...8.",".4..8..5.","85....249"};
    //cout<<endl<<sboard[0].size();

    for (int i = 0;i < 9;i++)
        for (int j = 0;j < 9;j++)
    {
        board[i].push_back(sboard[i][j]);
    }

    //board.size();
    Solution s;
    s.solveSudoku(board);

    s.coutBoard(board);


    return 0;
}
