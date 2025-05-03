//B.J #5525 KMF 알고리즘 
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, N, M;
    cin >> N >> M;

    string S;
    cin >> S;

    int count=0;
    int pattern=0;
    for(int i=1; i<M-1; i++){
        if(S[i-1]=='I' && S[i]=='O' && S[i+1]=='I'){
            pattern++;
            i++;
        
            if(pattern == N){
                count++;
                pattern--;
            }
        }
        else { pattern=0; }
    }

    cout << count;
    return 0;
}