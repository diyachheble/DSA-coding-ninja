/*
Maximum Square Matrix With All Zeros

Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.
Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.

Second-line onwards, the next 'N' lines or rows represent the ith row values.

Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
Output Format:
Print the size of maximum square sub-matrix.
 Constraints :
0 <= N <= 10^4
0 <= M <= 10^4

Time Limit: 1 sec
Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4
*/
#include <iostream>
using namespace std;


int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
    int **storage = new int * [n + 1] ;

    for (int i = 0 ;i <= n; i++)
    {
        storage[i] = new int[m + 1];

        for (int j = 0 ;j <= m; j++) {
            storage[i][j] = 0;
        }
    }

    for(int i = n - 1; i >= 0 ;i--)
    {
        for (int j=m-1; j >= 0; j--)
        {
            int maximum = storage[i][j] = max(storage[i+1][j], storage[i][j+ 1]);

            if (min(n - i, m - j) <= maximum) {
                continue;
            }

            bool foundOne = false;

            for (int p= 0; p <= maximum; p++)
            {
                for (int q = 0; q <= maximum; q++)
                {
                    if (arr[i + p][j + q] == 1) {

                        foundOne = true;
                        p = q = maximum + 1;
                    }
                }
            }

            if (foundOne == false) {

                storage[i][j] += 1;
            }
        }
    }

    int ans = storage[0][0];

    for (int i = 0; i <= n; i++) {

        delete[] storage[i];
    }

    delete[] storage;

    return ans;
}


int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}