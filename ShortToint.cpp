//将字符串转化为整数
//1.字符串首字符的正负
//2.字符串是否合法
//3.是否会出现字符串越界情况



#include<iostream>
using namespace std;
class solution{
	public:
		static int StrToInt(string str){
			const int MAX_INT_VALUE = 2147483647;
			int len = str.length();
			long long sum = 0;
			if(len == 0){
				return -1;
			}
			if(str[0] == '+' || str[0] == '-'){
				//判断首字符是否标识符号 
				for(int i= 1;i<len;i++){
					//舍去首字符，开始计算
					if(str[i]>'9' || str[i] < '0' )
					//字符非法
						return -1;
					else{
					 	int temp = str[i] - '0';
					 	sum = sum*10 + temp;
					}
				}
				if(str[0]=='+'){
					if(sum > MAX_INT_VALUE){
						//判断整数是否越界
						return -1; 
					}else{
						return sum;
					}
				}
				if(str[0]=='-'){
					if(sum > MAX_INT_VALUE){
						//判断整数是否越界
						return -1; 
					}else{
						return -sum;
					}
				}
			}else if(str[0]>='0' && str[0] <= '9'){
				sum = str[0]-'0';
				for(int i=1;i<len;i++){
					if(str[i]>'9' || str[i] < '0' )
					//字符非法
						return -1;
					else{
					 	int temp = str[i] - '0';
					 	sum = sum*10 + temp;
					}
				}
				if(sum > MAX_INT_VALUE){
					return -1;
				}else{
					return sum;
				}
			}
			
		}
};

int main(){
	string s1="+2147483647";
	int a = solution::StrToInt(s1);
	cout<< a << endl;
	
	string s2="la33";
	int b = solution::StrToInt(s2);
	cout<< b << endl;
	
	string s3="+2147483649";
	int c = solution::StrToInt(s3);
	cout<< c << endl;

	string s4="";
	int d = solution::StrToInt(s4);
	cout<< d << endl;	
}
