#include <iostream>
#include <string>
#include <list>
#include <sstream>
#include <cstdlib>
#include "../include/info.h"
#include "../include/ui.h"
#include "search_info.h"
#include "const.h"
#include <iomanip>
extern std::list<student_info> students;
std::list<student_info> searched_stu;
bool search_student(std::string &str)
{

    std::cout << "输入\\back退出当前查询。" << std::endl;
    std::cout << "输入\\all显示所有信息。" << std::endl;
    std::cout << "输入*表示不设置此筛选条件。" << std::endl;

    student_info si;
    if (!si.input_guide())
    {
        return true;
    }

    std::ostringstream oss;
    int count = 0;
    oss << "您输入的学生信息为：\n"
        << si << std::endl;
    oss << std::endl
        << title_student << std::endl;
    for (std::list<student_info>::iterator i = students.begin(); i != students.end(); i++)
    {
        if (*i == si)
        {
            searched_stu.push_back(*i);
            oss << *i << std::endl;
            count++;
        }
    }
    oss << "查询到" << count << "条结果。" << std::endl;

    str = oss.str();
    // choice c[2] = {search_student_again ,search_student_exit};

    // bool flag = true;
    // while(flag) {
    //     system("cls");
    //     std::cout << str << std::endl;
    //     switch(ui::show_screen("学生信息查询完毕", "请选择后续操作", 2, "从筛选结果中继续查询", "退出学生信息查询")){
    //         case 'A':
    //         //search_student_again();
    //         break;
    //         case 'B':
    //         flag = false;
    //         return true;
    //         break;
    //         default:
    //         break;
    //     }
    // }
    return true;
}
bool search_student_again(std::string &str)
{
    return true;
}
bool search_student_exit(std::string &str)
{
    return true;
}
extern std::list<course_info> courses;
std::list<course_info> searched_cou;
bool search_course(std::string &str)
{
    std::cout << "输入\\back退出当前查询。" << std::endl;
    std::cout << "输入\\all显示所有信息。" << std::endl;
    std::cout << "输入*表示不设置此筛选条件。" << std::endl;

    course_info ci;
    if (!ci.input_guide())
    {
        return true;
    }

    std::ostringstream oss;
    int count = 0;
    oss << "您输入的课程信息为：\n"
        << ci << std::endl;
    oss << std::endl;
    oss << title_course << std::endl;
    for (std::list<course_info>::iterator i = courses.begin(); i != courses.end(); i++)
    {
        if (*i == ci)
        {
            searched_cou.push_back(*i);
            oss << *i << std::endl;
            count++;
        }
    }

    oss << "查询到" << count << "条结果。" << std::endl;

    str = oss.str();

    // bool flag = true;
    // while(flag) {
    //     system("cls");
    //     std::cout << str << std::endl;
    //     switch(ui::show_screen("课程信息查询完毕", "请选择后续操作", 2, "从筛选结果中继续查询", "退出课程信息查询")){
    //         case 'A':
    //         //search_student_again();
    //         break;
    //         case 'B':
    //         flag = false;
    //         return true;
    //         break;
    //         default:
    //         break;
    //     }
    // }

    return true;
}
extern std::list<grade_info> grades;
std::list<grade_info> searched_gra;
bool search_grade(std::string &str)
{
    std::cout << "输入\\back退出当前查询。" << std::endl;
    std::cout << "输入\\all显示所有信息。" << std::endl;
    std::cout << "输入*表示不设置此筛选条件。" << std::endl;

    grade_info gi;
    if (!gi.input_guide())
    {
        return true;
    }

    std::ostringstream oss;
    int count = 0;
    oss << "您输入的成绩信息为：\n"
        << gi << std::endl;
    oss << std::endl
        << title_grade << std::endl;
    for (std::list<grade_info>::iterator i = grades.begin(); i != grades.end(); i++)
    {
        if (*i == gi)
        {
            searched_gra.push_back(*i);
            oss << *i << std::endl;
            count++;
        }
    }
    oss << "查询到" << count << "条结果。" << std::endl;

    str = oss.str();

    std::string info;
    bool flag = true;
    while (flag)
    {
        system("cls");
        std::cout << str << std::endl
                  << info << std::endl;
        switch (ui::show_screen("成绩信息查询完毕", "请选择后续操作", 3, "统计课程成绩", "统计学生成绩", "退出成绩信息查询"))
        {
        case 'A':
            flag = calculate_course(info);
            break;
        case 'B':
            flag = calculate_student(info);
            break;
        case 'C':
            return true;
            break;
        default:
            break;
        }
    }

    return true;
}
bool calculate_grade(std::string &str)
{
    bool flag = true;
    std::string info;
    while (flag)
    {
        system("cls");
        std::cout << info << std::endl;
        switch (ui::show_screen("成绩统计", "请选择统计选项: ", 3, "课程统计", "学生统计", "退出"))
        {
        case 'A':
            flag = calculate_course(info);
            break;
        case 'B':
            flag = calculate_student(info);
            break;
        case 'C':
            return true;
            break;
        default:
            break;
        }
    }
    return true;
}
struct course_sum
{
    const course_info &ci;
    int count;  //课程总人数
    int percent_count;   //百分制成绩人数
    double percent;
    int point_count;    //绩点成绩人数
    double point;
};
std::list<course_sum> calculate_course_list;
//输出百分制平均成绩，平均绩点，课程人数
bool calculate_course(std::string &str)
{
    std::ostringstream oss;

    for (std::list<grade_info>::iterator i = searched_gra.begin(); i != searched_gra.end(); i++)
    {

        std::istringstream iss1(i->get_percent());
        double percent;
        if(iss1.peek() == '-') {
            percent = -1.0;
        } else {
            iss1 >> percent;
        }

        std::istringstream iss2(i->get_grade_point());
        double point;
        if(iss2.peek() == '-') {
            point = -1.0;
        } else {
            iss2 >> point;
        }

        bool contains = false;
        for (std::list<course_sum>::iterator j = calculate_course_list.begin(); j != calculate_course_list.end() && !contains; j++)
        {
            if (j->ci.get_course_first_id() == i->get_course_first_id() && j->ci.get_course_second_id() == i->get_course_second_id())
            {
                j->count++;
                if(percent != -1.0) {
                    j->percent_count++;
                    j->percent += percent;
                }
                if(point != -1.0) {
                    j->point_count++;
                    j->point += point;
                }
                contains = true;
            }
        }
        if (!contains)
        {
            calculate_course_list.push_back(course_sum{*i, 1, ((percent == -1.0) ? 0 : 1), ((percent == -1.0) ? 0 : percent), ((point == -1.0) ? 0 : 1), ((point == -1.0) ? 0 : point)});
        }
    }
    oss << std::setw(width_course_first_id) << "课程号" << std::setw(widtch_course_second_id) << "课序号" << std::setw(width_course_name) << "课程名" << std::setw(10) << "课程人数" << std::setw(10) << "平均绩点" << std::setw(16) << "百分制平均分" << std::endl;
    for (std::list<course_sum>::iterator i = calculate_course_list.begin(); i != calculate_course_list.end(); i++)
    {
        oss << std::setw(width_course_first_id) << i->ci.get_course_first_id() << std::setw(widtch_course_second_id) << i->ci.get_course_second_id() << std::setw(width_course_name) << i->ci.get_course_name() << std::setw(10) << i->count;

        if(i->point_count == 0) {
            oss << std::setw(10)<< '-';
        } else {
            i->point /= i->point_count;
            oss << std::setw(10) << std::setprecision(4) << i->point;
        }
        if (i->percent_count == 0) {
            oss << std::setw(16) << '-';
        } else {
            i->percent /= i->percent_count;
            oss << std::setw(16) << std::setprecision(4) << i->percent;
        }
        oss << std::endl;
        oss.unsetf(std::ios_base::floatfield);
    }
    str = oss.str();
    return true;
}
struct student_sum
{
    const student_info &si;
    int count;       //课程数
    int total_point; //总学分
    int count_point; //计算gpa用学分
    double point1;   // gpa
};
std::list<student_sum> calculate_student_list;
//课程数，总学分，GPA
bool calculate_student(std::string &str)
{
    std::ostringstream oss;
    for (std::list<grade_info>::iterator i = searched_gra.begin(); i != searched_gra.end(); i++)
    {
        int total_point = 0; //总学分
        int count_point = 0; //计数学分
        double point1 = 0;   //绩点
        //获得当前课程学分
        std::istringstream iss_point(i->get_course_point());
        iss_point >> total_point;

        if (i->get_grade_point() == "-")
        { //不计入gpa
            count_point = 0;
            point1 = 0;
        }
        else
        { //计入gpa
            count_point = total_point;
            std::istringstream iss_point(i->get_grade_point());
            iss_point >> point1;
        }

        bool contains = false;
        for (std::list<student_sum>::iterator j = calculate_student_list.begin(); j != calculate_student_list.end() && !contains; j++)
        {
            if (j->si.get_id() == i->get_id())
            {
                j->count++;
                j->total_point += total_point;
                j->count_point += count_point;
                j->point1 += point1 * count_point;
                contains = true;
            }
        }
        if (!contains)
        {
            calculate_student_list.push_back(student_sum{*i, 1, total_point, count_point, point1 * count_point});
        }
    }
    oss << std::setw(width_id) << "学号" << std::setw(width_name) << "姓名" << std::setw(10) << "选课数目" << std::setw(8) << "总学分" << std::setw(10) << "绩点" << std::endl;
    for (std::list<student_sum>::iterator i = calculate_student_list.begin(); i != calculate_student_list.end(); i++)
    {

        oss << std::setw(width_id) << i->si.get_id() << std::setw(width_name) << i->si.get_name() << std::setw(10) << i->count << std::setw(8) << i->total_point << std::setw(10);
        if (i->count_point != 0)
        {
            double gpa = i->point1 / i->count_point;
            oss << std::setprecision(4) << gpa << std::endl;
            oss.unsetf(std::ios_base::floatfield);
        }
        else
        {
            oss << '-' << std::endl;
        }
    }
    str = oss.str();
    return true;
}

bool search_exit(std::string &str)
{
    return false;
}
void search_info()
{
    bool (*const f[4])(std::string &) = {search_student, search_course, search_grade, search_exit};
    ui::choose(f, "查询信息", "请选择需要查询的信息类型", 4, "学生信息", "课程信息", "成绩信息", "退出查询");
}