#include<stdio.h>
int MinInorder();
/*
    旋转数组的最小数字，和二分查找法一样，设置index_start & index_end两个指针
    分别直线数组首尾，如果中间值((index_start+index_end)/2)在左递增区
    间(data[index_start]<data[index_mid]),则index_start=index_mid，
    反之(data[index_end]>=data[index_mid])，则index_end=index_mid，
    ‘最终最小值总是落在data[index_end]上’，结束条件为data[index_start]
    >=data[index_end]
*/
int Min(int data[],int length)
{
    int temp=0;
    if(data==NULL || length<=0)
        return 0;
    int index_start=0;
    int index_end=length-1;
    int index_mid=index_start;  
/*
    存在一种特殊情况，如果把排序数组的前面的0个元素搬到后面
    那么相当于没有旋转数组，则第一个元素为最小元素，这就是
    为什么初始化index_mid=index_start的原因
*/
    while(data[index_start]>=data[index_end])
    {
        if(index_end-index_start==1)
        {
            index_mid=index_end;
            break;
        }
        index_mid=(index_end+index_start)/2;
/*
    当两个指针指向的数字和中间值均相同时，再利用二分查找法已经不行
    这时只能利用顺序查找，找出index_start~index_end中的最小值
*/
        if(data[index_start]==data[index_mid] && 
            data[index_mid]==data[index_end])
        {
            return MinInorder(data,index_start,index_end);
        }

        if(data[index_start]<=data[index_mid])
            index_start=index_mid;
        else if(data[index_end]>=data[index_mid])
            index_end=index_mid;
    }
    return data[index_mid];
}
int MinInorder(int data[],int start,int end)
{
    int result=data[start];
    for(int i=start+1;i<=end;++i)
    {
        if(result>data[i])
            result=data[i];
    }
    return result;
}
void test()
{
    //int data[]={3,4,5,1,2};
    //int data[]={1,0,1,1,1};
    //int data[]={1,1,1,0,1};
    //int data[]={1,2,3,4,5};
    int data[]={1};
    int temp=0;
    temp=Min(data,1);
    printf("%d ",temp);
}
int main()
{
    test();
}