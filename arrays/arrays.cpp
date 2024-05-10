#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <bits/stdc++>
using namespace std;

// max element
int largestElement(vector<int> &arr, int n)
{
    int maxElement = arr[0];
    for (int i : arr)
    {
        maxElement = max(i, maxElement);
    }

    return maxElement;
}

/*second largest and second smallest element
Approach: intialise largest as first element, and second largest as -1. iterate thru array
if arr[i] > largest, make largest as second and arr[i] as new largest and if arr[i] > second,
but it is not equal to largest then make second as arr[i].
*/
vector<int> getSecondOrderElements(int n, vector<int> arr)
{
    int largest = arr[0];
    int secondLargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        if (arr[i] > secondLargest && arr[i] != largest)
            secondLargest = arr[i];
    }

    int smallest = arr[0];
    int secondSmallest = 100;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        if (arr[i] < secondSmallest && arr[i] != smallest)
            secondSmallest = arr[i];
    }

    return {secondLargest, secondSmallest};
}

/*rotate array left by k elements
approach: save first element in a var. then make every element of array as its next element.
and make last element as first element. repeat this for k times to rotate k times.
*/
vector<int> rotateArray(vector<int> arr, int k)
{
    int n = arr.size();
    for (int i = 1; i <= k; i++)
    {
        int first = arr[0];
        for (int j = 0; j < n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[arr.size() - 1] = first;
    }
    return arr;

    // optimised apporach: use concept of circular indexes (i-k+n)%n
    vector<int> rotatedArr(n);
    for (int i = 0; i < n; i++)
    {
        rotatedArr[(i - k + n) % n] = arr[i];
    }
}

/*check if given array is sorted. array may be rotated and have duplicates
Approach: if array is sorted and rotated then, there is only 1 break point where (nums[x] > nums[x+1]),
if array is already sorted then, there is 0 break point.
*/
bool check(vector<int> &arr)
{
    int size = arr.size();
    int count = 0;

    for (int x = 0; x < size; x++)
    {
        if (arr[x] > arr[(x + 1) % size])
            count++;
    }
    return (count <= 1);
}

/*move all zeroes of array to end
approach: tow pointer apporach.*/
vector<int> moveZeros(int n, vector<int> arr)
{
    int j = -1;
    // place the pointer j:
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    // no non-zero elements:
    if (j == -1)
        return arr;

    for (int i = j; i < n; i++)
    {
        if (arr[i] != 0)
            swap(arr[j++], arr[i]);
    }
    return arr;
}

/*find union of 2 sorted arrays
approach: use two pointers i and j for arra a and b. we will follow the approach of
merging two sorted arrays to make a new sorted array. but to remove the duplicates,
before insertig we check if the last element inserted is equal to element we'll be
inserting now. if equal -> skip inserting and increment i or j accordingly.
*/
vector<int> sortedArray(vector<int> a, vector<int> b)
{
    int i = 0, j = 0;
    vector<int> unionArr;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            if (unionArr.empty() || unionArr.back() != a[i])
                unionArr.push_back(a[i]);
            i++;
        }
        else
        {
            if (unionArr.empty() || unionArr.back() != b[j])
                unionArr.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
    {
        if (unionArr.empty() || unionArr.back() != a[i])
            unionArr.push_back(a[i]);
        i++;
    }
    while (j < b.size())
    {
        if (unionArr.empty() || unionArr.back() != b[j])
            unionArr.push_back(b[j]);
        j++;
    }
    return unionArr;
}

/*find the missing number from the array of size n*/
int missingNumber(vector<int> &nums)
{
    // // xor approach
    // int result = nums.size();
    // int i = 0;

    // for (int num : nums)
    // {
    //     result ^= num;
    //     result ^= i;
    //     i++;
    // }
    // return result;

    // // summation approach
    // int n = nums.size();
    // int maxSum = n * (n + 1) / 2;
    // int sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     sum += nums[i];
    // }
    // return maxSum - sum;

    // hashing approach
    int n = nums.size();
    vector<int> hash(n + 1);
    for (auto it : nums)
    {
        hash[it]++;
    }
    for (int i = 0; i < n + 1; i++)
    {
        if (hash[i] == 0)
            return i;
    }
    return -1;
}

/*find longest subarray with sum k
approach 1:
*/
int longestSubarrayWithSumK(vector<int> arr, long long k)
{
    int left = 0, right = 0;
    int maxLen = 0;
    int n = arr.size();
    long long sum = arr[0];

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left++];
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
            sum += arr[right];
    }
    return maxLen;
}

/*2 sum
BRUTE: check every element wiyh every other element for sum == target */
string read1(int n, vector<int> book, int target)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = book[i];
        for (int j = i + 1; j < n; j++)
        {
            sum += book[j];
            if (sum == target)
            {
                return "YES";
            }
        }
    }
    return "NO";
}
// BETTER:
vector<int> read2(int n, vector<int> book, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int a = book[i];
        int rem = target - a;
        if (mpp.find(rem) != mpp.end())
        {
            return {book[rem], i};
        }
        mpp[a] = i;
    }
    return {};
}
// optimised: 2 pointer approach. sort array. increment left if sum < target and decrement right if sum > target
string read3(int n, vector<int> book, int target)
{
    // sort(book.begin(), book.end());
    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = book[left] + book[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
            left++;
        else
            right--;
    }
    return "NO";
}

/*sort colors: sort an array of 0's 1's and 2's
approach: */
void sortColors(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }

    // unordered_map<int, int> counts;
    // for (int i = 0; i < nums.size(); i++)
    // {
    //     counts[nums[i]]++;
    // }
    // int cval = 0;
    // for (int j = 0; j < nums.size(); j++)
    // {
    //     if (counts[cval] != 0)
    //     {
    //         nums[j] = cval;
    //         counts[cval]--;
    //     }
    //     else
    //     {
    //         cval++;
    //         j--;
    //     }
    // }
}

/*majority element in an array
approach: Moore's voting algorithm.
*/
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int count = 0, el;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count++;
            el = nums[i];
        }
        else if (nums[i] == el)
            count++;
        else
            count--;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == el)
            cnt++;
    }
    if (cnt > n / 2)
        return el;
    return -1;

    // int n = v.size();
    // unordered_map<int, int> hash;
    // for (int i = 0; i < n; i++)
    // {
    //     hash[v[i]]++;
    // }

    // for (auto it : hash)
    // {
    //     if (it.second >= n / 2)
    //         return it.first;
    // }
    // return -1;
}

int main()
{
    int n;
    cin >> n;

    int target;
    cin >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    string result = read1(n, arr, target);

    return 0;
}