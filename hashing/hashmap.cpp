#include <iostream>
#include <vector>
#include <unordered_map>
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

    // pre commpute
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        cout << mpp[number] << endl;
    }
    return 0;
}