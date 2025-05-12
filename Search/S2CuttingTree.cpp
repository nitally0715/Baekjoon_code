//B.J #2805_매개변수탐색_이분탐색
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> tree(N);

    for(int i=0; i<N; i++){
        cin >> tree[i];
    }

    int left = 0;
    int right = *max_element(tree.begin(), tree.end());
    int result = 0;
    while(left <= right){
        int mid = (left + right)/2;
        long long sum = 0;
        for( int H : tree ){
            if( H > mid ) {
                sum += H-mid;
            }
        }

        if( sum >= M) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << result;
    return 0;
}

