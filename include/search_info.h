/**
 * @file search_info.h
 * @author BlitherBoom812
 * @brief 查询功能
 * @version 0.1
 * @date 2022-09-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SEARCH_INFO_H
#define SEARCH_INFO_H

#include <string>
#include <list>
#include "../include/info.h"

extern std::list<student_info> students;
extern std::list<student_info> searched_stu;
bool search_student(std::string &str);
bool search_student_again(std::string &str);
bool search_student_exit(std::string &str);
extern std::list<course_info> courses;
extern std::list<course_info> searched_cou;
bool search_course(std::string &str);
extern std::list<grade_info> grades;
extern std::list<grade_info> searched_gra;
bool search_grade(std::string &str);
bool calculate_grade(std::string &str);
struct course_sum;  //课程信息汇总，用于calculate_course
extern std::list<course_sum> calculate_course_list;
bool calculate_course(std::string &str);
struct student_sum; //学生信息汇总，用于calculate_student
extern std::list<student_sum> calculate_student_list;
bool calculate_student(std::string &str);
bool rank_grade(std::string &str);
bool search_exit(std::string &str);
void search_info();

#endif