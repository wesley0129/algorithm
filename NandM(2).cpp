#include <iostream>
#include <vector>
using namespace std;

vector<int> box;
vector<bool> visited(false);
vector<vector<int>> result;

void dfs(int& k, int& n, int& m){
    if(box.size()==m){
        result.push_back(box);
        return;
    }
    for(int i=k; i<=n; i++){
        if(visited[i]) continue;

        visited[i]=true;
        box.push_back(i);

        dfs(i, n, m);

        visited[i]=false;
        box.pop_back();
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m, first = 1;
    cin>>n>>m;
    dfs(first, n, m);
    for(auto arr: result){
        for(auto i: arr){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}