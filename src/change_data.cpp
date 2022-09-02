#include "change_data.h"
#include "ui.h"
#include "utility.h"
#include "info.h"
#include "saves_manager.h"
#include <string>
#include <list>
#include <cctype>
#include <sstream>
#include <limits>
#include "const.h"
extern std::list<student_info> students;
extern std::list<course_info> courses;
extern std::list<grade_info> grades;
bool exit_change(std::string &str);

bool add_student_info(std::string &str)
{
    student_info si;
    if (!si.input_guide())
    {
        return true;
    }
    if (utility::contains_student(si.get_id(), students))
    {
        str = "操作失败！此学生已经存在。";
        return true;
    }
    else
    {
        students.push_back(si);
        if (save_data(students, student_file_name))
        {
            str = "操作成功！已保存至文件。";
            return true;
        }
        else
        {
            str = "操作失败！未能保存至文件。";
            return true;
        }
    }
}
bool add_course_info(std::string &str)
{
    course_info ci;
    if (!ci.input_guide())
    {
        return true;
    }
    if (utility::contains_course(ci.get_course_first_id(), ci.get_course_second_id(), courses))
    {
        str = "操作失败！此课程已经存在。";
        return true;
    }
    else
    {
        courses.push_back(ci);
        if (save_data(courses, course_file_name))
        {
            str = "操作成功！已保存至文件。";
            return true;
        }
        else
        {
            str = "操作失败！未能保存至文件。";
            return true;
        }
    }
}
bool add_grade_info(std::string &str)
{
    grade_info gi;
    std::cout << "学号：";
    std::string id;
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    student_info si;
    if ((si = utility::search_student(id, students)) == null_student)
    {
        str = "操作失败！此学生不存在。";
        return true;
    }
    std::cout << "查找到学生：" << std::endl;
    std::cout << si << std::endl;

    std::string first_id;
    std::string second_id;
    std::cout << "课程号：";
    std::cin >> first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "课序号：";
    std::cin >> second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    course_info ci;
    if ((ci = utility::search_course(first_id, second_id, courses)) == null_course)
    {
        str = "操作失败！此课程不存在。";
        return true;
    }
    std::cout << "查找到课程：" << std::endl;
    std::cout << ci << std::endl;

    if (utility::contains_grade(id, first_id, second_id, grades))
    {
        str = "操作失败！此成绩已经存在。";
        return true;
    }

    gi.set_id(si.get_id());
    gi.set_name(si.get_name());
    gi.set_class_name(si.get_class_name());
    gi.set_grade(si.get_grade());
    gi.set_academy(si.get_academy());

    gi.set_course_first_id(ci.get_course_first_id());
    gi.set_course_second_id(ci.get_course_second_id());
    gi.set_course_name(ci.get_course_name());
    gi.set_course_teacher(ci.get_course_teacher());
    gi.set_course_semester(ci.get_course_semester());
    gi.set_course_point(ci.get_course_point());

    std::string buf;
    std::cout << "评分制(等级制, PF制): ";
    std::cin >> buf;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gi.set_grade_type(buf);
    std::cout << "课程类型(必修，限选，任选): ";
    std::cin >> buf;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gi.set_course_type(buf);
    std::cout << "等级: ";
    std::cin >> buf;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gi.set_grade_level(buf);
    std::cout << "绩点: ";
    std::cin >> buf;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gi.set_grade_point(buf);
    std::cout << "百分制成绩(没有则写-): ";
    std::cin >> buf;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gi.set_percent(buf);

    grades.push_back(gi);
    if (save_grade_data(grades))
    {
        str = "操作成功！已保存至文件。";
        return true;
    }
    else
    {
        str = "操作失败！未能保存至文件。";
        return true;
    }
}
bool add_info(std::string &str)
{
    const choice c[4] = {add_student_info, add_course_info, add_grade_info, exit_change};
    ui::choose(c, "添加信息", "请选择添加的信息类型", 4, "学生信息", "课程信息", "成绩信息", "退出");
    return true;
}
bool delete_student_info(std::string &str)
{
    std::string id;
    std::cout << "请输入学号: ";
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (utility::contains_student(id, students))
    {
        std::cout << "是否删除此学生：\n"
                  << utility::search_student(id, students) << std::endl;
        std::cout << "[A]是\n[B]否\n";
        switch (std::toupper(ui::peek_strip(std::cin)))
        {
        case 'A':
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (utility::erase_student(id, students, grades))
            {
                str = "删除成功！";
                save_data(students, student_file_name);
                save_grade_data(grades);
                return true;
            }
            else
            {
                str = "删除失败!";
                return true;
            }
            break;
        case 'B':
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        }
    }
    else
    {
        str = "不存在此学生。";
        return true;
    }
}
bool delete_grade_info(std::string &str)
{
    std::string id;
    std::cout << "请输入学号: ";
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string first_id;
    std::cout << "请输入课程号: ";
    std::cin >> first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string second_id;
    std::cout << "请输入课序号: ";
    std::cin >> second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (utility::contains_grade(id, first_id, second_id, grades))
    {
        std::cout << "是否删除此成绩信息：\n"
                  << utility::search_grade(id, first_id, second_id, grades) << std::endl;
        std::cout << "[A]是\n[B]否\n";
        switch (std::toupper(ui::peek_strip(std::cin)))
        {
        case 'A':
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (utility::erase_grade(id, first_id, second_id, grades))
            {
                str = "删除成功！";
                save_grade_data(grades);
                return true;
            }
            else
            {
                str = "删除失败!";
                return true;
            }
            break;
        case 'B':
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        }
    }
    else
    {
        str = "不存在此成绩信息。";
        return true;
    }
}
bool delete_course_info(std::string &str)
{

    std::string first_id;
    std::cout << "请输入课程号: ";
    std::cin >> first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string second_id;
    std::cout << "请输入课序号: ";
    std::cin >> second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (utility::contains_course(first_id, second_id, courses))
    {
        std::cout << "是否删除此课程：\n"
                  << utility::search_course(first_id, second_id, courses) << std::endl;
        std::cout << "[A]是\n[B]否\n";
        switch (std::toupper(ui::peek_strip(std::cin)))
        {
        case 'A':
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (utility::erase_course(first_id, second_id, courses, grades))
            {
                str = "删除成功！";
                save_data(courses, course_file_name);
                save_grade_data(grades);
                return true;
            }
            else
            {
                str = "删除失败!";
                return true;
            }
            break;
        case 'B':
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true;
        }
    }
    else
    {
        str = "不存在此课程。";
        return true;
    }
}
bool delete_info(std::string &str)
{
    const choice c[4] = {delete_student_info, delete_course_info, delete_grade_info, exit_change};
    ui::choose(c, "删除信息", "请选择删除的信息类型", 4, "学生信息", "课程信息", "成绩信息", "退出");
    return true;
}
bool revise_student_info(std::string &str)
{
    std::cout << "学号：";
    std::string id;
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    student_info si;

    if ((si = utility::search_student(id, students)) == null_student)
    {
        str = "操作失败！此学生不存在。";
        return true;
    }

    std::cout << "查找到学生：" << std::endl;
    std::cout << si << std::endl;
    std::cout << "是否修改:\n[A]是\n[B]否\n";

    switch (std::toupper(ui::peek_strip(std::cin)))
    {
    case 'A':
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "输入修改后的信息: \n（如无需修改可以按回车跳过）\n";
        std::string buf;

        std::cout << "姓名: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            si.set_name(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "班级: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            si.set_class_name(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "年级: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            si.set_grade(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "院系: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            si.set_academy(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        for (std::list<student_info>::iterator i = students.begin(); i != students.end(); i++)
        {
            if (i->get_id() == id)
            {
                *i = si;
                break;
            }
        }

        save_data(students, student_file_name);

        std::ostringstream oss;
        oss << "修改完毕！修改后的信息为: \n"
            << si << std::endl;
        str = oss.str();

        return true;
    }

    break;
    case 'B':
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
        break;
    default:
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
        break;
    }
    return true;
}
bool revise_course_info(std::string &str)
{
    std::cout << "课程号: ";
    std::string first_id;
    std::cin >> first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "课序号: ";
    std::string second_id;
    std::cin >> second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    course_info ci;

    if ((ci = utility::search_course(first_id, second_id, courses)) == null_course)
    {
        str = "操作失败！此课程不存在。";
        return true;
    }

    std::cout << "查找到课程：" << std::endl;
    std::cout << ci << std::endl;
    std::cout << "是否修改:\n[A]是\n[B]否\n";

    switch (std::toupper(ui::peek_strip(std::cin)))
    {
    case 'A':
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "输入修改后的信息: \n（如无需修改可以按回车跳过）\n";
        std::string buf;

        std::cout << "课程名: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            ci.set_course_name(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "授课学期: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            ci.set_course_semester(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "任课老师: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            ci.set_course_teacher(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "学分: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            ci.set_course_point(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        for (std::list<course_info>::iterator i = courses.begin(); i != courses.end(); i++)
        {
            if (i->get_course_first_id() == first_id && i->get_course_second_id() == second_id)
            {
                *i = ci;
                break;
            }
        }

        save_data(courses, course_file_name);

        std::ostringstream oss;
        oss << "修改完毕！修改后的信息为: \n"
            << ci << std::endl;
        str = oss.str();

        return true;
    }

    break;
    case 'B':
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
        break;
    default:
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
        break;
    }
    return true;
}
bool revise_grade_info(std::string &str)
{
    std::cout << "学号: ";
    std::string id;
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "课程号: ";
    std::string first_id;
    std::cin >> first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "课序号: ";
    std::string second_id;
    std::cin >> second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    grade_info gi;
    if ((gi = utility::search_grade(id, first_id, second_id, grades)) == null_grade)
    {
        str = "操作失败！此成绩信息不存在。";
        return true;
    }

    std::cout << "查找到信息：" << std::endl;
    std::cout << gi << std::endl;
    std::cout << "是否修改:\n[A]是\n[B]否\n";

    switch (std::toupper(ui::peek_strip(std::cin)))
    {
    case 'A':
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "输入修改后的信息: \n（如无需修改可以按回车跳过）\n";
        std::string buf;

        std::cout << "评分制(等级制, PF制): ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            gi.set_grade_type(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "课程类型(必修, 限选, 任选): ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            gi.set_course_type(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "等级: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            gi.set_grade_level(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "绩点: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            gi.set_grade_point(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "百分制成绩(没有则输入-): ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            gi.set_percent(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        for (std::list<grade_info>::iterator i = grades.begin(); i != grades.end(); i++)
        {
            if (i->get_id() == id && i->get_course_first_id() == first_id && i->get_course_second_id() == second_id)
            {
                *i = gi;
                break;
            }
        }

        save_grade_data(grades);

        std::ostringstream oss;
        oss << "修改完毕！修改后的信息为: \n"
            << gi << std::endl;
        str = oss.str();

        return true;
    }

    break;
    case 'B':
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
        break;
    default:
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return true;
        break;
    }
    return true;
}
bool revise_info(std::string &str)
{
    const choice c[4] = {revise_student_info, revise_course_info, revise_grade_info, exit_change};
    ui::choose(c, "修改信息", "请选择修改的信息类型", 4, "学生信息", "课程信息", "成绩信息", "退出");
    return true;
}
bool exit_change(std::string &str)
{
    return false;
}
void change_data()
{
    const choice c[4] = {add_info, delete_info, revise_info, exit_change};
    ui::choose(c, "增删信息", "请选择操作", 4, "添加信息", "删除信息", "修改信息", "退出信息修改");
}
