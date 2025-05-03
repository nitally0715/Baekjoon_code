//B.J #18870
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, x;
    vector<int> X;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x;
        X.push_back(x);
    }

    vector<int> X_set = X;
    sort(X_set.begin(), X_set.end());
    auto last = unique(X_set.begin(), X_set.end());
    X_set.erase(last, X_set.end());

    for(int i=0; i<N; i++){
        //lower_bound: first,last에서 X[i]가 처음 나오는 위치의 iterator 반환 X_set.begin() + n => n을 원하는 것이기에 X_set.begin() 빼주기 
        // 추가로 그냥 find 말고 lower_bound 쓰는 이유: 이진 탐색 기반이라 빠름 시간 복잡도 O(log n)
        int count = lower_bound(X_set.begin(), X_set.end(), X[i]) - X_set.begin();
        cout << count << " ";
    }

    return 0;
}
