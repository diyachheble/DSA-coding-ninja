/*
Number of Digits
Send Feedback
You are given a number 'n'.


Return number of digits in ‘n’.


Example:
Input: 'n' = 123

Output: 3

Explanation:
The 3 digits in ‘123’ are 1, 2 and 3. 


Input format:
The first line of input contains an integer ‘n’.


Output Format:
Return an integer as described in the problem statement. 


Note
You don’t need to print anything, it has already been taken care of, just complete the given function.
*/



#include <iostream>
using namespace std;

int countDigits(int n){
	// Write your code here.	
	if(n==0){
		return 0;
	}
	int smalloutput =countDigits(n/10);
	int output=smalloutput+1;
}
int main()
{
    int n;
    cin >> n;

    cout << count(n) << endl;
}