#include<stdio.h>
#include<time.h> 
void swap(int arr[], int pos1,int pos2)
{
    int temp;
    temp=arr[pos1];
    arr[pos1]=arr[pos2];
    arr[pos2]=temp;
}
int partition(int arr[],int low, int high, int pivot)
{
    int i=low;
    int j=low;
    while(i<=high)
    {
        if(arr[i]>pivot)
        {
            i++;
        }
        else
        {
            swap(arr,i,j);
            i++;
            j++;
        }
    }
    return j-1;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pivot=arr[high];
        int pos=partition(arr,low,high,pivot);
        quicksort(arr,low,pos-1);
        quicksort(arr,pos+1,high);
        }
}
int main()
{
    clock_t start,end;
    int n;
    printf("enter the size of array:\n");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array element:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
         }
    printf("\n before sorted:\n");
    for(int i=0;i<n;i++)
    printf("%d\t",arr[i]);
    start=clock();
    quicksort(arr,0,n-1);
    printf("\n\nthe sorted array is:\n\n");
    for(int i=0;i<n;i++)
    printf("%d\t",arr[i]);
    end=clock();
    printf("\nthe time complexity is%ld\n",end-start);
    return 0;
}
