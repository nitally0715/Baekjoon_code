#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) { 
        int N, M, val, count = 0;
        cin >> N >> M;

        queue<pair<int, int>> que; //pair 이용해서 que.front().first 이런 식으로 접근 가능 <중요도(값), 초기순서>로 저장장
        priority_queue<int> pq; //Priority_Queue: 값들의 중요도 순으로 자동정렬 해주는 queue/ greater<int>를 이용하면 최소 힙순으로 정렬

        for (int j = 0; j < N; j++) {
            cin >> val;
            que.push({val, j});  // 큐에 (문서의 중요도, 원래 순서) 저장
            pq.push(val);  // 우선순위 큐에 중요도만 저장
        }

        while (!que.empty()) {

            int front_val = que.front().first;
            int front_idx = que.front().second;
            //맨 앞의 값이 가장 중요하고/ id(초기 순서)의 값도 같으면 출력
            if (front_val == pq.top()) {
                que.pop();  
                pq.pop();   
                count++;   

                //지금 가장 중요하지만 id가 다르면 제거만/ 같으면 출력
                if (front_idx == M) {
                    cout << count << endl;
                    break; 
                }
            } else {
                que.push(que.front());
                que.pop();
            }
        }
    }

    return 0;
}
