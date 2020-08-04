#include<iostream>
using namespace std;
double un_Power(double base,unsigned int exponent);
unsigned int Flag=false;
double Power(double base,int exponent)
{
    double result=0.0;
    if(exponent<0 && base==0)
    {
        Flag=true;
        return 0;
    }
    unsigned int un_exponent=(unsigned int)exponent;
    if(exponent<0)
        un_exponent=(unsigned int)(-exponent);
    result=un_Power(base,un_exponent);
    if(exponent<0)
        result=1.0/result;
    return result;
}
double un_Power(double base,unsigned int exponent)
{
    //递归终止边界值
    if(exponent==1)
        return base;
    if(exponent==0)
        return 1;
/*
    算法如下：
        a的n次方=  a的n/2次方 * a的n/2次方              n=偶数；
                  a的(n-1)/2次方 * a的(n-1)/2次方 *a   n=奇数； 
*/
    double result=un_Power(base,exponent>>1);
    result*=result;
    //判断exponert奇偶；1：奇数 0：偶数
    if((exponent & 0x1)==1)
        result*=base;

    return result;
}
void test()
{
    cout<<"....power: "<<Power(2,-1)<<endl;
    cout<<"is wrong ? :"<<Flag<<endl;
}
int main()
{
    test();
}