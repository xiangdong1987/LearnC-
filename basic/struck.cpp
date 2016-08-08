//
// Created by xiangdong on 16/8/8.
//
#include "MyHeader.h"

//定义类型的的两种方式
typedef char C;
using I=int;
//定义数据结构
struct person {
    C name[10];
    I height;
    I weight;
};

//计算标准体重
void cale(person one) {
    float normal;
    normal = (one.height - 100) * 0.9;
    if (normal > one.weight) {
        cout << one.name << "的体重偏轻" << normal - one.weight << "kg" << endl;
    }
    if (normal < one.weight) {
        cout << one.name << "您的体重超重" << one.weight - normal << "kg" << endl;
    }
    if (normal == one.weight) {
        cout << one.name << "恭喜您体重很标准" << endl;
    }
}

//计算标准体重
void cale(person *one) {
    float normal;
    normal = (one->height - 100) * 0.9;
    if (normal > one->weight) {
        cout << one->name << "的体重偏轻" << normal - one->weight << "kg" << endl;
    }
    if (normal < one->weight) {
        cout << one->name << "您的体重超重" << one->weight - normal << "kg" << endl;
    }
    if (normal == one->weight) {
        cout << one->name << "恭喜您体重很标准" << endl;
    }
}

int main() {
    person me;
    cout << "输入您的名字:" << endl;
    cin >> me.name;
    cout << "输入您的身高:" << endl;
    cin >> me.height;
    cout << "输入您的体重:" << endl;
    cin >> me.weight;
    cale(me);
    //指针数据结构
    person *her;
    cout << "输入您的名字:" << endl;
    cin >> her->name;
    cout << "输入您的身高:" << endl;
    cin >> her->height;
    cout << "输入您的体重:" << endl;
    cin >> her->weight;
    cale(her);
    return 0;
}