// c++
#include <bits/stdc++.h>
using namespace std;

const int N = 9;

bool isValid(vector<vector<int>>& vt,int row, int col, int num){
    for(int i = 0; i < 9; i++){
        if(vt[row][i] == num) return false;
    }
    for(int i = 0 ; i < 9; i++){
        if(vt[i][col]==num) return false;
    }
    int startRow = row - row%3;
    int startCol = col - col%3;
    for(int i = 0 ; i < 3; i++){
        for( int j = 0; j < 3; j++){
            if(vt[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

int countSolutions(vector<vector<int>>& vt, int row, int col){
    if(row == N-1 && col == N) return 1;
    if(col == N){
        row++;
        col = 0;
    }
    int cnt = 0;

    if(vt[row][col] != 0) return countSolutions(vt,row,col+1);

    for(int num = 1; num <= 9; num++){
        if(isValid(vt,row,col,num)){
            vt[row][col] = num;
            cnt += countSolutions(vt,row,col+1);
            vt[row][col] = 0;
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> vt(N,vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> vt[i][j];
        }
    }
    cout << countSolutions(vt,0,0) << endl;
    return 0;
}
