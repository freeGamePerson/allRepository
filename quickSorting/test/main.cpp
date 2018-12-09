#include <iostream>
#include <Log.h>
#include <cstring>
#include <string>
#include <Sorting.h>
using namespace std;

void printArray(int array[],int length)
{
    for(int i = 0; i < length ; i++)
    {
        cout << array[i] << "\t";
    }
    cout <<endl;
}
static int array_length = 0;

int main()
{
    ERROR_LOG<string>("=======>>>");
    int array[] = {10,5,7,3,8,2,55,121,24,55,7,95};
    int length = sizeof(array) / sizeof(array[0]);
    array_length = length;
    printArray(array,length);

    QuickSort<int>(array,0,length-1);
    printArray(array,length);
    return 0;
}



//
//int partition(int array[], int left ,int right)
//{
//    int key = array[left];
//
//    while(left< right)
//    {
//        while(left < right && array[right] >=key)
//        {
//            right--;
//        }
//
//        array[left] = array[right];
//
//        while(left < right && array[left] <=key)
//        {
//            left++;
//        }
//
//        array[right] = array[left];
//    }
//
//    array[left] = key;
//
//    return left;
//}
