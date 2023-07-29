/*
N-Queen Problem

You are given 'N', and for a given 'N x N' chessboard. Find a configuration of 'N' queens such that no queen can attack any other queen on the chess board.


A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to return all such configurations.


Note:
If no such configuration is present return an empty array, it will be represented as 'No Configuration' in the output.
For Example:
For a chessboard of size 4*4
The configurations are 
alt text

Input Format:
The first line of input contains an integer, that denotes the value of N.     
Output Format :
In the output, every board configuration is printed in a new line. 

Every configuration will have 'N*N' board elements printed row wise and are separated by space. 

The cells where queens are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0. 
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
Explanation:
The first and second configuration are shown in the image above in example.
Sample Input 2:
3
Sample Output 2 :
'No Configuration'
Constraints :
1 <= N <= 10
Time Limit: 1 second

*/
#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


vector<int> col;
vector<bool> leftDiag;
vector<bool> rightDiag; 
vector<vector<int>> ans;

void recurBoard (int row, int n)
{
    for (int i=0;i<n;i++){
        if(leftDiag[row+i] || rightDiag[i-row+n-1] || col[i]!=-1) continue;
        col[i]=row;
        leftDiag[row+i]=true;
        rightDiag[i-row+n-1]=true;
        if (row+1==n){
            vector<int> temp;
            for (int j=0;j<n;j++){
                for (int k = 0; k < n; k++) {
                    temp.push_back(col[k] == j);
                }
            }
            ans.push_back(temp);
        }
        else {
            recurBoard(row + 1, n);
        }
        col[i] = -1;
        leftDiag[row + i] = false;
        rightDiag[i - row + n - 1] = false;
    }
}


vector<vector<int>> nQueens(int n)

    {
    col = vector<int>(n, -1);
leftDiag = vector<bool>(2 * n + 1, false);
rightDiag = vector<bool>(2 * n + 1, false);

recurBoard(0, n);

return ans;
}



class Runner
{
    int n;

public:
    
    void takeInput()
    {
        cin >> n;
    }
    void execute()
    {
        auto ans = nQueens(n);
    }
    void executeAndPrintOutput()
    {
        auto ans = nQueens(n);
        if(ans.size())
        {
            sort(ans.begin(),ans.end());
            for(auto v:ans)
            {
                for(auto i:v)cout << i << " ";
                cout << endl;
            }
        }
        else cout << "\'No Configuration\'";
    }
};

int main()
{
        Runner runner;
        runner.takeInput();
        runner.executeAndPrintOutput();   
    return 0;
    
}