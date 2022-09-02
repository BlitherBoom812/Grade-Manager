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

    std::cout << "ѧ��:" << std::endl;
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

    std::cout << "����:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "�༶:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> class_name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�꼶:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> grade;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ժϵ:" << std::endl;
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
} //ѧ��
const std::string &student_info::get_name() const
{
    return name;
} //����
const std::string &student_info::get_class_name() const
{
    return class_name;
} //�༶
const std::string &student_info::get_grade() const
{
    return grade;
} //�꼶
const std::string &student_info::get_academy() const
{
    return academy;
} //Ժϵ
void student_info::set_id(const std::string &str)
{
    id = str;
} //ѧ��
void student_info::set_name(const std::string &str)
{
    name = str;
} //����
void student_info::set_class_name(const std::string &str)
{
    class_name = str;
} //�༶
void student_info::set_grade(const std::string &str)
{
    grade = str;
} //�꼶
void student_info::set_academy(const std::string &str)
{
    academy = str;
} //Ժϵ
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
    std::cout << "�γ̺�:" << std::endl;
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

    std::cout << "�����:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�γ���:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�ڿ�ѧ��:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_semester;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�ο���ʦ:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_teacher;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "ѧ��:" << std::endl;
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
} //�����
const std::string &course_info::get_course_name() const
{
    return course_name;
} //�γ���
const std::string &course_info::get_course_semester() const
{
    return course_semester;
} //�ڿ�ѧ��
const std::string &course_info::get_course_teacher() const
{
    return course_teacher;
} //�ο���ʦ
const std::string &course_info::get_course_point() const
{
    return course_point;
} //ѧ��
void course_info::set_course_first_id(const std::string &str)
{
    course_first_id = str;
} //�γ̺�
void course_info::set_course_second_id(const std::string &str)
{
    course_second_id = str;
} //�����
void course_info::set_course_name(const std::string &str)
{
    course_name = str;
} //�γ���
void course_info::set_course_semester(const std::string &str)
{
    course_semester = str;
} //�ڿ�ѧ��
void course_info::set_course_teacher(const std::string &str)
{
    course_teacher = str;
} //�ο���ʦ
void course_info::set_course_point(const std::string &str)
{
    course_point = str;
} //ѧ��

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

    std::cout << "ѧ��:" << std::endl;
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

    std::cout << "����:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "�༶:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> class_name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�꼶:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> grade;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ժϵ:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> academy;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�γ̺�:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�����:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�γ���:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_name;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�ڿ�ѧ��:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_semester;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�ο���ʦ:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_teacher;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "ѧ��:" << std::endl;
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_point;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "������(PF�ƻ�ȼ���): ";
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> grade_type;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�γ�����(���ޣ���ѡ����ѡ): ";
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> course_type;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�ȼ�: ";
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> grade_level;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "����: ";
    if (ui::command() == "back")
    {
        return false;
    }
    std::cin >> grade_point;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�ٷ��Ƴɼ�: ";
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
} //������(PF�ƣ��ȼ���)
const std::string &grade_info::get_course_type() const
{
    return course_type;
} //�γ����ͣ����ޣ���ѡ����ѡ��
const std::string &grade_info::get_grade_level() const
{
    return grade_level;
} //�ȼ�
const std::string &grade_info::get_grade_point() const
{
    return grade_point;
} //����
const std::string &grade_info::get_percent() const
{
    return percent;
} //�ٷ��Ƴɼ�
void grade_info::set_grade_type(const std::string &str)
{
    grade_type = str;
} //������(PF�ƣ��ȼ���)
void grade_info::set_course_type(const std::string &str)
{
    course_type = str;
} //�γ����ͣ����ޣ���ѡ����ѡ��
void grade_info::set_grade_level(const std::string &str)
{
    grade_level = str;
} //�ȼ�
void grade_info::set_grade_point(const std::string &str)
{
    grade_point = str;
} //����
void grade_info::set_percent(const std::string &str)
{
    percent = str;
} //�ٷ��Ƴɼ�