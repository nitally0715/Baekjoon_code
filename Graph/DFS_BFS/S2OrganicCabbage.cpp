//B.J #1012
#include <iostream>
using namespace std;

class Cabbage_Patch {
private:
    int T;
    int M, N, K;
    int x, y;
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    int patch[50][50];

public:
    Cabbage_Patch() {
        cin >> T;               //Test_case
        for(int i=0; i<T; i++){
            cin >> M >> N >> K;     //width, length, count
            initialize(M,N);
            for(int j=0; j<K; j++){
                cin >> x >> y;
                patch[x][y] = 1;
            }
            cout << solve() << "\n";
        }
    }

    void initialize(int M, int N){
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                patch[i][j] = 0;
    }

    void dfs(int x, int y){
        patch[x][y] = 0;
        for(int i=0; i<4; i++){
            int x2 = x + dx[i];
            int y2 = y + dy[i];
            if(x2 < 0 || y2 < 0 || x2 >= M || y2 >= N){ continue; }
            else if(patch[x2][y2] == 1){
                dfs(x2, y2);
            }
        }
    }

    int solve(){
        int count = 0;
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(patch[i][j] == 1){
                    count++;
                    dfs(i, j);
                }
            }
        }
        return count;
    }
};


int main(){
    Cabbage_Patch MyPatch;
    return 0;
}