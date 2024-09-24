#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

// 定义一个类来记录时间
class Time {
private:
    time_t t; // 存储时间
public:
    // 无参构造函数，初始化为当前时间
    Time () {
        t = time (NULL);
    }
    // 有参构造函数，初始化为指定的时间
    Time (int year, int month, int day, int hour, int minute, int second) {
        struct tm timeinfo;
        timeinfo.tm_year = year - 1900;
        timeinfo.tm_mon = month - 1;
        timeinfo.tm_mday = day;
        timeinfo.tm_hour = hour;
        timeinfo.tm_min = minute;
        timeinfo.tm_sec = second;
        t = mktime (&timeinfo);
    }
    // 重载<运算符，比较两个时间的大小
    bool operator< (const Time& other) const {
        return difftime (t, other.t) < 0;
    }
    // 重载<<运算符，输出时间的字符串表示
    friend ostream& operator<< (ostream& os, const Time& time) {
        os << ctime (&time.t);
        return os;
    }
    // 重载-运算符，计算两个时间的差值（秒数）
    double operator- (const Time& other) const {
        return fabs (difftime (t, other.t));
    }
};

// 定义一个函数，根据给出的时间查找所记录的时间
void search_time (const Time& target, const Time* records, int size) {
    // 使用二分查找的方法
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (records[mid] < target) {
            low = mid + 1;
        } else if (target < records[mid]) {
            high = mid - 1;
        } else {
            break;
        }
    }
    // 输出最接近给出的时间的记录
    cout << "The closest record to " << target << "is " << records[mid] << endl;
    // 输出与给出的时间的差值
    cout << "The difference is " << target - records[mid] << "seconds" << endl;
}

// 测试程序
int main () {
    // 创建一个时间数组，存储10个时间记录
    Time records[10] = {
            Time (2023, 12, 11, 19, 17, 30),
            Time (2023, 12, 11, 19, 18, 15),
            Time (2023, 12, 11, 19, 19, 45),
            Time (2023, 12, 11, 19, 20, 30),
            Time (2023, 12, 11, 19, 21, 00),
            Time (2023, 12, 11, 19, 22, 15),
            Time (2023, 12, 11, 19, 23, 30),
            Time (2023, 12, 11, 19, 24, 45),
            Time (2023, 12, 11, 19, 25, 15),
            Time (2023, 12, 11, 19, 26, 00)
    };
    // 创建一个目标时间，用于查找
    Time target (2023, 12, 11, 19, 20, 00);
    // 调用函数，根据目标时间查找所记录的时间
    search_time (target, records, 10);
    return 0;
}
