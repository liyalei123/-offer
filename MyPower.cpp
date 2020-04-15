//数值的整数次方

#include<iostream>
using namespace std;
bool equal(double b1,double b2);
double Power(double base, int absexponent);
double MyPower(double base, int exponent){
	if(equal(base, 0.0) && exponent<=0)//非法输入
		throw "Invalid input!";
	int absexponent;
	if(exponent >= 0)
		absexponent=exponent;
	else
		absexponent=-exponent;
	double result=Power(base,absexponent);
	if(exponent < 0)
		result=1.0/Power(base,absexponent);
	return result;
	
}
bool equal(double b1,double b2){//两个浮点型的相等判断
	if((b1-b2)<0.0000001 && (b1-b2)>-0.0000001)
		return true;
	else 
		return false;
}
double Power(double base,int absexponent){
	double result = 1.0;
	while(absexponent >= 1){
		result = result * base;
		absexponent--;
	}
	return result;
}
double Power1(double base, int absexponent){
	double result = 1.0;
	if(absexponent==0)
		return 1.0;
	if(absexponent==1)
		return base;
	result=Power1(base,exponent>>1);
	result*=result;
	if(exponent & 0x1==1)
		result*=base;
	return result;

}
int main()
{
	cout << MyPower(2.0,2) << endl;
	cout << MyPower(2.0,-2) << endl;
	cout << MyPower(0.0,-1) << endl;
	return 0;
 } 
