#include "utility.h"
#include "const.h"

student_info utility::search_student(const std::string &id, const std::list<student_info> &li)
{
    for (std::list<student_info>::const_iterator i = li.begin(); i != li.end(); i++)
    {
        if (i->get_id() == id)
        {
            return *i;
        }
    }
    return student_info();
}
course_info utility::search_course(const std::string &course_first_id, const std::string &course_second_id, const std::list<course_info> &list)
{
    for (std::list<course_info>::const_iterator i = list.begin(); i != list.end(); i++)
    {
        if (i->get_course_first_id() == course_first_id && i->get_course_second_id() == course_second_id)
        {
            return *i;
        }
    }
    return course_info();
}
grade_info utility::search_grade(const std::string &id, const std::string &course_first_id, const std::string &course_second_id, const std::list<grade_info> &list)
{
    for (std::list<grade_info>::const_iterator i = list.begin(); i != list.end(); i++)
    {
        if (i->get_id() == id && i->get_course_first_id() == course_first_id && i->get_course_second_id() == course_second_id)
        {
            return *i;
        }
    }
    return grade_info();
}

namespace utility
{
    bool contains_student(const std::string &id, const std::list<student_info> &list)
    {
        return !(search_student(id, list) == null_student);
    }
    bool contains_course(const std::string &course_first_id, const std::string &course_second_id, const std::list<course_info> &list)
    {
        return !(search_course(course_first_id, course_second_id, list) == null_course);
    }
    bool contains_grade(const std::string &id, const std::string &course_first_id, const std::string &course_second_id, const std::list<grade_info> &list)
    {
        return !(search_grade(id, course_first_id, course_second_id, list) == null_grade);
    }
    bool erase_student(const std::string &id, std::list<student_info> &list, std::list<grade_info> &grades)
    {
        for (std::list<grade_info>::iterator i = grades.begin(); i != grades.end();)
        {
            if (i->get_id() == id)
            {
                grades.erase(i++);
            }
            else
            {
                i++;
            }
        }
        for (std::list<student_info>::iterator i = list.begin(); i != list.end();)
        {
            if (i->get_id() == id)
            {
                list.erase(i++);
                return true;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
    bool erase_course(const std::string &course_first_id, const std::string &course_second_id, std::list<course_info> &list, std::list<grade_info> &grades)
    {
        for (std::list<grade_info>::iterator i = grades.begin(); i != grades.end();)
        {
            if (i->get_course_first_id() == course_first_id && i->get_course_second_id() == course_second_id)
            {
                grades.erase(i++);
            }
            else
            {
                i++;
            }
        }
        for (std::list<course_info>::iterator i = list.begin(); i != list.end(); i++)
        {
            if (i->get_course_first_id() == course_first_id && i->get_course_second_id() == course_second_id)
            {
                list.erase(i++);
                return true;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
    bool erase_grade(const std::string &id, const std::string &course_first_id, const std::string &course_second_id, std::list<grade_info> &list)
    {
        for (std::list<grade_info>::iterator i = list.begin(); i != list.end(); i++)
        {
            if (i->get_id() == id && i->get_course_first_id() == course_first_id && i->get_course_second_id() == course_second_id)
            {
                list.erase(i++);
                return true;
            }
        }
        return true;
    }
} // namespace utility
