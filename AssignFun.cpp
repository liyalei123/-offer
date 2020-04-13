//面试题1:赋值运算符函数
//注意点：const参数 返回值应该为引用才能够保证能够连续赋值 new和delete的使用

#include<cstring>
#include<cstdio>

class CMyString{
	private://C语言风格的字符串 
		char* m_pData;
	public:
		CMyString(char* pData = nullptr);
		CMyString(const CMyString& str);
		//构造函数
		~CMyString(void); //析构函数
		
		CMyString& operator= (const CMyString& str);
		void Print() ;
};

CMyString::CMyString(char *pData)
{
	if(pData==nullptr){
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else{
		int length=strlen(pData);
		m_pData = new char[length+1];   //注意字符串末尾的'\0' 
		strcpy(m_pData,pData);
	}
}
CMyString::CMyString(const CMyString &str){
	int length=strlen(str.m_pData);
	m_pData=new char[length+1];
	strcpy(m_pData,str.m_pData);
}
CMyString::~CMyString(){
	delete[] m_pData;
} 

CMyString& CMyString::operator=(const CMyString & str){
	if(this == &str)
		return *this;
	delete[] m_pData;
	m_pData = nullptr;
	
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData,str.m_pData);
	
	return *this;
}

void CMyString::Print(){
	printf("%s", m_pData);
}

void Test1(){
	char* text = "Hello Ding!";
	CMyString str1(text);
	CMyString str2;
	str2=str1;
	str2.Print();
	printf("\n");
}
void Test2(){
	char* text = "Hello Ding!";
	CMyString str1(text);
	CMyString str2;
	str1=str1;
	str1.Print();
	printf("\n");
}
void Test3(){
	char* text = "Hello Ding!";
	CMyString str1(text);
	CMyString str2, str3;
	str3=str2=str1;
	str2.Print();
	str3.Print();
	printf("\n");
}
int main(){
	Test1();
	Test2();
	Test3();
	return 0;
}


