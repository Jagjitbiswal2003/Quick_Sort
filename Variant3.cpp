// Array mid element as Pivot


#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr,int low,int high){
     int mid = low+(high-low)/2;
     int pivot = mid;
     int i = low; int j = high;

        
            while(i < mid && j > mid){
             while(i < mid && arr[i] <= pivot) i++;

             while(j > mid && pivot < arr[j]) j--;

                  if(i < mid && j > mid){
                     swap(arr[i],arr[j]);
                 }
            
         }
                swap(arr[mid],arr[j]);
                return j;
}


void quicksort(vector<int>& arr,int low,int high){
    
    if (low >= high)
        return;

    int pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
}

int main()
{
    int n;
    cout << "Enter the length of array" << endl;
    cin >> n;

    if (n == 0)
        exit(0);

    vector<int> arr(n);

    cout << "Enter array elements" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}