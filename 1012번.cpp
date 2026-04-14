#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
bool visited[50][50];

void dfs_checker(vector<vector<int>> &arr, int x, int y, int maxX, int maxY){
    int nx[4] = {0, 1, 0, -1};
    int ny[4] = {1, 0, -1, 0};
    for(int i=0; i<4; i++){
        int nextX = x + nx[i];
        int nextY = y + ny[i];
        if(nextX >= 0 && nextX < maxX && nextY >= 0 && nextY < maxY && arr[nextX][nextY] == 1 && !visited[nextX][nextY]){
            visited[nextX][nextY] = true;
            dfs_checker(arr, nextX, nextY, maxX, maxY);
        }
    }
}
int dfs(vector<vector<int>> &arr, int x, int y){
    int cnt = 0;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(arr[i][j] == 1 && !visited[i][j]){
                visited[i][j] = true;
                dfs_checker(arr, i, j, x, y);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T, M, N, K, X, Y;
    cin>>T;
    vector<int> result(T);
    for(int i=0; i<T; i++){
        memset(visited, false, sizeof(visited));
        cin>>M>>N>>K;
        vector<vector<int>> arr(M, vector<int>(N, 0));
        for(int j=0; j<K; j++){
            cin>>X>>Y;
            arr[X][Y] = 1;
        }
        result[i] = dfs(arr, M, N);
    }
    for(int i=0; i<T; i++){
        cout<<result[i]<<"\n";
    }
    return 0;
};
