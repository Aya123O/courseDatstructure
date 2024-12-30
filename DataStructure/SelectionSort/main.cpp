#include <iostream>

using namespace std;
void SelectionSort(int *arr ,int size){
int minIndex ;
for (int outer=0;outer<size-1;outer++){
minIndex=outer;
for(int inner=outer+1 ;inner <size ;inner ++){

  if(arr[minIndex] >arr[inner]){ minIndex = inner ;}
}
   int swap =arr[outer];
   arr[outer]=arr[minIndex];
   arr[minIndex]=swap;

}

}
void display (int *arr ,int size){

for(int i= 0 ;i<size ;i++){

 cout <<arr[i]<<"\t";

}
cout <<endl;

}
int main()
{
     int arr [5] ={5,2,11,9,10};
   cout <<"Array Before Sorted \n";
   display (arr,5);
   SelectionSort(arr,5);
   cout <<"Array After Sorted \n";
   display (arr,5);
    return 0;
}
