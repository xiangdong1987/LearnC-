//
// Created by xiangdong on 16/8/5.
//
#include "MyHeader.h"

//无类型指针
void increase(void *data, int psize) {
    if (psize == sizeof(char)) {
        char *pchar;
        pchar = (char *) data;
        ++(*pchar);
    } else if (psize == sizeof(int)) {
        int *pInt;
        pInt = (int *) data;
        ++(*pInt);
    }
}

//指针函数
int addtion(int x, int y) {
    return (x + y);
}

int operate(int x, int y, int (*functionName)(int, int)) {
    int g;
    g = (*functionName)(x, y);
    return g;
}

int main() {
    int a = 7;
    //定义指针
    int *p;
    //将指针地址指向a
    p = &a;
    //输出p指针所在的值
    cout << *p << endl;
    //数组也是指针,数组名是指针首地址
    int b[5] = {1, 2, 2, 4, 6};
    int i = 0;
    int *q = b;
    while (i < 5) {
        cout << *q;
        q++;
        i++;
    }
    //常量指针(只能读不能修改)
    const int *c = &a;
    cout << *c << endl;
    //不能赋值
    //*c=i;
    //指针常量(指针是不能修改的 值是可以修改的)
    int *const d = &a;
    cout << *d << endl;
    cout << ++(*d) << endl;
    //指针不能变
    //cout << *d++;
    //指针的指针
    int x = 1;
    int *y;
    int **yy;
    y = &x;
    yy = &y;
    cout << **yy << endl;
    int pInt = 4;
    char pChar = 'a';
    increase(&pInt, sizeof(pInt));
    increase(&pChar, sizeof(pChar));
    cout << pInt << pChar << endl;
    //无效指针
    int myArr[5];
    int *noP;
    //*noP = myArr + 10;
    //空指针
    noP = 0;
    noP = nullptr;
    cout << operate(1, 2, addtion) << endl;
}
