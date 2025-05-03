//B.J #11726
#include <iostream>
using namespace std;

int main(){
    int n;
    long long dp[1001];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<1001; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }

    cin >> n;
    cout << dp[n];

    return 0;
}