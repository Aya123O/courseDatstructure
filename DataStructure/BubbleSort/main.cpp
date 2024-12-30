#include <iostream>

using namespace std;
void BubbleSort(int* arr ,int size){
    int sortted=0;
    for(int outer = 0;sortted == 0;outer ++){

       for(int inner=0;inner<size-1-outer;inner++){
           sortted =1;
          if(arr[inner] >arr[inner+1]){
          int swap =arr[inner];
          arr[inner]=arr[inner+1];
          arr[inner+1]=swap;
          sortted =0;

          }

       }


    }

   }
   void display (int* arr ,int size){

    for(int index = 0;index <size;index ++){
       cout<<arr[index]<<"\t";

   }
   cout <<endl;
   }

int main()
{
   int arr [5] ={1,5,8,9,10};
   cout <<"Array Before Sorted \n";
   display (arr,5);
   BubbleSort(arr,5);
   cout <<"Array After Sorted \n";
   display (arr,5);
    return 0;
}
