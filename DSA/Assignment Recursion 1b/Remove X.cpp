/*
Remove X

Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:

*/



#include <iostream>
#include<cstring>
using namespace std;


void removeX(char input[],int start){

    if(input[start]== '\0'){
        return ;
    }

    removeX( input, start+1);
    
   if(input[start]=='x'){

        int length= strlen(input);
        int i ;

       for( i = start+1 ; i<length ; i++){
           input[ i-1 ]=input[ i];
       }
       input[i-1]= '\0';
   }
  

}

void removeX(char input[]) {
    // Write your code here
removeX( input ,0);
}


int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
