#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

//오등큰수: 특정 원소가 수열에서 등장한 횟수를 F(Ai)라고 할때, 1~i까지 중 한 원소의 오등 큰수는 해당원소보다 오른쪽에 있으면서 해당원소의 등장 횟수보다 큰 수를 의미한다.
//map을 const 참조형으로 바꿀 수 없게 만들때, []로 map의 멤버에 접근하려고 하면, [key]값이 없을경우 새로 생성하니까 const와 같이 쓸 수 없음.
//따라서 map과 const를 같이 사용할때는 .at()을 이용해야함.
vector<int> calc(const vector<int>& a, const unordered_map<int,int>& m){
    vector<int> res(a.size());
    stack<int> st;
    for(int i=0; i<a.size(); i++){
        while(!st.empty() && m.at(a[st.top()]) < m.at(a[i])){
            res[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        res[st.top()] = -1;
        st.pop();
    }
    return res;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> arr(n);
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        arr[i] = tmp;
        if(m.find(tmp) != m.end()){
            m[tmp]++;
        }else{
            m[tmp] = 1;
        }
    }
    arr = calc(arr, m);
    for(auto i: arr){
        cout<<i<<" ";
    }
    return 0;
};

//나중에 map을 배열로 바꾸자
