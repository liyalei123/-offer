//替换空格
//设置两个指针，简化运算时间

#include<iostream>
using namespace std;

void ReplaceBlank(char str[], int length){
	//length表示string所能容纳长度
	if(str== NULL || length <= 0)
		return;
	int OriginalLength = 0;
	int NumOfBlank = 0;
	for(int i=0;str[i]!='\0';i++){
		++OriginalLength;
		if(str[i]==' ')
			++NumOfBlank;
	} 
	int NewLength = OriginalLength + 2*NumOfBlank;
	if(NewLength > length)
		return;
	int indexOfOriginal = OriginalLength;
	int indexOfNew = NewLength;
	while(indexOfOriginal >=0 && indexOfNew > indexOfOriginal){
		if(str[indexOfOriginal]==' '){
			str[indexOfNew--]='0';
			str[indexOfNew--]='2';
			str[indexOfNew--]='%';
		}
		else
			str[indexOfNew--]=str[indexOfOriginal];
		indexOfOriginal--;
	}
}
int main(){
	char str1[]="HelloDing!";
	char str2[]="Hello Ding!";
	char str3[]="";
	ReplaceBlank(str1,20);
	printf("%s\n",str1);
	ReplaceBlank(str2,20);
	printf("%s\n",str2);
	ReplaceBlank(str3,20);	
	printf("%s\n",str3);
	return 0;
}
