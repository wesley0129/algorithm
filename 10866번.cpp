#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;
int arr[20000];

class Deque
{
private:
    int front_, rear_;

public:
    Deque()
    {
        front_ = rear_ = 10000;
    }
    void push_front(int x)
    {
        front_--;
        arr[front_] = x;
    }
    void push_back(int x)
    {
        arr[rear_] = x;
        rear_++;
    }
    void pop_front()
    {
        if (size() == 0)
        {
            cout << -1 << "\n";
        }
        cout << arr[front_] << "\n";
        front_++;
    }
    void pop_back()
    {
        if (size() == 0)
        {
            cout << -1 << "\n";
        }
        rear_--;
        cout << arr[rear_] << "\n";
    }
    int size()
    {
        cout << front_ - rear_ << "\n";
        return (front_ - rear_);
    }
    void empty()
    {
        if (size() == 0)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
    void front()
    {
        cout << arr[front_] << "\n";
    }
    void back()
    {
        cout << arr[rear_ - 1] << "\n";
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    Deque d;
    for (int i = 0; i < n; i++)
    {
        string order;
        cin >> order;
        if (order == "push_front")
        {
            int tmp;
            cin >> tmp;
            d.push_front(tmp);
        }
        if (order == "push_back")
        {
            int tmp;
            cin >> tmp;
            d.push_back(tmp);
        }
        if (order == "pop_front")
        {
            d.pop_front();
        }
        if (order == "pop_back")
        {
            d.pop_back();
        }
        if (order == "size")
        {
            d.size();
        }
        if (order == "empty")
        {
            d.empty();
        }
        if (order == "front")
        {
            d.front();
        }
        if (order == "back")
        {
            d.back();
        }
    }
    return 0;
}