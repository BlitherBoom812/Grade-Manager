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
        str = "����ʧ�ܣ���ѧ���Ѿ����ڡ�";
        return true;
    }
    else
    {
        students.push_back(si);
        if (save_data(students, student_file_name))
        {
            str = "�����ɹ����ѱ������ļ���";
            return true;
        }
        else
        {
            str = "����ʧ�ܣ�δ�ܱ������ļ���";
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
        str = "����ʧ�ܣ��˿γ��Ѿ����ڡ�";
        return true;
    }
    else
    {
        courses.push_back(ci);
        if (save_data(courses, course_file_name))
        {
            str = "�����ɹ����ѱ������ļ���";
            return true;
        }
        else
        {
            str = "����ʧ�ܣ�δ�ܱ������ļ���";
            return true;
        }
    }
}
bool add_grade_info(std::string &str)
{
    grade_info gi;
    std::cout << "ѧ�ţ�";
    std::string id;
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    student_info si;
    if ((si = utility::search_student(id, students)) == null_student)
    {
        str = "����ʧ�ܣ���ѧ�������ڡ�";
        return true;
    }
    std::cout << "���ҵ�ѧ����" << std::endl;
    std::cout << si << std::endl;

    std::string first_id;
    std::string second_id;
    std::cout << "�γ̺ţ�";
    std::cin >> first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "����ţ�";
    std::cin >> second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    course_info ci;
    if ((ci = utility::search_course(first_id, second_id, courses)) == null_course)
    {
        str = "����ʧ�ܣ��˿γ̲����ڡ�";
        return true;
    }
    std::cout << "���ҵ��γ̣�" << std::endl;
    std::cout << ci << std::endl;

    if (utility::contains_grade(id, first_id, second_id, grades))
    {
        str = "����ʧ�ܣ��˳ɼ��Ѿ����ڡ�";
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
    std::cout << "������(�ȼ���, PF��): ";
    std::cin >> buf;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gi.set_grade_type(buf);
    std::cout << "�γ�����(���ޣ���ѡ����ѡ): ";
    std::cin >> buf;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gi.set_course_type(buf);
    std::cout << "�ȼ�: ";
    std::cin >> buf;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gi.set_grade_level(buf);
    std::cout << "����: ";
    std::cin >> buf;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gi.set_grade_point(buf);
    std::cout << "�ٷ��Ƴɼ�(û����д-): ";
    std::cin >> buf;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gi.set_percent(buf);

    grades.push_back(gi);
    if (save_grade_data(grades))
    {
        str = "�����ɹ����ѱ������ļ���";
        return true;
    }
    else
    {
        str = "����ʧ�ܣ�δ�ܱ������ļ���";
        return true;
    }
}
bool add_info(std::string &str)
{
    const choice c[4] = {add_student_info, add_course_info, add_grade_info, exit_change};
    ui::choose(c, "�����Ϣ", "��ѡ����ӵ���Ϣ����", 4, "ѧ����Ϣ", "�γ���Ϣ", "�ɼ���Ϣ", "�˳�");
    return true;
}
bool delete_student_info(std::string &str)
{
    std::string id;
    std::cout << "������ѧ��: ";
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (utility::contains_student(id, students))
    {
        std::cout << "�Ƿ�ɾ����ѧ����\n"
                  << utility::search_student(id, students) << std::endl;
        std::cout << "[A]��\n[B]��\n";
        switch (std::toupper(ui::peek_strip(std::cin)))
        {
        case 'A':
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (utility::erase_student(id, students, grades))
            {
                str = "ɾ���ɹ���";
                save_data(students, student_file_name);
                save_grade_data(grades);
                return true;
            }
            else
            {
                str = "ɾ��ʧ��!";
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
        str = "�����ڴ�ѧ����";
        return true;
    }
}
bool delete_grade_info(std::string &str)
{
    std::string id;
    std::cout << "������ѧ��: ";
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string first_id;
    std::cout << "������γ̺�: ";
    std::cin >> first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string second_id;
    std::cout << "����������: ";
    std::cin >> second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (utility::contains_grade(id, first_id, second_id, grades))
    {
        std::cout << "�Ƿ�ɾ���˳ɼ���Ϣ��\n"
                  << utility::search_grade(id, first_id, second_id, grades) << std::endl;
        std::cout << "[A]��\n[B]��\n";
        switch (std::toupper(ui::peek_strip(std::cin)))
        {
        case 'A':
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (utility::erase_grade(id, first_id, second_id, grades))
            {
                str = "ɾ���ɹ���";
                save_grade_data(grades);
                return true;
            }
            else
            {
                str = "ɾ��ʧ��!";
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
        str = "�����ڴ˳ɼ���Ϣ��";
        return true;
    }
}
bool delete_course_info(std::string &str)
{

    std::string first_id;
    std::cout << "������γ̺�: ";
    std::cin >> first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string second_id;
    std::cout << "����������: ";
    std::cin >> second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (utility::contains_course(first_id, second_id, courses))
    {
        std::cout << "�Ƿ�ɾ���˿γ̣�\n"
                  << utility::search_course(first_id, second_id, courses) << std::endl;
        std::cout << "[A]��\n[B]��\n";
        switch (std::toupper(ui::peek_strip(std::cin)))
        {
        case 'A':
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (utility::erase_course(first_id, second_id, courses, grades))
            {
                str = "ɾ���ɹ���";
                save_data(courses, course_file_name);
                save_grade_data(grades);
                return true;
            }
            else
            {
                str = "ɾ��ʧ��!";
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
        str = "�����ڴ˿γ̡�";
        return true;
    }
}
bool delete_info(std::string &str)
{
    const choice c[4] = {delete_student_info, delete_course_info, delete_grade_info, exit_change};
    ui::choose(c, "ɾ����Ϣ", "��ѡ��ɾ������Ϣ����", 4, "ѧ����Ϣ", "�γ���Ϣ", "�ɼ���Ϣ", "�˳�");
    return true;
}
bool revise_student_info(std::string &str)
{
    std::cout << "ѧ�ţ�";
    std::string id;
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    student_info si;

    if ((si = utility::search_student(id, students)) == null_student)
    {
        str = "����ʧ�ܣ���ѧ�������ڡ�";
        return true;
    }

    std::cout << "���ҵ�ѧ����" << std::endl;
    std::cout << si << std::endl;
    std::cout << "�Ƿ��޸�:\n[A]��\n[B]��\n";

    switch (std::toupper(ui::peek_strip(std::cin)))
    {
    case 'A':
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "�����޸ĺ����Ϣ: \n���������޸Ŀ��԰��س�������\n";
        std::string buf;

        std::cout << "����: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            si.set_name(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "�༶: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            si.set_class_name(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "�꼶: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            si.set_grade(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ժϵ: ";
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
        oss << "�޸���ϣ��޸ĺ����ϢΪ: \n"
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
    std::cout << "�γ̺�: ";
    std::string first_id;
    std::cin >> first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�����: ";
    std::string second_id;
    std::cin >> second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    course_info ci;

    if ((ci = utility::search_course(first_id, second_id, courses)) == null_course)
    {
        str = "����ʧ�ܣ��˿γ̲����ڡ�";
        return true;
    }

    std::cout << "���ҵ��γ̣�" << std::endl;
    std::cout << ci << std::endl;
    std::cout << "�Ƿ��޸�:\n[A]��\n[B]��\n";

    switch (std::toupper(ui::peek_strip(std::cin)))
    {
    case 'A':
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "�����޸ĺ����Ϣ: \n���������޸Ŀ��԰��س�������\n";
        std::string buf;

        std::cout << "�γ���: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            ci.set_course_name(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "�ڿ�ѧ��: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            ci.set_course_semester(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "�ο���ʦ: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            ci.set_course_teacher(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "ѧ��: ";
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
        oss << "�޸���ϣ��޸ĺ����ϢΪ: \n"
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
    std::cout << "ѧ��: ";
    std::string id;
    std::cin >> id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�γ̺�: ";
    std::string first_id;
    std::cin >> first_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "�����: ";
    std::string second_id;
    std::cin >> second_id;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    grade_info gi;
    if ((gi = utility::search_grade(id, first_id, second_id, grades)) == null_grade)
    {
        str = "����ʧ�ܣ��˳ɼ���Ϣ�����ڡ�";
        return true;
    }

    std::cout << "���ҵ���Ϣ��" << std::endl;
    std::cout << gi << std::endl;
    std::cout << "�Ƿ��޸�:\n[A]��\n[B]��\n";

    switch (std::toupper(ui::peek_strip(std::cin)))
    {
    case 'A':
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "�����޸ĺ����Ϣ: \n���������޸Ŀ��԰��س�������\n";
        std::string buf;

        std::cout << "������(�ȼ���, PF��): ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            gi.set_grade_type(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "�γ�����(����, ��ѡ, ��ѡ): ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            gi.set_course_type(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "�ȼ�: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            gi.set_grade_level(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "����: ";
        if (std::cin.peek() > 32)
        {
            std::cin >> buf;
            gi.set_grade_point(buf);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "�ٷ��Ƴɼ�(û��������-): ";
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
        oss << "�޸���ϣ��޸ĺ����ϢΪ: \n"
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
    ui::choose(c, "�޸���Ϣ", "��ѡ���޸ĵ���Ϣ����", 4, "ѧ����Ϣ", "�γ���Ϣ", "�ɼ���Ϣ", "�˳�");
    return true;
}
bool exit_change(std::string &str)
{
    return false;
}
void change_data()
{
    const choice c[4] = {add_info, delete_info, revise_info, exit_change};
    ui::choose(c, "��ɾ��Ϣ", "��ѡ�����", 4, "�����Ϣ", "ɾ����Ϣ", "�޸���Ϣ", "�˳���Ϣ�޸�");
}
