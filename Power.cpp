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
    //�ݹ���ֹ�߽�ֵ
    if(exponent==1)
        return base;
    if(exponent==0)
        return 1;
/*
    �㷨���£�
        a��n�η�=  a��n/2�η� * a��n/2�η�              n=ż����
                  a��(n-1)/2�η� * a��(n-1)/2�η� *a   n=������ 
*/
    double result=un_Power(base,exponent>>1);
    result*=result;
    //�ж�exponert��ż��1������ 0��ż��
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