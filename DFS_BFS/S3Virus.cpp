//B.J #2606
#include <iostream>
#include <vector>

using namespace std;

class Virus{
private:
    int n, set_num, count;
    bool visited[101] = {false};
    vector<int> graph[101]; // 2-D array 

public:
    Virus() : count(0){
        cin >> n >> set_num;        

        int a,b;
        for(int i=0; i<set_num; i++){
            cin >> a >> b;
    
            graph[a].push_back(b); // 연결된 것 해당 위치를 index로 하여 
            graph[b].push_back(a);
        }
    }

    void dfs(int node ){
        visited[node] = true;
        count++;

        for(int behavior : graph[node]){
            if(!visited[behavior]){ dfs(behavior); }
        }
    }

    ~Virus(){
        cout << count-1; //처음에 1번 컴퓨터 ++ 한 거 빼주기 
    }
};

int main(){
    Virus vi;
    vi.dfs(1);

    return 0;
}