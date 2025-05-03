//B.J #1874
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main(){
    int n, num;
    cin >> n;

    stack<int> Stack;
    vector<char> cal;
    
    int point=1;
    for(int i=0; i<n; i++){
        int target;
        cin >> target;

        while(point <= target){
            cal.push_back('+');
            Stack.push(point++);
        } 

        if(!Stack.empty() && Stack.top() == target){
            cal.push_back('-');
            Stack.pop();
        }
        else{
            cout << "NO";
            return 0;
        }
 
    }

    for(char op : cal){
        cout << op << "\n";
    }

    return 0;
    }
