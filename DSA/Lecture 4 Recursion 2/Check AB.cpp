/*
Check AB

Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
Input format :
String S
Output format :
'true' or 'false'
Constraints :
1 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
abb
Sample Output 1 :
true
Sample Input 2 :
abababa
Sample Output 2 :
false
Explanation for Sample Input 2
In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.
*/


#include <iostream>
#include <string>
using namespace std;

bool checkAB(string S) {
    if (S.empty()) {
        return true;
    }
    if (S[0] == 'a') {
        if (S.size() >= 3 && S[1] == 'b' && S[2] == 'b') {
            return checkAB(S.substr(3));
        } else {
            return checkAB(S.substr(1));
        }
    } else {
        return false;
    }
}



int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
