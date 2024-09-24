#include <iostream>
#include <string>
using namespace std;

// 定义一个基类Date，用于存储年，月，日
class Date {
public:
    int year, month, day;
public:
    // 构造函数，用于初始化一个Date对象
    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
    // 虚函数print，用于打印日期的字符串表示，采用“年-月-日”的格式
    virtual void print() {
        cout << year << "-" << month << "-" << day << endl;
    }
};

// 定义一个派生类ShortDate，继承自Date类，重写print函数，采用“日-月-年”的格式
class ShortDate : public Date {
public:
    // 构造函数，用于初始化一个ShortDate对象，调用基类的构造函数
    ShortDate(int y, int m, int d) : Date(y, m, d) {}
    // 重写print函数，采用“日-月-年”的格式
    void print() override {
        cout << day << "-" << month << "-" << year << endl;
    }
};

// 定义一个派生类MediumDate，继承自Date类，重写print函数，采用“月. 日, 年”的格式
class MediumDate : public Date {
public:
    // 构造函数，用于初始化一个MediumDate对象，调用基类的构造函数
    MediumDate(int y, int m, int d) : Date(y, m, d) {}
    // 重写print函数，采用“月. 日, 年”的格式
    void print() override {
        // 定义一个数组，用于存储月份的英文缩写
        string months[12] = {"Jan.", "Feb.", "Mar.", "Apr.", "May", "Jun.", "Jul.", "Aug.", "Sep.", "Oct.", "Nov.", "Dec."};
        // 输出月份的英文缩写，日期，逗号，空格，年份
        cout << months[month - 1] << " " << day << ", " << year << endl;
    }
};

// 定义一个派生类LongDate，继承自Date类，重写print函数，采用“月 日, 年”的格式
class LongDate : public Date {
public:
    // 构造函数，用于初始化一个LongDate对象，调用基类的构造函数
    LongDate(int y, int m, int d) : Date(y, m, d) {}
    // 重写print函数，采用“月 日, 年”的格式
    void print() override {
        // 定义一个数组，用于存储月份的英文全称
        string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        // 输出月份的英文全称，空格，日期，逗号，空格，年份
        cout << months[month - 1] << " " << day << ", " << year << endl;
    }
};

// 定义一个全局函数printDate，用于接受一个Date类的指针作为参数，并调用其print函数，用于多态地打印不同类型的日期对象
void printDate(Date* dp) {
    dp->print();
}

int main() {
    Date          d (2006, 6, 30);
    ShortDate     sd (2006, 5, 31);
    MediumDate  md (2006, 9, 21);
    LongDate     ld (2006, 9, 21);

    printDate( &d );    // Display: 2006-6-30
    printDate( &sd );   // Display: 31-5-2006
    printDate( &md );  // Display: Sep. 21, 2006
    printDate( &ld );   // Display: September 21, 2006
    return 0;
}
