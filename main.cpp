#include <bits/stdc++.h>

#define vi vector<int>

using namespace std;

vector<vi> board(10,vi(10)), row(10,vi(10)), col(10,vi(10)), box(10,vi(10));

int solve(int i, int j)
{
    if (i>9)
        return 1;
    if (j>9)
        return solve(i+1, 1);
    if (board[i][j])
        return solve(i, j+1);
    int num, box_no=((i-1)/3)*3+(j-1)/3+1;
    for (num=1; num<=9; num++)
        if ((row[i][num] | col[j][num] | box[box_no][num])==0)
        {
            row[i][num]=col[j][num]=box[box_no][num]=1;
            board[i][j]=num;
            if (solve(i, j+1))
                return 1;
            row[i][num]=col[j][num]=box[box_no][num]=0;
            board[i][j]=0;
        }
    return 0;
}

void format_output()
{
    for (int i=1; i<=9; i++)
    {
        for (int j=1; j<=9; j++)
        {
            cout<<board[i][j]<<" \n"[j==9];
            if (j==3 || j==6)
                cout<<"| ";
        }
        if (i==3 || i==6)
            cout<<"---------------------\n";
    }
}

int main()
{
    int i, j, box_no, num, unsolvable=0;
    for (i=1; i<=9; i++)
        for (j=1; j<=9; j++)
        {
            cin>>board[i][j];
            num=board[i][j];
            box_no=((i-1)/3)*3+(j-1)/3+1;
            if (num && (row[i][num] | col[j][num] | box[box_no][num])!=0 )
                unsolvable=1;
            row[i][board[i][j]]=col[j][board[i][j]]=box[box_no][board[i][j]]=1;
        }
    cout<<'\n';
    if (unsolvable || solve(1,1)==0)
        cout<<"Not solvable!";
    else
        format_output();
    cout<<'\n';
}
