//B.J #1260
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class DFS_BFS {
private:
    int N, M, V;
    bool dfs_visited[1001] = {false};
    bool bfs_visited[1001] = {false};
    vector<int> dfs_graph[1001];
    vector<int> bfs_graph[1001];

public:
    DFS_BFS(){
        cin >> N >> M >> V;

        int n1,n2;
        for(int i=0; i<M; i++){
            cin >> n1 >> n2;
            dfs_graph[n1].push_back(n2);
            bfs_graph[n1].push_back(n2);
            dfs_graph[n2].push_back(n1);
            bfs_graph[n2].push_back(n1);
        }

        for(int i=1; i<=N; ++i){
            sort(dfs_graph[i].begin(), dfs_graph[i].end());
            sort(bfs_graph[i].begin(), bfs_graph[i].end());
        }

        DFS(V);
        cout << "\n";
        BFS(V);
        cout << "\n";
    }

    void DFS(int node){ //vector를 이용한 stack 자료구조
        dfs_visited[node] = true;
        cout << node << " ";
        // 한 번 카운트한 node 안 세려고 visited로 확인 
        for(int behavior : dfs_graph[node]){
            if(!dfs_visited[behavior]){ DFS(behavior); } //재귀로 처리 
        }
    }

    void BFS(int node){ //queue를 이용
        queue<int> q;
        q.push(node);
        bfs_visited[node] = true;

        while(!q.empty()){
            int x = q.front();
            q.pop();
            cout << x << ' ';
            for(int behavior : bfs_graph[x]){
                if(!bfs_visited[behavior]){
                    q.push(behavior);
                    bfs_visited[behavior] = true; //직접 처리
                }
            }
        }
    }
};

int main() {
    DFS_BFS mySolution;
    return 0;
}