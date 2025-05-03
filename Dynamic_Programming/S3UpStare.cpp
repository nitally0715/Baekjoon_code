//B.J #2579
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int n = N+1;
    int dp[n];       
    int score_board[n];
    score_board[0] = 0;
    for(int i=1; i<n; i++) {
        cin >> score_board[i];
    }
    // 0,1,2,3,5,8,13
    dp[0] = 0;
    dp[1] = score_board[1];
    dp[2] = score_board[2] + dp[1];
    
    for(int i=3; i<n; i++){
        int jump = score_board[i] + dp[i-2];                          
        int non_jump = score_board[i] + score_board[i-1] + dp[i-3]; 
        dp[i] = max(jump, non_jump);
    }

    cout << dp[n-1];
    return 0;
}