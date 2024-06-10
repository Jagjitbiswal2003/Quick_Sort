// Array last element as Pivot


#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr,int low,int high){
     int pivot = arr[high];
     int i = low-1;

       for (int j = low; j<=high-1; j++)
       {
             if(arr[j] <= pivot)
             {
                i++;
                swap(arr[i],arr[j]);
             }
       }
        swap(arr[i+1],arr[high]);
        return i+1;
       
    
    /*
     This code is passed all the test cases of GFG but not in HackerRank so we just modify this code above 

     int pivot = arr[high];
     int i = low;
     int j = high-1;

          while(i < j){
            while(arr[i] <= pivot) i++;

            while(pivot <= arr[j]) j--;

               if(i < j){
                 swap(arr[i],arr[j]);
               }
          }
             swap(arr[i],arr[high]);
             return i;
        */
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