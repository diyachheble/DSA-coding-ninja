/*
Check Palindrome (recursive)
Send Feedback
Check whether a given String 'S' is a palindrome using recursion.


Return true or false.


Note:
You don’t need to print anything. Just implement the given function.
Example:
Input: s = "racecar"
Output: true
Explanation: "racecar" is a palindrome.
Input Format:
The first and only line of the input contains string S.
Output format:
Return a boolean value True or False.
Sample Input 1:
abbba
Sample Output 1:
true
Explanation Of Sample Input 1 :
“abbba” is a palindrome
Sample Input 2:
abcd
Sample Output 2:
false
Explanation Of Sample Input 2 :
“abcd” is not a palindrome.
Expected time complexity:
Expected time complexity is O(n).
Constraints:
0 <= |S| <= 10^6
where |S| represents the length of string S.
*/



#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <stack>
using namespace std;



bool checkPalindrome(const string& str, int start, int end) {
   if (start >= end) {
     return true;
   }
   if (str[start] != str[end]) {
     return false;
   }
  return checkPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(string& str) {
  return checkPalindrome(str, 0 , str.length() -1);
}




class Runner
{
    string t;

public:
    void takeInput()
    {
        cin>>t;
    }

    void execute()
    {
        auto ans = isPalindrome(t);
    }

    void executeAndPrintOutput()
    {
        auto ans = isPalindrome(t);
        ans ? cout<<"true" : cout<<"false";
    }
};

int main()
{
    
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}

