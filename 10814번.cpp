#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct client{
    int age;
    string name;
};
bool cmp(client a, client b){
    return a.age < b.age; //true면 a가 앞으로.
}
int main(){
    int N;
    vector<client> arr;
    cin>>N;
    for(size_t i=0; i<N; i++){
        int age;
        string name;
        cin >> age >> name;
        arr.push_back({age, name});
    }
    stable_sort(arr.begin(), arr.end(), cmp);
    for(auto client : arr){
        cout<<client.age<<" "<<client.name<<'\n';
    }
};