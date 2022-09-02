#include "../include/saves_manager.h"
#include <io.h>
#include <direct.h>
#include <iostream>
#include <string>
#include "const.h"

void init_saves_dir()
{
    CreateFolder(save_path);
}

//（需要 #include <io.h> 以及 #include <direct.h>）
// 创建文件夹
bool CreateFolder(const char folderName[])
{
    if (_access(folderName, 0) == -1)
    {
        // SET_TEXT_WARNING();
        std::cout << "文件夹" << folderName << "不存在, 尝试创建此文件夹..." << std::endl;
        if (_mkdir(folderName) == 0)
        { //创建成功
            // SET_TEXT_SUCCESS();
            std::cout << "创建文件夹 " << folderName << " 成功！" << std::endl;
            return true;
        }
        else
        {
            // SET_TEXT_WARNING();
            std::cout << "创建文件夹 " << folderName << " 失败！" << std::endl;
            return false;
        }
    }
    return true;
}

bool MakeSaveFile(const char fileName[])
{
    std::fstream f(fileName, std::ios_base::in);
    if (!f.good())
    {
        // SET_TEXT_WARNING();
        std::cout << "存档文件" << fileName << "打开失败。尝试创建此文件..." << std::endl;
        f.close();
        f.clear();
        f.open(fileName, std::ios_base::out);
        if (f.good())
        {
            // SET_TEXT_SUCCESS();
            std::cout << "创建文件 " << fileName << " 成功！" << std::endl;
            f.close();
            return true;
        }
        else
        {
            // SET_TEXT_WARNING();
            std::cout << "创建文件 " << fileName << " 失败！" << std::endl;
            f.close();
            return false;
        }
    }
    return true;
}

bool save_grade_data(const std::list<grade_info> &grades)
{
    if (!CreateFolder(save_path))
    {
        return false;
    }
    std::string save_file_path = grade_path;
    if (!MakeSaveFile(save_file_path.c_str()))
    {
        return false;
    }
    std::fstream fout(save_file_path, std::ios_base::out | std::ios_base::trunc);
    if (!fout.good())
    {
        std::cout << "文件" << save_file_path << "打开失败!" << std::endl;
        fout.close();
        return false;
    }
    else
    {
        fout << grades.size() << std::endl;
        for (typename std::list<grade_info>::const_iterator i = grades.begin(); i != grades.end(); i++)
        {
            fout
                << i->get_id()
                << '\t' << i->get_course_first_id()
                << '\t' << i->get_course_second_id()
                << '\t' << i->get_grade_type()
                << '\t' << i->get_course_type()
                << '\t' << i->get_grade_level()
                << '\t' << i->get_grade_point()
                << '\t' << i->get_percent()
                << std::endl;
        }
        fout.close();
        return true;
    }
}

bool read_grade_data(std::list<grade_info> &grades, const char *file_path, const std::list<student_info> &students, const std::list<course_info> &courses)
{
    std::fstream fin(file_path, std::ios_base::in);
    if (!fin.good())
    {
        std::cout << "文件" << file_path << "打开失败!" << std::endl;
        return false;
    }
    else
    {
        int count = 0;
        std::string id;
        std::string first_id;
        std::string second_id;
        std::string grade_type;
        std::string course_type;
        std::string grade_level;
        std::string grade_point;
        std::string percent;
        fin >> count;
        for (int i = 0; i < count; i++)
        {
            fin >> id;
            fin >> first_id;
            fin >> second_id;
            student_info si(utility::search_student(id, students));
            if (si == null_student)
            {
                std::cout << "line " << count + 1 << ": 请先添加学生！学号：" << id << std::endl;
                return false;
            }
            course_info ci(utility::search_course(first_id, second_id, courses));
            if (ci == null_course)
            {
                std::cout << "line  " << count + 1 << ": 请先添加课程！课程号：" << first_id << " 课序号：" << second_id << std::endl;
                return false;
            }
            fin >> grade_type >> course_type >> grade_level >> grade_point >> percent;
            grades.push_back(
                grade_info(
                    si.get_id(), si.get_name(), si.get_class_name(), si.get_grade(), si.get_academy(),
                    ci.get_course_first_id(), ci.get_course_second_id(), ci.get_course_name(), ci.get_course_semester(), ci.get_course_teacher(), ci.get_course_point(),
                    grade_type, course_type, grade_level, grade_point, percent));
        }
        return true;
    }
}