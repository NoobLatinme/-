#include<iostream>
using namespace std;
/*
    ��һ������-1��Ȼ���ٺ�ԭ����λ������
    �ж��ٸ�1 �ͻ�ѭ������
*/
int NumberOf1(int n)
{
    int count=0;
    while(n)
    {
        ++count;
        n=(n-1)&n;
    }
    return count;
}
/*
    �Ƿ�Ϊ2�������η�
*/
bool IsNotPowOf2(int n)
{
    return (n-1)&n;
}
/*
    ��Ҫ�ı���ٲ�����ʹm��n���
*/
int ChangeSteps(int m,int n)
{
    m=m^n;
    return NumberOf1(m);
}
void test()
{
    cout<<"Number of 1:"<<NumberOf1(2)<<endl;
    cout<<"Is Pow of 2? : "<<IsNotPowOf2(3)<<endl;
    cout<<"how many that we need change steps : "<<ChangeSteps(10,13)<<endl;
}

int main()
{
    test();
}