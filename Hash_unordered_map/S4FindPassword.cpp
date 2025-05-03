#include <iostream>
#include <string>
#include <unordered_map> //해시를 사용한 집합과 맵

using namespace std;

int main(){
    int N, M;
    string site, pass, find_site;
    cin >> N >> M;
    unordered_map<string, string> memo;

    for(int i=0; i<N; i++){
        cin >> site >> pass;
        memo[site] = pass;
    }
    
    for(int i=0; i<M; i++){
        cin >> find_site;
        cout << memo[find_site] << endl;
    }

    return 0;
}