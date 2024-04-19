#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
using namespace std;

void explainPair()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second;

    pair<int, pair<int, int>> p1 = {1, {3, 5}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second;

    pair<int, int> arr[] = {{1, 3}, {5, 7}, {9, 11}};
    cout << arr[1].first;

    pair<int, char> p2 = {1, 'a'};
    cout << p2.second;
}
void explainVector()
{
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    vec.emplace_back(3, 4);

    vector<int> v1(5, 100); // {100, 100, 100, 100, 100}

    vector<int> v2(5); // {0, 0, 0, 0, 0}

    vector<int> v3(5, 20);
    vector<int> v4(v1); // copies v1 to v4

    vector<int>::iterator it = v.begin();

    it++;
    cout << *(it) << " ";

    it += 2;
    cout << *(it) << " ";

    vector<int>::iterator it = v.end();
    // vector<int>::iterator it = v.rend();
    // vector<int>::iterator it = v.rbegin();

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    for (auto it : v)
    {
        cout << it << " ";
    }

    // erase functions
    v.erase(v.begin() + 1); //[index]

    v.erase(v.begin() + 2, v.begin() + 4); // [start, end]

    // insert functions
    vector<int> v5(3, 100);           // {100, 100, 100}
    v5.insert(v5.begin(), 300);       // {300, 100, 100, 100}
    v5.insert(v5.begin() + 1, 2, 10); // {300, 10, 10, 100, 100, 100}

    vector<int> copy(2, 500);
    v5.insert(v5.begin() + 3, copy.begin(), copy.end()); // {300, 10, 10, 500, 500, 100, 100, 100}

    // {10, 20}
    cout << v.size(); // 2
    v.pop_back();     //{10}

    v1.swap(v2);

    v.clear(); // erase all elements;

    cout << v.empty(); // true if atlease one element
}
void explainList()
{
    list<int> ls;

    ls.push_back(3);    //{3}
    ls.emplace_back(4); // {3,4}

    ls.push_front(2);    //{2,3,4}
    ls.emplace_front(1); //{1,2,3,4}

    ls.pop_back();  //{4}
    ls.pop_front(); //{1}

    /*
    -> list operations are usually faster as compared to vector as
        in list elements are stored as doubly linked list;
    -> rest fucntions are same as vector
    -> begin, end, rend, rbegin, clear, insert, erase, size, swap
    */
}
void explainDeque()
{
    deque<int> dq;
    // rest all functions same as list and vector
}
void explainStack()
{
    stack<int> st;
    st.push(1);    // {1}
    st.push(2);    // {2,1}
    st.push(3);    //{3,2,1}
    st.emplace(4); //{4,3,2,1}

    cout << st.top(); // returns 4  "** st[2] is invalid **"

    st.pop(); // returns and deletes top element

    st.size(); // 3

    st.empty(); // true or false

    stack<int> st1, st2;
    st1.swap(st2); // swaps
}
void explainQueue()
{
    queue<int> q;
    q.push(1);    // {1}
    q.push(2);    // {1,2}
    q.emplace(3); //{1,2,3}

    cout << q.back(); // returns last element of queue {3}
    q.back()++;

    cout << q.front(); // {1}

    q.pop(); // returns and deletes first element
}
void explainPQ()
{
    priority_queue<int> pq;
    pq.push(5);     // {5}
    pq.push(2);     // {5, 2}
    pq.emplace(10); // {10, 5, 2}

    cout << pq.top(); // {10}

    pq.pop();
    pq.size();

    // minimum heap
    priority_queue<int, vector<int>, greater<int>> pq1;
    pq.push(5);     // {5}
    pq.push(2);     // {2, 5}
    pq.emplace(10); // {2, 5, 10}
}
void explainSet()
{
    // tree is maintained
    // stores everything in sorted order
    // stores unique

    set<int> st;
    st.insert(1);  // {1}
    st.emplace(2); // {1,2}
    st.insert(2);  //{1,2}
    st.insert(3);  //{1,2,3}
    st.insert(5);  // {1,2,3,5}
    st.insert(4);  // {1,2,3,4,5}

    // functions similar to vector and list
    // begin(), empty(), size(), swap(), etc..

    // {1,2,3,4,5}
    auto it = st.find(3); // points to address of 3

    auto it = st.find(6); // it points at set.end() -> points to right after end

    st.erase(5); // {1,2,3,4}

    int count = st.count(2);

    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2);

    auto it = st.lower_bound(2);
}
void explainMultiSet()
{
    // everything same as set
    // can store duplicate elements also

    multiset<int> ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1,1}
    ms.insert(1); //{1,1,1}

    ms.erase(1); // all 1's are erased

    int cnt = ms.count(1); // 3

    // onyl single one is deleted
    ms.erase(ms.find(1));

    // rest all functionns same as set
}

int main()
{
    explainPair();
}