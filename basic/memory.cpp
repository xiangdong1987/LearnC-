//
// Created by xiangdong on 16/8/8.
// 堆和栈的区别
// 堆是用户使用的内存空间
// 栈是系统使用的内存空间
//
#include "MyHeader.h"

int main() {
    int i;
    cout << "输入初始化数量:";
    cin >> i;
    //在堆中初始化动态内存
    int *list = new int[i];
    for (int j = 0; j < i; ++j) {
        cout << "输入想插入的数字:" << endl;
        cin >> list[j];
    }
    cout << "您输入的数组是:" << endl;
    for (int k = 0; k < i; ++k) {
        cout << list[k] << ",";
    }
    cout << endl;
}
