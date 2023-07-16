/*
Binary Search (Recursive)

Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 
Hint : Use helper function to solve this question.
*/

#include <iostream>

using namespace std;

int binarySearchHelper( int arr[], int  si , int ei, int x ){

    if( si > ei){

        return -1;
    }

    int mid =(si+ei)/2 ;

    if( arr[mid]==x){

        return mid;
    }

    if(arr[mid]> x ){

         binarySearchHelper( arr ,si , mid-1 ,x );

    }
    else{

        binarySearchHelper( arr , mid+1 ,ei ,x);
    }
}


int binarySearch(int input[], int size, int element) {
    // Write your code here

 int startIndex = 0;
 int endIndex = size-1;

 binarySearchHelper( input , startIndex , endIndex , element);
}


int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
