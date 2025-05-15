//B.J #11403_플로이드 와샬 알고리즘_ 모든 경로 다 찾기 3중 for문 
#include <iostream>
#include <vector>
using namespace std;

class Find_Course {
private:
    int N, node;
    vector<int> graph[100];

public:
    Find_Course(int n): N(n){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> node;
                graph[i].push_back(node);
            }
        }
    }

    void Floyd_Warshall(){
        // k = 거쳐가는 정점(node)
        // i = 출발 정점
        // j = 도착 정점
        for(int k=0; k<N; k++){
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(graph[i][k] && graph[k][j]) {
                        graph[i][j] = 1;
                    }
                }
            }
        }
    }

    void print_course(){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << graph[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main(){
    int N;
    cin >> N;

    Find_Course my_course(N);
    my_course.Floyd_Warshall();
    my_course.print_course();

    return 0;
}