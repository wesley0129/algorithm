#include <iostream>
#include <vector>
using namespace std;

//0은 B, 1은 W를 의미 
vector<vector<int>> matrix1 = {{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0}};
vector<vector<int>> matrix2 = {{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1}};

int check(int x, int y, vector<vector<int>> &arr){
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(arr[x+i][y+j] != matrix1[i][j]) cnt1++;
            if(arr[x+i][y+j] != matrix2[i][j]) cnt2++;
        }
    }
    if(cnt1 > cnt2) return cnt2;
    else return cnt1; 
}

int main() {
    int N, M;
    cin>>N>>M;
    int result = 64;
    //0은 B, 1은 W를 의미 
    vector<vector<int>> arr(N, vector<int>(M));
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char tmp;
            cin>>tmp;
            if(tmp=='B') arr[i][j]=0;
            else arr[i][j]=1;
        }
    }
    
    for(int a=0; a<N-7; a++){
        for(int b=0; b<M-7; b++){
            int tmp = check(a, b, arr);
            if(tmp < result) result = tmp;
        }    
    }
    cout<<result;
    return 0;
}