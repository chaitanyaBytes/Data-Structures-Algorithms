#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_set>
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
    sort(book.begin(), book.end());
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
approach: Dutch national flag algirthm
3 pointers: low, mid, high. arr[0….low-1] contains 0. [Extreme left part],
arr[low….mid-1] contains 1, arr[high+1….n-1] contains 2. [Extreme right part]
arr[0….low-1] contains 0. [Extreme left part]
arr[low….mid-1] contains 1.
arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
The middle part arr[mid….high] is the unsorted segment.
If arr[mid] == 0, swap arr[low], arr[mid]. increment low and mid.
if arr[mid] == 1, increment mid.
if arr[mid] == 2, swap arr[mid], arr[high], decrement high
*/
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
If the array contains a majority element, its occurrence must be greater than the
floor(N/2). Now, we can say that the count of minority elements and majority elements
is equal up to a certain point in the array. So when we traverse through the array we
try to keep track of the count of elements and the element itself for which we are tracking the count.
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

/*maxiumum subarray sum
approach: kadane's algorithm: A subarray with a sum less than 0 will always reduce our
answer and so this type of subarray cannot be a part of the subarray with maximum sum.
*/
int maxSubArray(vector<int> &nums)
{
    long long sum = 0, maxi = -10000;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxi = max(sum, maxi);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

/*Best Time to Buy and Sell Stock
approach: */
int maxProfit(vector<int> &prices)
{
    int buy = prices[0], profit = 0, n = prices.size();
    for (int i = 0; i < n; i++)
    {
        profit = max(profit, prices[i] - buy);
        buy = min(buy, prices[i]);
    }
    return profit;
}

/*rearragnge elements by sign alternativeley
approach: starting index of first pos and neg number is 0 and 1 respectively.
now iterate through given array and if a positive number is encountered, store it in
new array at current posIndex and increment it by 2. similar for neg index.*/
vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> ans(nums.size());
    int posindex = 0;
    int negindex = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            ans[negindex] = nums[i];
            negindex += 2;
        }
        else
        {
            ans[posindex] = nums[i];
            posindex += 2;
        }
    }
    return ans;
}

/*next permutation**
approach: Find the break-point, i: Break-point means the first index i from the back of
the given array where arr[i] > arr[i+1].
If such a break-point does not exist i.e. if the array is sorted in decreasing order.
If a break-point exists:
Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.*/
void nextPermutation(vector<int> &nums)
{
    int ind = -1, n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = n - 1; i > ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin() + ind + 1, nums.end());
}

/*find leaders in an array
Approach: */
vector<int> leaders(int arr[], int n)
{
    vector<int> leaders;
    int maxi = -1000000;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= maxi)
        {
            maxi = max(arr[i], maxi);
            leaders.push_back(maxi);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

/*longest consecutive sequence
approach: put all the array elements into the set data structure.If a number, num,
is a starting number, ideally, num-1 should not exist. So, for every element, x, in the set,
we will check if x-1 exists inside the set. :
If x-1 exists: x cannot be a starting number and move on to the next element in the set.
If x-1 does not exist: x is a starting number of a sequence. So, for number, x, we will start finding the consecutive elements.*/
int longestConsecutive(vector<int> &nums)
{
    // optimmal
    unordered_set<int> st;
    if (nums.size() == 0)
        return 0;
    int longest = 1;
    for (int i = 0; i < nums.size(); i++)
        st.insert(nums[i]);

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

    // better
    int longestt = 1;
    int count = 1;
    if (nums.size() == 0)
        return 0;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            if (nums[i] - nums[i - 1] == 1)
            {
                count++;
            }
            else
            {
                longestt = max(longestt, count);
                count = 1;
            }
        }
    }
    return max(longestt, count);
}

/*rotate matrix by 90 degrees
approach:
brute: when rotating we can observe that [i][j] --> [j][n-1-j]
optimal: take transpose and then reverse every row*/
void rotate(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i; j < matrix.size(); j++)
        {
            swap(matrix[j][i], matrix[i][j]);
        }
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

/*spiral matrix*/
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans;
    int top = 0, left = 0, right = m - 1, bottom = n - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }

        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
        }
        bottom--;
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
        }
        left++;
    }
    return ans;
}

/*pascal Triangle*/
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pascal(numRows, vector<int>(numRows, 1));
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 1; j < i; j++)
        {
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
        pascal[i].erase(pascal[i].begin() + i + 1, pascal[i].end());
    }
    return pascal;
}

/*majority element in array > n/3
If the array contains the majority of elements, their occurrence must be greater than
the floor(N/3). Now, we can say that the count of minority elements and majority elements
is equal up to a certain point in the array. So when we traverse through the array we try
to keep track of the counts of elements and the elements themselves for which we are tracking the counts.*/
vector<int> majorityElementt(vector<int> &nums)
{
    int cnt1 = 0, cnt2 = 0, el1, el2;
    for (int i = 0; i < nums.size(); i++)
    {
        if (cnt1 == 0 && el2 != nums[i])
        {
            cnt1++;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i])
        {
            cnt2++;
            el2 = nums[i];
        }
        else if (nums[i] == el1)
            cnt1++;
        else if (nums[i] == el2)
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    int count1 = 0, count2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
        {
            count1++;
        }
        else if (nums[i] == el2)
        {
            count2++;
        }
    }
    vector<int> ans;
    if (count1 > nums.size() / 3)
        ans.push_back(el1);
    if (count2 > nums.size() / 3)
        ans.push_back(el2);
    return ans;
}

/*3 sum
better approach: hashing*/
vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> st;
    for (int i = 0; i < nums.size(); i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < nums.size(); j++)
        {
            int third = -(nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
/*optimal: 2 pointer approach.
sort the array. fix i. and set j as i+1 and k as n-1. j and k will move. if sum is greater/smaller
than 0, k/j will move backward/forward. if sum == 0, then push it in result vector and move j and k
until current element is not equal to prev element.*/
vector<vector<int>> threeSumm(vector<int> &nums)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1, k = nums.size() - 1;
        while (j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == 0)
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
            else if (sum < 0)
                j++;
            else
                k--;
        }
    }
    return ans;
}

/*4 sum*/
// better: hashing approach
vector<vector<int>> fourSumm(vector<int> &nums, int target)
{
    set<vector<int>> st;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            set<long long> hashset;
            for (int k = j + 1; k < nums.size(); k++)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                long long rem = target - sum;
                if (hashset.find(rem) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)rem};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// optimal: two pointer approach
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1, l = nums.size() - 1;
            while (k < l)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k] + nums[l];
                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
            }
        }
    }
    return ans;
}

/*merge overlappinng intervals
Approach: push the first interval in ans vector. iterate through other intervals. If upper bound of
last interval inserted in ans vector is greater than current interval's lower bound then update the
upper bound of interval in ans to max of itself or current interval's upper bound. else push the
current interval in the ans vector. */
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (!ans.empty() && end <= ans.back()[1])
            continue;
        for (int j = i + 1; j < intervals.size(); j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;

    // optimmised:
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    ans.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (ans.back()[1] >= intervals[i][0])
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else
        {
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

/*merge 2 sorted arrays without usinf extra space*/
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
}

/**/

int main()
{
    int n;
    cin >> n;

    // vector<int> arr(n);
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];

    vector<vector<int>> result = generate(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}