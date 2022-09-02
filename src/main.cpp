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
    str = "��л����ʹ�ã�";
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

    std::cout << "��ȡ�浵..." << std::endl;
    init_saves();
    // MakeSaveFile(student_path);
    if (!(read_data(students, student_path) &&
          read_data(courses, course_path) &&
          read_grade_data(grades, grade_path, students, courses)))
    {
        std::cout << "�浵��ȡʧ�ܣ�" << std::endl;
        system("pause");
        return -1;
    }
    ui::choose(f, "ѧ���ɼ�����ϵͳ", "��ѡ����Ҫ���еĲ���", 3, "��ѯ��Ϣ�Լ�ͳ�Ʋ�ѯ���", "��ӡ�ɾ�����޸���Ϣ", "�˳�����");
    system("pause");
    return 0;
}