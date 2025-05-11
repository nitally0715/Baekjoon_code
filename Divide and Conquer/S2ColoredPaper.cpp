//B.J #2630
#include <iostream>
#include <vector>
using namespace std;

class colored_paper{
private:
    int N;
    int color;
    int white_count = 0;
    int blue_count = 0;
    vector<vector<int>> paper;
public:
    colored_paper(int n): N(n), paper(n, vector<int>(n)) {
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> color;
                paper[i][j] = color;
            }
        }
    }

    void get_answer(){
        cout << white_count << "\n" << blue_count;
    }

    void Divide_and_Conquer(int x, int y, int n) {
        bool ok = true;
        int pre_color = paper[x][y];
        for(int i=x; i<x+n; i++){
            for(int j=y; j<y+n; j++){
                if( paper[i][j] != pre_color ){
                    ok = false;
                    Divide_and_Conquer(x, y, n/2);
                    Divide_and_Conquer((x+n/2), y, n/2);
                    Divide_and_Conquer(x, (y+n/2), n/2);
                    Divide_and_Conquer((x+n/2), (y+n/2), n/2);
                    return ;
                }
            }
        }

        if(ok){
            if(pre_color){
                blue_count++;
            }
            else {
                white_count++;
            }
        }
    }
};

int main(){
    int N;
    cin >> N;
    
    colored_paper myPaper(N);
    myPaper.Divide_and_Conquer(0, 0, N);
    myPaper.get_answer();

    return 0;
}