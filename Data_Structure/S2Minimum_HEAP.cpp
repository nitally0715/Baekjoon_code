//B.J #1927
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n, x, zero_count=0;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x==0) { 
            if(!min_heap.empty()) {
                cout << min_heap.top() << "\n";
                min_heap.pop();
            }
            else { cout << 0 << "\n"; }
        }
        else {
            min_heap.push(x);
        }
    }

    return 0;
}