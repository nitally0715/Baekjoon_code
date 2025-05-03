//B.J #1654
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> vec;

int main(){
    int N, K, cm; //단위 cm, 정수
    long long max_length=0;
    cin >> K >> N;

    for(int i=1; i<=K; i++){
        cin >> cm;
        vec.push_back(cm); //K값들 배열에 일단 저장
        max_length = max(max_length, (long long)cm); // 가장 긴 랜선 저장
    }


    //이진 탐색[Binary Search]
    //-오버플로우 걱정 x,  시간 복잡도 O(K log max_length)로 매우 빠름
    int left=1, right = max_length, answer=0;
    while(left <= right){
        int mid = (left + right) / 2; // 기준값(중앙값)
        int count=0;

        for(int i=0; i<K; i++){ 
            count += vec[i] / mid; // mid 길이로 몇 개의 랜선 만들 수 있는지 계산
        }
        
        if(count >= N){
            answer = mid; //정답후보
            left = mid + 1; // 기준값에서 우측 탐색
        } else{
            right = mid - 1; // 기준값에서 좌측 탐색
        }
    }

    cout << answer;
    return 0;
}