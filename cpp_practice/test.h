#include <ctime>
#include <chrono>
#include <memory>
#include <list>
#include <string>
#include "math.h"

struct President
{
    std::string name;
    std::string country;
    int year;

    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
    {
        std::cout << "I am being constructed.\n";
    }
    President(President &&other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << "I am being moved.\n";
    }
    President &operator=(const President &other) = default;
};

// class Student : public std::enable_shared_from_this<Student>
class Student
{
public:
    Student()=default;
    Student(std::string name, int age) : name_(std::move(name)), age_(age)
    {
        std::cout << "construct " << name_ << std::endl;
    };
    Student(const Student &su) : name_(std::move(su.name_)), age_(su.age_)
    {
        std::cout << "copy construct " << name_ << std::endl;
    };
    Student(Student &&other) : name_(std::move(other.name_)), age_(other.age_)
    {
        std::cout << "move construct " << name_ << std::endl;
    };
    Student &operator=(const Student &other) = default;
    ~Student()
    {
        std::cout << "destory " << name_ << std::endl;
    };
    // template <typename... Ts>
    // static std::shared_ptr<Student> Creat(Ts &&... params)
    // {
    //     std::shared_ptr<Student> result(new Student(std::forward<Ts>(params)...));
    //     return result;
    // }
    void Process()
    {
        std::cout << "process..\n";
        // std::cout << shared_from_this()->name_ << std::endl;
    };
    // std::shared_ptr<Student> GetPtr()
    // {
    //     // return shared_from_this();
    // }

public:
    std::string name_;
    int age_;
};

std::string
TimeCount2TimeString(std::time_t &time_count)
{
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_count), "%%Y-%m-%d %T");
    return std::string(ss.str());
}

// you can also get time_t from  std::time(nullptr) or std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())
std::time_t TimeString2timeCount(const std::string &time_string)
{
    std::istringstream ss(time_string);
    std::tm time_struct = {};
    ss >> std::get_time(&time_struct, "%Y-%m-%d %T");
    return mktime(&time_struct);
}

class Line
{
public:
    int getLength(void);
    Line()
    {
        printf("default constructor\n");
        ptr = new int(1);
    };
    Line(int len);         // 简单的构造函数
    Line(const Line &obj); // 拷贝构造函数
    Line &operator=(const Line &l)
    {
        using namespace std;
        cout << "using opentaor= .." << endl;
        ptr = new int;
        *ptr = *l.ptr;
        return *this;
    }
    //   Line& operator=(Line&& l){cout<<"usring r value move"<<endl; ptr = l.ptr; l.ptr=nullptr; return *this;}
    ~Line(); // 析构函数

private:
    int *ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
    using namespace std;
    cout << "construct of " << len << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    using namespace std;
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}

Line::~Line(void)
{
    using namespace std;
    if (ptr)
    {
        cout << "释放内存" << *ptr << endl;
        delete ptr;
    }
    else
    {
        cout << "empty" << endl;
    }
}
int Line::getLength(void)
{
    return *ptr;
}

void display(Line obj)
{
    using namespace std;
    cout << "line 大小 : " << obj.getLength() << endl;
}
