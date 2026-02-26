#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> dijkstra(int start, int V){
    vector<int> distance(V+1, 10000000);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    distance[start] = 0;
    //맨 처음 노드부터 시작하기 위해서 pq에 넣어준다.
    pq.push({0, start});

    while(!pq.empty()){
        int dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if(distance[current_node] <= dist) continue;
        //현재 노드에서 갈 수 있는 노드들을 모두 확인함.
        //graph에 1에서 2로 가는 길이 있고 해당 길의 cost가 2라면 초기의 2로 가는 distance는 inf로 설정되어 있기 때문에 
        //dist + weight 즉, 0+2가 더 작은 값이 되고 두 값을 더해서 나온 2라는 값이 distance[2]에 들어가게 된다.
        //이렇게 1에서 갈 수 있는 모든 노드에 대해서 distance를 갱신해주고 pq에 넣으면 자동으로 1에서 갈 수 있는 노드 중 
        //가장 distance가 작은 노드가 pq의 top에 오게 된다.
        //ex) 1->2(2), 1->3(4) 2->(3)(3)인 경우를 생각해보자

        //첫번째 루프를 마치면 distance[2] = 2가 되고 pq에는 {2, 2}가 들어가게 된다.
        //두번째 루프를 돌면 distance[3] = 4가 되고 pq에는 {4, 3}이 들어가게 된다.
        //그러면 1에서 2와 3으로 가는 길은 모두 확인했기 때문에 다음 루프로 들어가게 되고 dist = 2, current_node = 2가 된다.
        //이 때 위의 if문에 걸리지 않기 때문에 아래의 루프를 돌게 된다.
        //current_node = 2 , dist = 2;
        //2에서 갈 수 있는 노드는 3이 있기 때문에 2->3(3)을 확인하게 된다. distance[3] = 4고 dist와 weight을 더하면 5가 된다.
        //따라서 아래의 if문을 충족시키지 못하기 때문에 distance는 갱신되지 않고 pq에 넣지 않게 되면서 루프를 빠져나간다.
        //pq에서 {4, 3}이 실행되면 dist = 4, current_node = 3이 되고 distance[3] = 4이기 때문에 if문에 걸려서 루프를 빠져나가게 되고
        //pq에 아무것도 남지 않기 때문에 while문을 빠져나가게 되면서 distance를 리턴한다.
        for(auto [next_node, weight]: graph[current_node]){
            if(distance[next_node] > dist + weight){
                distance[next_node] = dist + weight;
                pq.push({distance[next_node], next_node});
            }
        }
    }

    return distance;
}
int main(){
    int V, E, start;
    cin >> V >> E >> start;
    graph.resize(V+1);

    for(size_t i = 0; i < E; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back({to, cost});
    }

    vector<int> output;
    output = dijkstra(start, V);
    for(size_t i = 1; i <= V; i++){
        if(output[i] == 10000000) cout << "INF" << endl;
        else cout << output[i] << endl;
    }
}