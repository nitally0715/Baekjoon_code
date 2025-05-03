#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> //특정 문자 위치 반환가능 => 시간 복잡도 훨씬 효율적적

using namespace std;

int main(){
    ios::sync_with_stdio(0); //빠른 입출력
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    vector<string> vec(N+1);
    unordered_map<string, int> umap;

    for(int i=1; i<=N; i++){
        cin >> vec[i];
        umap[vec[i]] = i;
    }

    string input;
    for(int i=0; i<M; i++){
        cin >> input;
        if(isdigit(input[0])){
            cout << vec[stoi(input)] << "\n";
        } 
        else{
            cout << umap[input] << "\n";
        }
    }

    return 0;
}