#ifndef UTILITY_H
#define UTILITY_H

#include "info.h"
#include <string>
#include <list>
namespace utility
{

    student_info search_student(const std::string &id, const std::list<student_info> &list);
    course_info search_course(const std::string &course_first_id, const std::string &course_second_id, const std::list<course_info> &list);
    grade_info search_grade(const std::string &id, const std::string &course_first_id, const std::string &course_second_id, const std::list<grade_info> &list);
    bool contains_student(const std::string &id, const std::list<student_info> &list);
    bool contains_course(const std::string &course_first_id, const std::string &course_second_id, const std::list<course_info> &list);
    bool contains_grade(const std::string &id, const std::string &course_first_id, const std::string &course_second_id, const std::list<grade_info> &list);
    /**
     * @brief
     *
     * @param id
     * @param list
     * @return true É¾³ı³É¹¦¡£
     * @return false É¾³ıÊ§°Ü¡£
     */
    bool erase_student(const std::string &id, std::list<student_info> &list, std::list<grade_info> &grades);
    bool erase_course(const std::string &course_first_id, const std::string &course_second_id, std::list<course_info> &list, std::list<grade_info> &grades);
    bool erase_grade(const std::string &id, const std::string &course_first_id, const std::string &course_second_id, std::list<grade_info> &list);
}

#endif