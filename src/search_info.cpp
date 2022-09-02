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

    std::cout << "����\\back�˳���ǰ��ѯ��" << std::endl;
    std::cout << "����\\all��ʾ������Ϣ��" << std::endl;
    std::cout << "����*��ʾ�����ô�ɸѡ������" << std::endl;

    student_info si;
    if (!si.input_guide())
    {
        return true;
    }

    std::ostringstream oss;
    int count = 0;
    oss << "�������ѧ����ϢΪ��\n"
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
    oss << "��ѯ��" << count << "�������" << std::endl;

    str = oss.str();
    // choice c[2] = {search_student_again ,search_student_exit};

    // bool flag = true;
    // while(flag) {
    //     system("cls");
    //     std::cout << str << std::endl;
    //     switch(ui::show_screen("ѧ����Ϣ��ѯ���", "��ѡ���������", 2, "��ɸѡ����м�����ѯ", "�˳�ѧ����Ϣ��ѯ")){
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
    std::cout << "����\\back�˳���ǰ��ѯ��" << std::endl;
    std::cout << "����\\all��ʾ������Ϣ��" << std::endl;
    std::cout << "����*��ʾ�����ô�ɸѡ������" << std::endl;

    course_info ci;
    if (!ci.input_guide())
    {
        return true;
    }

    std::ostringstream oss;
    int count = 0;
    oss << "������Ŀγ���ϢΪ��\n"
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

    oss << "��ѯ��" << count << "�������" << std::endl;

    str = oss.str();

    // bool flag = true;
    // while(flag) {
    //     system("cls");
    //     std::cout << str << std::endl;
    //     switch(ui::show_screen("�γ���Ϣ��ѯ���", "��ѡ���������", 2, "��ɸѡ����м�����ѯ", "�˳��γ���Ϣ��ѯ")){
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
    std::cout << "����\\back�˳���ǰ��ѯ��" << std::endl;
    std::cout << "����\\all��ʾ������Ϣ��" << std::endl;
    std::cout << "����*��ʾ�����ô�ɸѡ������" << std::endl;

    grade_info gi;
    if (!gi.input_guide())
    {
        return true;
    }

    std::ostringstream oss;
    int count = 0;
    oss << "������ĳɼ���ϢΪ��\n"
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
    oss << "��ѯ��" << count << "�������" << std::endl;

    str = oss.str();

    std::string info;
    bool flag = true;
    while (flag)
    {
        system("cls");
        std::cout << str << std::endl
                  << info << std::endl;
        switch (ui::show_screen("�ɼ���Ϣ��ѯ���", "��ѡ���������", 3, "ͳ�ƿγ̳ɼ�", "ͳ��ѧ���ɼ�", "�˳��ɼ���Ϣ��ѯ"))
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
        switch (ui::show_screen("�ɼ�ͳ��", "��ѡ��ͳ��ѡ��: ", 3, "�γ�ͳ��", "ѧ��ͳ��", "�˳�"))
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
    int count;  //�γ�������
    int percent_count;   //�ٷ��Ƴɼ�����
    double percent;
    int point_count;    //����ɼ�����
    double point;
};
std::list<course_sum> calculate_course_list;
//����ٷ���ƽ���ɼ���ƽ�����㣬�γ�����
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
    oss << std::setw(width_course_first_id) << "�γ̺�" << std::setw(widtch_course_second_id) << "�����" << std::setw(width_course_name) << "�γ���" << std::setw(10) << "�γ�����" << std::setw(10) << "ƽ������" << std::setw(16) << "�ٷ���ƽ����" << std::endl;
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
    int count;       //�γ���
    int total_point; //��ѧ��
    int count_point; //����gpa��ѧ��
    double point1;   // gpa
};
std::list<student_sum> calculate_student_list;
//�γ�������ѧ�֣�GPA
bool calculate_student(std::string &str)
{
    std::ostringstream oss;
    for (std::list<grade_info>::iterator i = searched_gra.begin(); i != searched_gra.end(); i++)
    {
        int total_point = 0; //��ѧ��
        int count_point = 0; //����ѧ��
        double point1 = 0;   //����
        //��õ�ǰ�γ�ѧ��
        std::istringstream iss_point(i->get_course_point());
        iss_point >> total_point;

        if (i->get_grade_point() == "-")
        { //������gpa
            count_point = 0;
            point1 = 0;
        }
        else
        { //����gpa
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
    oss << std::setw(width_id) << "ѧ��" << std::setw(width_name) << "����" << std::setw(10) << "ѡ����Ŀ" << std::setw(8) << "��ѧ��" << std::setw(10) << "����" << std::endl;
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
    ui::choose(f, "��ѯ��Ϣ", "��ѡ����Ҫ��ѯ����Ϣ����", 4, "ѧ����Ϣ", "�γ���Ϣ", "�ɼ���Ϣ", "�˳���ѯ");
}