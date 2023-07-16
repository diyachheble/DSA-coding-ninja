/*
Merge Sort Code

You are given the starting 'l' and the ending 'r' positions of the array 'ARR'.


You must sort the elements between 'l' and 'r'.


Note:
Change in the input array itself. So no need to return or print anything.
Example:
Input: ‘N’ = 7,
'ARR' = [2, 13, 4, 1, 3, 6, 28]

Output: [1 2 3 4 6 13 28]

Explanation: After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
Input format :
The first line contains an integer <em>**'N'**</em> representing the size of the array/list.

The second line contains 'N' single space-separated integers representing the elements in the array/list.
Output format :
You don't need to return anything. In the output, you will see the array after you do the modification.
Sample Input 1:
7
2 13 4 1 3 6 28
Sample Output 1:
1 2 3 4 6 13 28
Explanation of Sample Output 1:
After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
Sample Input 2:
5
9 3 6 2 0
Sample Output 2:
0 2 3 6 9
Explanation of Sample Output 2:
After applying 'merge sort' on the input array, the output is [0 2 3 6 9].
Constraints :
1 <= N <= 10^3
0 <= ARR[i] <= 10^9
*/




#include <bits/stdc++.h>

using namespace std;

#include<iostream>

using namespace std; 
 
 void merge( vector<int>& arr  , int l , int m , int r){
     
     int n1=m-l+1;
     int n2=r-m;

     vector<int> a(n1), b(n2);

   

    for (int i = 0; i < n1; i++) {
      a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++) {
      b[i] = arr[m + 1 + i];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while(i<n1){
        arr[k] = a[i];
            k++;
            i++;
    }

    while(j<n2){
        arr[k] = b[j];
            k++;
            j++;
    }



 }

void mergeSort(vector<int>& arr, int l, int r) {
    // Write Your Code Here
    if( l >= r){
        return ;
    }
    int mid = (l+r)/2 ;

    mergeSort( arr , l ,mid );
    mergeSort( arr ,mid+1 ,r);

    merge( arr , l , mid , r);

}


class Runner {
  vector<int> v;

public:
  void takeInput() {
    int n;
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
  }

  void execute() {
    auto c = v;
    mergeSort(c, 0, (int)c.size() - 1);
  }

  void executeAndPrintOutput() {
    auto c = v;
    mergeSort(c, 0, (int)c.size() - 1);
    for (int i = 0; i < c.size(); ++i)
      cout << c[i] << ' ';
    cout << endl;
  }
};

int main() {
  // freopen("./Testcases/large/in/input30.txt", "r", stdin);
  // freopen("./Testcases/large/out/output30.txt", "w", stdout);
  Runner runner;
  runner.takeInput();
  runner.executeAndPrintOutput();

  return 0;
}





