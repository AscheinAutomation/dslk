#include <bits/stdc++.h>

using namespace std;
void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
void selectionSort(int a[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
    min = i;
    for (j = i+1; j < n; j++)
        if (a[j] < a[min])
        min = j;
 
        swap(a[min], a[i]);
    }
}
void bubbleSort(int a[], int n)
{
    int i, j;
    bool tailap = false;
    for (i = 0; i < n-1; i++){
        tailap = false;
        for (j = 0; j < n-i-1; j++){
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                tailap = true; 
            }
        }
        if(tailap == false){
            break;
        }
    }
}
void insertionSort(int a[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = a[i];
       j = i-1;
       while (j >= 0 && a[j] > key)
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = key;
   }
}

void print(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<<a[i]<<" ";
}

int main(){
   int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, n);
    cout<<" Mang sau khi xep la: ";
      print(a, n);
    selectionSort(a, n);
    cout<<"\n Mang sau khi xep la: ";
    print(a, n);
    insertionSort(a, n);
    cout<<"\n Mang sau khi xep la: ";
    print(a, n);
    return 0;
}