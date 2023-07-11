/*
String to Integer

Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)
Constraints :
0 < |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567
*/


#include <iostream>
#include<cstring>
using namespace std;



int stringToNumber( char input[] , int last){

    if( last ==0){
        return input[last] - '0';
    }

    int smallAns = stringToNumber( input , last-1);
    int a = input[last] - '0' ;

    return smallAns*10 + a ;

}


int stringToNumber(char input[]) {
  // Write your code here
  int length = strlen(input);
  stringToNumber( input , length-1);
}


int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
