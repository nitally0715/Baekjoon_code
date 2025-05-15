//B.J #14940_다익스트라_Dijkstra 
#include <iostream>
#include <queue>
#include <utility> // std::pair 
using namespace std;

static bool visited[1001][1001] = {false};  //class안에 local로 초기화하면 stack의 스택한계가 8MB이기에 무리가 갈 걸 생각해서 
static int map[1001][1001];                 //global에 전역, static으로 선언해주면 segment fault 방지할 수 있음 
static int solution_map[1001][1001];

class Shortest_Distance{
private:
    int N, M;
    int x_point, y_point;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};

public:
    Shortest_Distance(int n, int m): N(n), M(m){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> map[i][j];
                if(map[i][j] == 2){    //Destination_Coordinate
                    x_point = j;
                    y_point = i;
                }
            }
        }
    }

    void Searching_Distance(int x, int y){ //BFS
        queue<pair<int,int>> q; // 두 개의 값으로 묶어서 2차원 좌표용 
        q.push({y,x});
        visited[y][x] = true;
        solution_map[y_point][x_point] = 0; 

        while(!q.empty()){
            auto q_coordinate = q.front();  //q에 넣어두고 그 기준으로 거리를 재기 때문에 
            q.pop();                        //DFS랑 달리 가로 세로 모든 칸이 같은 거리를 가짐 1 1 1 1 이렇게 
            int qx = q_coordinate.second;   //DFS는 한방향으로만 1더해져서 돌아갈 수 있음 
            int qy = q_coordinate.first;

            for(int i=0; i<4; i++){
                int cur_x = qx + dx[i];
                int cur_y = qy + dy[i];

                if( (cur_y < 0) || (cur_y >= N) || (cur_x < 0) || (cur_x >= M) ) { continue; }
                else if( !visited[cur_y][cur_x] && (map[cur_y][cur_x] == 1) ){
                        visited[cur_y][cur_x] = true;
                        solution_map[cur_y][cur_x] = solution_map[qy][qx] + 1;
                        q.push({cur_y, cur_x});
                }
            }
        }
    }

    void get_solution_map(){

        Searching_Distance(x_point, y_point);
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j] == 0)          cout << 0 << ' '; 
                else if(!visited[i][j])     cout << -1 << ' ';
                else                        cout << solution_map[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Shortest_Distance MyMap(N, M);
    MyMap.get_solution_map();

    return 0;
}