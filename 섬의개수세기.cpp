#include <iostream>
#include <vector>
using namespace std;

void circuit(vector<vector<int>>& arr,int dx, int dy, int xlen, int ylen, vector<vector<int>>& check){
    int x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
    int y[8] = {0, 1, 0, -1, -1, 1, 1, -1};
    for(int i=0; i<8; i++){
        int xcd = dy+x[i];
        int ycd = dx+y[i];
        if(xcd>=0 && xcd<dy && ycd>=0 && ycd<dx && check[ycd][xcd]==0){
            check[ycd][xcd]=1;
            circuit(arr, ycd, xcd, xlen, ylen, check);
        }
    }
};

int dfs(vector<vector<int>>& arr, int xlen, int ylen){
    int count = 0;
    vector<vector<int>> check(xlen, vector<int>(ylen, 0));
    for(int i=0; i<xlen; i++){
        for(int j=0; j<ylen; j++){
            if(arr[i][j]==1 && check[i][j]==0){
                count++;
                circuit(arr, i, j, xlen, ylen, check);
            }
        }
    }

    return count;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    cin>>x>>y;
    vector<vector<int>> arr(x, vector<int>(y));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            int tmp;
            cin>>tmp;
            arr[i][j] = tmp; 
        }
    }

    cout<<dfs(arr, x, y)<<endl;
    return 0;
};
