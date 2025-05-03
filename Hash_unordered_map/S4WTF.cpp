#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 

using namespace std;

int main(){
    int N, M;
    string str;
    cin >> N >> M;

    vector<string> Dont_any;
    unordered_map<string, bool> Dont_hear;
    for(int i=1; i<=N; i++){
        cin >> str;
        Dont_hear[str] = true;
    }

    for(int i=0; i<M; i++){
        cin >>  str;
        if(Dont_hear.find(str) != Dont_hear.end()){
            Dont_any.push_back(str);
        }    
    }

    sort(Dont_any.begin(), Dont_any.end());

    cout << Dont_any.size() << "\n";
    for(int i=0; i<Dont_any.size(); i++){
        cout << Dont_any[i] << "\n";
    }
    return 0;
}