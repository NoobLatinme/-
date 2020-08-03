#include<stdio.h>
int MinInorder();
/*
    ��ת�������С���֣��Ͷ��ֲ��ҷ�һ��������index_start & index_end����ָ��
    �ֱ�ֱ��������β������м�ֵ((index_start+index_end)/2)���������
    ��(data[index_start]<data[index_mid]),��index_start=index_mid��
    ��֮(data[index_end]>=data[index_mid])����index_end=index_mid��
    ��������Сֵ��������data[index_end]�ϡ�����������Ϊdata[index_start]
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
    ����һ�������������������������ǰ���0��Ԫ�ذᵽ����
    ��ô�൱��û����ת���飬���һ��Ԫ��Ϊ��СԪ�أ������
    Ϊʲô��ʼ��index_mid=index_start��ԭ��
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
    ������ָ��ָ������ֺ��м�ֵ����ͬʱ�������ö��ֲ��ҷ��Ѿ�����
    ��ʱֻ������˳����ң��ҳ�index_start~index_end�е���Сֵ
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