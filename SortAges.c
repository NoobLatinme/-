#include<stdio.h>
#include<iostream>
using namespace std;
/*
    数组timesOfAge用来记录某个年龄出现的次数。某个年龄出现了几次
    就在数组Ages里设置几次该年龄，这就相当于给数组Ages排序了
    用空间O(n)来换取时间O(n)
*/
void SortAges(int Ages[],int length)
{
    if(Ages==NULL || length<=0)
        return;
    const int oldestAge=99;      //年龄 0~99；
    int timesOfAge[99+1]; //存放年龄出现的次数，C++可以放入非常量值
    for(int i=0;i<100;i++)
        timesOfAge[i]=0;
    for(int i=0;i<length;i++)  //记录某个年龄有多少个人（某个年龄有多少个人就在某个年龄作为下标存入多少个人）
    {
        int age=Ages[i];
        if(age<=0 || age>oldestAge)
            throw new std::exception("age out of range")
        ++timesOfAge[age];  
    }

    int index=0;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<timesOfAge[i];j++)
        {
            Ages[index]=i;
            ++index;
        }
    }
}