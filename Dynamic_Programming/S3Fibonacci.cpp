//B.J #1003
#include <iostream>

using namespace std;

int main(){
    int T, N;
    cin >> T;
    int dp[41][2];

    dp[0][0] = 1;
    dp[0][1] = 0;

    for(int i=1; i<41; i++){
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    }

    for(int i=0; i<T; i++){
        cin >> N;

       cout << dp[N][0] << " " << dp[N][1] << endl;
    }

    
    return 0;
}