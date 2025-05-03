//B.J #1436
#include <iostream>
using namespace std;

int check(int num);


//666이 들어간 숫자를 작은 것 부터 순서대로 해서 N번째 찾기
//이런문제는 브루트 포스(Brute Force)는 "무식하게 전부 다 해보는" 방식을 이용!
//N이 10000이하라는 조건이 있으니 시간 복잡도 그리 높지않음 대신 최소화는 할 것.
int main(){
    int N, ans;
    cin >> N;

    if(N==1){
        cout << 666;
    } 
    else{
        int n = 1;
        ans = 1666;
        while(1){
            if(check(ans)){
                n++;
            } 
            if(n==N){
                cout << ans;
                break;
            }
            ans++;
            }
        }

    return 0;
}

int check(int num){
    if(num%1000 == 666 || (num%10000)/10 == 666 || (num%100000)/100 == 666 || (num%1000000)/1000 == 666 || (num%10000000)/10000 == 666){
        return 1;
    }
    else{
        return 0;
    }
}