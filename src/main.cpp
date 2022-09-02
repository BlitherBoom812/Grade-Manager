#include <iostream>
#include <list>
#include "../include/info.h"
#include "../include/ui.h"
#include "../include/saves_manager.h"
#include "../include/search_info.h"
#include "change_data.h"
#include "const.h"

bool f1(std::string &str)
{
    str = "";
    search_info();
    return true;
}

bool f2(std::string &str)
{
    str = "";
    change_data();
    return true;
}

bool f3(std::string &str)
{
    str = "感谢您的使用！";
    return false;
}

void init_saves()
{
    init_saves_dir();
    MakeSaveFile(student_path);
    MakeSaveFile(course_path);
    MakeSaveFile(grade_path);
}

// global variables
std::list<student_info> students;
std::list<course_info> courses;
std::list<grade_info> grades;

int main()
{
    bool (*const f[3])(std::string &) = {f1, f2, f3};

    std::cout << "读取存档..." << std::endl;
    init_saves();
    // MakeSaveFile(student_path);
    if (!(read_data(students, student_path) &&
          read_data(courses, course_path) &&
          read_grade_data(grades, grade_path, students, courses)))
    {
        std::cout << "存档读取失败！" << std::endl;
        system("pause");
        return -1;
    }
    ui::choose(f, "学生成绩管理系统", "请选择需要进行的操作", 3, "查询信息以及统计查询结果", "添加、删除或修改信息", "退出程序");
    system("pause");
    return 0;
}