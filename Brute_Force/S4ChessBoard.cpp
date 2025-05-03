//B.J #1018
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    char ch;
    cin >> N >> M;

    vector<vector<int>> board(N, vector<int>(M, 0));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> ch;
            if(ch == 'W'){
                board[i][j] = 1;
            }
            else{ board[i][j] = 0; }
        }
    }

    int result, result1=2500;
    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            int count=0;
            for(int x=i; x<i+8; x++){
                for(int y=j; y<j+8; y++){
                    if(x%2==0 && y%2==0){
                        if(!board[x][y]){ count++; }
                    }
                    else if(x%2!=0 && y%2!=0){
                        if(!board[x][y]){ count++; }
                    }
                    else{
                        if(board[x][y]){ count++; }
                    }
                }
            }
            if(result1 > count){ result1=count; }
        }
    }

    int result2 = 2500;
    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            int count=0;
            for(int x=i; x<i+8; x++){
                for(int y=j; y<j+8; y++){
                    if(x%2==0 && y%2==0){
                        if(board[x][y]){ count++; }
                    }
                    else if(x%2!=0 && y%2!=0){
                        if(board[x][y]){ count++; }
                    }
                    else{
                        if(!board[x][y]){ count++; }
                    }
                }
            }
            if(result2 > count){ result2=count; }
        }
    }

    if(result1 < result2){ result = result1; }
    else{ result = result2; }
    cout << result;
    return 0;
}