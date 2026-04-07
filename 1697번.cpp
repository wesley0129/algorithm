#include <iostream>
#include <queue>
using namespace std;

int visit[100001];

int bfs(int n, int k){
    queue<pair<int,int>> q;
    q.push({n, 0});
    visit[n] = 1;

    while(!q.empty()){
        int x = q.front().first;
        int time = q.front().second;
        q.pop();

        //도착
        if(x == k) return time;

        //3가지 이동
        int next[3] = {x - 1, x + 1, x * 2};

        for(int i = 0; i < 3; i++){
            int nx = next[i];

            // 범위 체크 및 방문 체크
            if(nx >= 0 && nx <= 100000 && visit[nx] == 0){
                visit[nx] = 1;
                q.push({nx, time + 1});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if(n >= k){
        cout << n - k << "\n";
    } else {
        cout << bfs(n, k) << "\n";
    }

    return 0;
}