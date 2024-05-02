#include <iostream>
#include <vector>
#include <set>
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

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = missingNumber(arr);
    cout << result;

    return 0;
}