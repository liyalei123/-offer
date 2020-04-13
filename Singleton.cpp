//单例模式：完全看不懂啊！！！
//单线程？多线程？锁？
//注意到实现中m_pInstance和GetInstance都是静态的，所以没有创建对象就已经存在了。通过调用GetInstance来创建或者获取唯一的对象
#include<iostream>
using namespace std;
class CSingleton{
private:
    CSingleton(){}                            //1.构造函数是私有的，不能通过构造函数创建该类的实例
    static CSingleton *m_pInstance;           //2.静态成员变量，且是私有的，指向一个CSingleton实例，同一时间只存在一个这个变量，所以只能存在一个CSingleton的实例
public:
    static CSingleton *GetInstance(){         //3.只能通过这个函数来创建并获得一个CSingleton实例，且这个实例是唯一的（因为没有其他途径创建CSingleton实例，构造函数是私有的）
        if(m_pInstance == NULL){
            m_pInstance = new CSingleton;
        }

        return m_pInstance;
    }
};

CSingleton *CSingleton::m_pInstance = NULL;    //4.初始化类的静态成员变量
int main()
{
	return 0;
 } 
