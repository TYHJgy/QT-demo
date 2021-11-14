#include <iostream>
using namespace std;

int main() {
    int i=5,j=6;
    int &r=i;
    void *pi,*pj;
    int* addr;
    int dis;

    pi=&i;    //取整型变量i的地址
    pj=&j;    //取整型变量j的地址
    dis=(int)pj-(int)pi;//计算连续两个整型变量的内存地址之间距离
    addr=(int*)((int)pj+dis);//计算引用变量r在内存中的地址

    cout<<"&i:"<<pi<<endl;
    cout<<"&j:"<<pj<<endl;
    cout<<"&pi:"<<&pi<<endl;
    cout<<"&pj:"<<&pj<<endl;
    cout<<"&addr:"<<&addr<<endl;
    cout<<"&dis:"<<&dis<<endl;
    cout<<"distance:"<<dis<<endl;

    (*addr)=(int)&j;    //将j的地址赋给引用r（此处把r看作指针）

    cout<<"addr:"<<addr<<endl;
    r=100;
    cout<<i<<" "<<j<<endl;
    return 0;
}

