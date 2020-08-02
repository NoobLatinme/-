#include<stdio.h>
#include<iostream>
using namespace std;
/*
    ����timesOfAge������¼ĳ��������ֵĴ�����ĳ����������˼���
    ��������Ages�����ü��θ����䣬����൱�ڸ�����Ages������
    �ÿռ�O(n)����ȡʱ��O(n)
*/
void SortAges(int Ages[],int length)
{
    if(Ages==NULL || length<=0)
        return;
    const int oldestAge=99;      //���� 0~99��
    int timesOfAge[99+1]; //���������ֵĴ�����C++���Է���ǳ���ֵ
    for(int i=0;i<100;i++)
        timesOfAge[i]=0;
    for(int i=0;i<length;i++)  //��¼ĳ�������ж��ٸ��ˣ�ĳ�������ж��ٸ��˾���ĳ��������Ϊ�±������ٸ��ˣ�
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