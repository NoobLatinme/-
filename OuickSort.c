#include<stdio.h>
int RandomInRange(int start,int end); //在start~end中取一个随机值
void Swap(int* ,int*);                //交换函数


int Partition(int data[],int length,int start,int end)
{
    if(data==NULL || length<=0 || start<0 ||end<0)
        return 0;
    int index=RandomInRange(start,end);
    Swap(&data[index],&data[end]);
    int small=start-1;
    for(index=start;index<end;index++)
    {
        ++small;
        if(small!=index)
            Swap(&data[index],&data[small]);
    }
    return small;
}
void QuickSort(int data[],int length,int start,int end)
{
    if(start==end)
        return;
    int index=Partition(data,length,start,end);
    if(index>start)
        QuickSort(data,length,start,index-1);
    if(index<end)
        QuickSort(data,length,index-1,end);
}
void Swap(int a[],int b[])
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
