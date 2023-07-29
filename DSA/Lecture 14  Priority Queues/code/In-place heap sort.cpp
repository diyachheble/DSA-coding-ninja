/*
Code : In-place heap sort

Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
*/
#include <iostream>
void heapSort(int arr[], int n) {
    // Write your code
 
    int heapIndex = 1;
    while ( heapIndex < n )                //Creating max-heap
    {
        int childIndex = heapIndex - 1;
        while ( childIndex > 0 )
        {
            int parentIndex = (childIndex - 1) / 2;
            
            if ( arr[childIndex] < arr[parentIndex] )
            {
                int temp =arr[childIndex];
                arr[childIndex] = arr[parentIndex];
                arr[parentIndex] = temp;
            } else {
              break;
            }
            childIndex = parentIndex;
        }
        heapIndex++;
    }
    while( heapIndex > 0 )
    {
        int temp =arr[0];
        arr[0] = arr[heapIndex-1];
        arr[heapIndex-1] = temp;
        heapIndex--;
        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;
        while ( leftChildIndex < heapIndex )
        {
            int minIndex = parentIndex;
            
            if (arr[minIndex] > arr[leftChildIndex] )
                minIndex = leftChildIndex;
            
            if ( rightChildIndex < heapIndex &&arr[minIndex] > arr[rightChildIndex] )
                minIndex = rightChildIndex;
            
            if ( minIndex != parentIndex )
            {
                int temp1 = arr[minIndex];
               arr[minIndex] = arr[parentIndex];
                arr[parentIndex] = temp1;
            }
            else
                break;
            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
    
}


using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}