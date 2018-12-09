#include <iostream>
#include <Log.h>
#include<iostream>
using namespace std;

template <typename T>
int partition(T array[],int left,int right)
{
    T key = array[left];

    while(left < right)
    {
        while(left < right && array[right] >=key)
        {
            print<string>("right"+to_string(right)+"\tleft"+to_string(left));
            right--;
        }
        print<string>("right"+to_string(right)+"\tleft"+to_string(left));

        array[left] = array[right];
        while(left < right &&  array[left] <= key )
        {
            print<string>("right"+to_string(right)+"\tleft"+to_string(left));

            left++;
        }
        print<string>("right"+to_string(right)+"\tleft"+to_string(left));
        array[right] = array[left];
    }
    array[left] = key;

    return left;

}



///快速排序
template <typename T>
void QuickSort(T array[],int left,int right)
{
    if(left >= right)
    {
        return;
    }

    int center = partition(array,left,right);

    print<string>(to_string(left) +to_string(center) +to_string( right));
    QuickSort(array,left,center-1);

    QuickSort(array,center+1,right);
}
