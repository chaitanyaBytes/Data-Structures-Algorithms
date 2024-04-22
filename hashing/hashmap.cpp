#include <iostream>
#include <vector>
#include <map>
#include<unordered_map>
using namespace std;


//create a hashmap using map
map<int, int> hashing(int n, vector<int> &v)
{
    // pre compute
    map<int, int> hashmap;
    for (int i = 0; i < n; i++)
    {
        hashmap[v[i]]++;
    }

    // iterate over map
    for (auto it : hashmap)
    {
        cout << it.first << "->" << it.second << endl;
    }

    return hashmap;
}


/*problem: find and return the highest and lowest frequency elements. 
If there are multiple elements that have the highest frequency or lowest frequency, pick the smallest element.
approach: first create element - freq map. Initialize four variables, ‘maxFreq’, ‘minFreq’, 
‘maxElement’, and ‘minElement’, initially assigned to 0, n, 0, and 1e9 + 1, respectively.
iterate thru map and update maxfreq to it.second and maxelement to it.first if it.second > maxfreq.
else if maxfreq == it.second, then update maxelement to min of maxelement and it.first.
*/
vector<int> getFrequencies(vector<int> &v) {
  unordered_map<int, int> hashmap;

  for (int i = 0; i < v.size(); i++) {
    hashmap[v[i]]++;
  }

  int maxf = 0, maxk = 0, mink = 0;
  int minf = v.size();
  for (auto it : hashmap) {
    if (it.second > maxf) {
      maxf = it.second;
      maxk = it.first;
    } else if (maxf == it.second) {
      maxk = min(it.first, maxk);
    }
  }

  for (auto it : hashmap) {
    if (it.second < minf) {
      minf = it.second;
      mink = it.first;
    } else if (minf == it.second) {
      mink = min(it.first, mink);
    }
  }

  return {maxk, mink};
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    map<int, int> hashmap = hashing(n, arr);

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        cout << hashmap[number] << endl;
    }
    return 0;
}