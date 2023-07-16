
\*
Remove Duplicates Recursively

Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string
Sample Input 1 :
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
*\

#include <iostream>
#include<cstring>
using namespace std;


void removeConsecutiveDuplicates(char *str) {

	 int len=strlen(str);
     if(len<=1) {
		 return ;
	 }

	 removeConsecutiveDuplicates(str+1);

    if(str[0]!= str[1]){
		 return ;
	 }

	 if(str[0]==str[1]){
           for (int i = 1; i<len; i++) {
             str[i - 1] = str[i];
           }
           str[len - 1] = '\0';
           removeConsecutiveDuplicates(str + 1);
         }
}


int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}