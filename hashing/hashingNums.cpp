#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // pre compute
    vector<int> hash(13, 0);
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        cout << hash[number] << endl;
    }
    return 0;
}