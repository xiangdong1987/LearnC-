#include <iostream>
using namespace std;
void QuickSort (int a[],int low,int high){
	int i=low;
	int j=high;
	int x=a[i];
	if(low<high){
		while(i<j){
			while((a[j]>=x)&&(i<j)){
				j--;
			}
			a[i] = a[j];
			while((a[i] <= x) && (i < j))
            {
                i++; 
            }  
            a[j]= a[i];
		}
        a[i] = x;
        QuickSort(a,low,i-1);
        QuickSort(a,j+1,high);
	}
}
int main()
{
	int arry[6] = {23,21,1,21,4,19};
    QuickSort(arry,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arry[i]<<endl;
    }
	/* code */
	return 0;
}