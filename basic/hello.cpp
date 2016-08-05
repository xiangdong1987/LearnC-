//
// Created by xiangdong on 16/8/5.
//
#include "MyHeader.h"

//定义常量
const double pi = 3.1415926;
//通过宏来定义常量
#define WELCOME "你好";

//函数
void sayHello(string name) {
    cout << WELCOME;
    cout << name << endl;
}

//函数模板
template<class T>
T getArea(T x) {
    return x * x;
}

//函数重载
int area(int r) {
    return r * r;
}

double area(double r) {
    return 2 * pi * r;
}

int main() {
    //多个定义
    int a, c;
    //单个定义
    int result;
    double r;
    string name;
    //赋值
    a = 5;
    //空指针
    int *p = nullptr;
    //构造函数赋值
    int b(4);
    c = 1;
    //自动判断类型赋值
    decltype(c) e = a;
    //数组
    int arr[5] = {2, 6, 7, 1, 9};
    //标准输出
    cout << "请输入您的名字:" << endl;
    //标准输入
    cin >> name;
    sayHello(name);
    cout << "请输入正方形的边长:" << endl;
    cin >> a;
    cout << "正方形的面积:" << area(a) << endl;
    cout << "请输入正方形的边长(整数):" << endl;
    cin >> a;
    cout << "正方形的面积:" << getArea<int>(a) << endl;
    cout << "请输入正方形的边长(小数):" << endl;
    cin >> r;
    cout << "正方形的面积:" << getArea<double>(r) << endl;
    cout << "请输入圆的半径(输入小数)" << endl;
    cin >> r;
    cout << "圆的面积:" << area(r) << endl;
    //操作符太简单不介绍 + - * / % && ||
    //逗号隔开操作符
    a = (b = 3, b + 2);
    cout << "a =" << a << endl;
    //循环 if 跳过
    cout << "for循环" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}

