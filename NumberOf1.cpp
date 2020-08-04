#include<iostream>
using namespace std;
/*
    把一个整数-1，然后再和原整数位与运算
    有多少个1 就会循环几次
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
    是否为2的整数次方
*/
bool IsNotPowOf2(int n)
{
    return (n-1)&n;
}
/*
    需要改变多少部才能使m与n相等
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