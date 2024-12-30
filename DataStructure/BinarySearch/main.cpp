#include <iostream>
int BinarySearch(int* arr ,int start ,int end,int val){
   while(start <=end){
     int mid = start + (end - start) / 2;
    if (arr[mid]==val){
      return mid ;
    } else if(arr[mid]<val){
       start =mid+1 ;

    }  else if(arr[mid]>val){
       end =mid-1 ;

    }



   }


return -1;

}

using namespace std;

int main()
{
   int arr [10]={1,2,3,4,5,6,7,8,9,10};
   cout <<"Binary Search " <<endl;
   cout<<"*************************************************"<<endl;
    cout << "Index of 5: " << BinarySearch(arr, 0, 9, 5) << endl;
        return 0;
}
