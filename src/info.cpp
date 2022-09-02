#include "../include/info.h"
#include <limits>
#include "../include/ui.h"
#include <iomanip>
#include "const.h"
std::istream &operator>>(std::istream &in, basic_info &info)
{
    info.input(in);
    return in;
}
std::ostream &operator<<(std::ostream &out, const basic_info &info)
{
    info.print(out);
    return out;
}

void student_info::input(std::istream &in)
{
    in >> id >> name >> class_name >> grade >> academy;
}
void student_info::print(std::ostream &out) const
{
    out << std::setw(width_id) << id << std::setw(width_name) << name << std::setw(6) << class_name << std::setw(6) << grade << std::setw(16) << academy;
}
bool student_info::input_guide()
{

    std::cout << "学号:" << std::endl;
    std::string command = ui::command();
    if (command == "back")
    {
        return false;
    }

    if (command == "all")
    {
        id = "*";
        name = "*";
        class_name = "*";
        grade = "*";
        academy = "*";
        return true;
    }
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "姓名:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "班级:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> class_name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "年级:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> grade;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "院系:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> academy;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return true;
}
bool student_info::operator==(const student_info &cmp) const
{
    return (
        (id == "*" || cmp.id == "*" || id == cmp.id) &&
        (name == "*" || cmp.name == "*" || name == cmp.name) &&
        (class_name == "*" || cmp.class_name == "*" || class_name == cmp.class_name) &&
        (grade == "*" || cmp.grade == "*" || grade == cmp.grade) &&
        (academy == "*" || cmp.academy == "*" || academy == cmp.academy));
}
const student_info &student_info::operator=(const student_info &cp)
{
    id = cp.id;
    name = cp.name;
    class_name = cp.class_name;
    grade = cp.grade;
    academy = cp.academy;
    return cp;
}
const std::string &student_info::get_id() const
{
    return id;
} //学号
const std::string &student_info::get_name() const
{
    return name;
} //姓名
const std::string &student_info::get_class_name() const
{
    return class_name;
} //班级
const std::string &student_info::get_grade() const
{
    return grade;
} //年级
const std::string &student_info::get_academy() const
{
    return academy;
} //院系
void student_info::set_id(const std::string &str)
{
    id = str;
} //学号
void student_info::set_name(const std::string &str)
{
    name = str;
} //姓名
void student_info::set_class_name(const std::string &str)
{
    class_name = str;
} //班级
void student_info::set_grade(const std::string &str)
{
    grade = str;
} //年级
void student_info::set_academy(const std::string &str)
{
    academy = str;
} //院系
void course_info::input(std::istream &in)
{
    in >> course_first_id >> course_second_id >> course_name >> course_semester >> course_teacher >> course_point;
}
void course_info::print(std::ostream &out) const
{

    out << std::setw(width_course_first_id) << course_first_id << std::setw(widtch_course_second_id) << course_second_id << std::setw(width_course_name) << course_name << std::setw(10) << course_semester << std::setw(10) << course_teacher << std::setw(6) << course_point;
}
bool course_info::operator==(const course_info &cmp) const
{
    return (
        (course_first_id == "*" || cmp.course_first_id == "*" || course_first_id == cmp.course_first_id) &&
        (course_second_id == "*" || cmp.course_second_id == "*" || course_second_id == cmp.course_second_id) &&
        (course_name == "*" || cmp.course_name == "*" || course_name == cmp.course_name) &&
        (course_semester == "*" || cmp.course_semester == "*" || course_semester == cmp.course_semester) &&
        (course_teacher == "*" || cmp.course_teacher == "*" || course_teacher == cmp.course_teacher) &&
        (course_point == "*" || cmp.course_point == "*" || course_point == cmp.course_point));
}
const course_info &course_info::operator=(const course_info &cp)
{
    course_first_id = cp.course_first_id;
    course_second_id = cp.course_second_id;
    course_name = cp.course_name;
    course_semester = cp.course_semester;
    course_teacher = cp.course_teacher;
    course_point = cp.course_point;
    return cp;
}
bool course_info::input_guide()
{
    std::cout << "课程号:" << std::endl;
    std::string command = ui::command();
    if (command == "back")
    {
        return false;
    }
    if (command == "all")
    {
        course_first_id = "*";
        course_second_id = "*";
        course_name = "*";
        course_semester = "*";
        course_teacher = "*";
        course_point = "*";
        return true;
    }
    std::cin >> course_first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "课序号:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "课程名:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "授课学期:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_semester;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "任课老师:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_teacher;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "学分:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_point;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return true;
}

const std::string &course_info::get_course_first_id() const
{
    return course_first_id;
}
const std::string &course_info::get_course_second_id() const
{
    return course_second_id;
} //课序号
const std::string &course_info::get_course_name() const
{
    return course_name;
} //课程名
const std::string &course_info::get_course_semester() const
{
    return course_semester;
} //授课学期
const std::string &course_info::get_course_teacher() const
{
    return course_teacher;
} //任课老师
const std::string &course_info::get_course_point() const
{
    return course_point;
} //学分
void course_info::set_course_first_id(const std::string &str)
{
    course_first_id = str;
} //课程号
void course_info::set_course_second_id(const std::string &str)
{
    course_second_id = str;
} //课序号
void course_info::set_course_name(const std::string &str)
{
    course_name = str;
} //课程名
void course_info::set_course_semester(const std::string &str)
{
    course_semester = str;
} //授课学期
void course_info::set_course_teacher(const std::string &str)
{
    course_teacher = str;
} //任课老师
void course_info::set_course_point(const std::string &str)
{
    course_point = str;
} //学分

void grade_info::input(std::istream &in)
{
    student_info::input(in);
    course_info::input(in);
    in >> grade_type >> course_type >> grade >> grade_point >> percent;
}
void grade_info::print(std::ostream &out) const
{
    student_info::print(out);
    course_info::print(out);
    out << std::setw(8) << grade_type << std::setw(10) << course_type << std::setw(6) << grade_level << std::setw(6) << grade_point << std::setw(12) << percent;
}
bool grade_info::input_guide()
{

    std::cout << "学号:" << std::endl;
    std::string command = ui::command();
    if (command == "back")
    {
        return false;
    }

    if (command == "all")
    {
        id = "*";
        name = "*";
        class_name = "*";
        grade = "*";
        academy = "*";
        course_first_id = "*";
        course_second_id = "*";
        course_name = "*";
        course_semester = "*";
        course_teacher = "*";
        course_point = "*";
        grade_type = "*";
        course_type = "*";
        grade_point = "*";
        grade_level = "*";
        percent = "*";
        return true;
    }
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "姓名:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "班级:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> class_name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "年级:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> grade;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "院系:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> academy;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "课程号:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "课序号:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "课程名:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "授课学期:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_semester;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "任课老师:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_teacher;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "学分:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_point;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "评分制(PF制或等级制): ";
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> grade_type;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "课程类型(必修，限选或任选): ";
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_type;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "等级: ";
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> grade_level;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "绩点: ";
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> grade_point;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "百分制成绩: ";
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> percent;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return true;
}
bool grade_info::operator==(const grade_info &cmp) const
{
    return (
        student_info::operator==(cmp) &&
        course_info::operator==(cmp) &&
        (grade_type == "*" || cmp.grade_type == "*" || grade_type == cmp.grade_type) &&
        (course_type == "*" || cmp.course_type == "*" || course_type == cmp.course_type) &&
        (grade_level == "*" || cmp.grade_level == "*" || grade_level == cmp.grade_level) &&
        (grade_point == "*" || cmp.grade_point == "*" || grade_point == cmp.grade_point) &&
        (percent == "*" || cmp.percent == "*" || percent == cmp.percent));
}
const grade_info &grade_info::operator=(const grade_info &cp)
{
    student_info::operator=(cp);
    course_info::operator=(cp);
    grade_type = cp.grade_type;
    course_type = cp.course_type;
    grade_level = cp.grade_level;
    grade_point = cp.grade_point;
    percent = cp.percent;
    return cp;
}
const std::string &grade_info::get_grade_type() const
{
    return grade_type;
} //评分制(PF制，等级制)
const std::string &grade_info::get_course_type() const
{
    return course_type;
} //课程类型（必修，限选，任选）
const std::string &grade_info::get_grade_level() const
{
    return grade_level;
} //等级
const std::string &grade_info::get_grade_point() const
{
    return grade_point;
} //绩点
const std::string &grade_info::get_percent() const
{
    return percent;
} //百分制成绩
void grade_info::set_grade_type(const std::string &str)
{
    grade_type = str;
} //评分制(PF制，等级制)
void grade_info::set_course_type(const std::string &str)
{
    course_type = str;
} //课程类型（必修，限选，任选）
void grade_info::set_grade_level(const std::string &str)
{
    grade_level = str;
} //等级
void grade_info::set_grade_point(const std::string &str)
{
    grade_point = str;
} //绩点
void grade_info::set_percent(const std::string &str)
{
    percent = str;
} //百分制成绩