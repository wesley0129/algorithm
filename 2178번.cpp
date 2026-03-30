#include <iostream>
#include <map>
#include <queue>
using namespace std;
//map버전
int bfs(map<pair<int,int>,int>& maze, int n, int m){
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        auto [a, b] = q.front();
        auto dist = maze[{a, b}];
        // if((a==n-2 && b==m-1) || (a==n-1 && b==m-2)){
        //     return ++dist;
        // }
        if(a==n-1 && b==m-1) return dist;
        q.pop();
        for(int i=0; i<4; i++){
            if(a+x[i] < n && b+y[i] < m && a+x[i]>=0 && b+y[i]>=0 && maze[{a+x[i], b+y[i]}]==1){
                maze[{a+x[i], b+y[i]}]+=dist;
                q.push({a+x[i], b+y[i]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    map<pair<int,int>, int> maze;
    for(int i=0; i<n; i++){
        string tmp;
        cin>>tmp;
        for(int j=0; j<m; j++){
            maze[{i, j}] = tmp[j]-'0';
        }
    }
    cout<<bfs(maze, n, m)<<"\n";
    return 0;
}   

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//vector버전
int bfs(vector<vector<int>>& maze, int n, int m){
    int x[4] = {-1, 0, 1, 0};
    int y[4] = {0, 1, 0, -1};
    queue<pair<int,int>> q;
    
    q.push({0,0});
    
    while(!q.empty()){
        auto [a, b] = q.front();
        int dist = maze[a][b];
        
        if(a == n-1 && b == m-1) return dist;
        
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = a + x[i];
            int ny = b + y[i];
            
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && maze[nx][ny] == 1){
                maze[nx][ny] += dist;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> maze(n, vector<int>(m));
    
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        for(int j=0; j<m; j++){
            maze[i][j] = tmp[j] - '0';
        }
    }
    
    cout << bfs(maze, n, m) << "\n";
    
    return 0;
}