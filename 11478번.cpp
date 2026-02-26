#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    string s;
    int cnt = 0;
    cin>>s;
    unordered_map<string, int> m;
    for(size_t i=0; i<s.size(); i++){
        string tmp;
        for(size_t j=i; j<s.size(); j++){
            tmp = s.substr(i, j-i+1);
            if(m.find(tmp) == m.end()){
                m[tmp];
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}

// 11478번.cpp

// #include <iostream>
// #include <unordered_set>
// #include <string>

// using namespace std;

// unordered_set<string> set;
// string s;

// void solve(int cnt)
// {
//     for (int i = 0; i + cnt <= s.size(); i++)
//     {
//         set.insert(s.substr(i, cnt));
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);

//     cin >> s;

//     for (int cnt = 1; cnt <= s.size(); cnt++)
//     {
//         solve(cnt);
//     }

//     cout << set.size();
//     return 0;
// }