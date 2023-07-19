/*
Get All Unique Subsets
Send Feedback
You are given an sorted integer array of size 'n'.


Your task is to find and return all the unique subsets of the input array.


Subsets are arrays of length varying from 0 to 'n', that contain elements of the array. But the order of elements should remain the same as in the input array.


Note:
The order of subsets is not important. You can return the subsets in any order. However, in the output, you will see the subsets in lexicographically sorted order.


Example:
Input: 'n' = 3, 'arr' = [12, 15, 20]

Output: [[], [12], [12, 15], [12, 15, 20], [12, 20], [15], [15, 20], [20]]

Sample Explanation: Since there are no repeated numbers, a total of 8 subsets are generated.
Input Format :
The first line will contain the value of ‘n’.

The second line will contain n integers, denoting the array 'arr' elements.
Output format :
Return all unique subsets in any order.
Note :
You don't need to print anything. It has already been taken care of. Just implement the given function.
Sample Input 1 :
3
12 15 20
Sample Output 1 :
[] (this represents an empty array)
12 
12 15 
12 15 20 
12 20 
15 
15 20 
20 
Explanation Of Sample Input 1 :
Since there are no repeated numbers, 8 subsets are generated.
Sample Input 2 :
3
1 1 2
Sample Output 2 :
[]    
1 
1 1 
1 1 2 
1 2 
2 
Explanation Of Sample Input 2 :
Since there are repeated numbers, the total number of unique subsets is 6.
Expected Time Complexity :
The expected time complexity is O(k * 2^n), where n is the size of the array and 'k' is the average size of a subset.
Expected Space Complexity :
The expected time complexity is O(k * 2^n), where n is the size of the array and 'k' is the average size of a subset.
Constraints :
1 <= n <= 15
1 <= arr[i] <= 100

Time Limit: 1 sec
*/




#include <bits/stdc++.h>


#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void findSubsets(int index, vector<int>& arr, vector<int>& temp, vector<vector<int>>& ans) {
    ans.push_back(temp);
    for (int i = index; i < (int)arr.size(); ++i) {
        if (i != index && arr[i] == arr[i - 1]) continue;
        temp.push_back(arr[i]);
        findSubsets(i + 1, arr, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> getUniqueSubsets(vector<int>& arr) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    findSubsets(0, arr, temp, ans);
    return ans;
}

class Runner
{
    vector<int> arr;
    int n;
public:
    void takeInput()
    {
        cin >> n;
        arr.assign(n, 0);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
    }
    void execute()
    {
        getUniqueSubsets(arr);
    }

    void executeAndPrintOutput()
    {
        auto c = getUniqueSubsets(arr);
        sort(c.begin(), c.end());
        
        for(auto val : c) {
            for(auto vall : val) cout << vall << ' ';
            cout << '\n';
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
