//B.J #1427
#include <iostream> 
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string num;
    cin >> num;
    sort(num.begin(), num.end(), greater<char>());
    cout << num;

    return 0;
}

