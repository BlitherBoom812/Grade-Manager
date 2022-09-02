/**
 * @file info.h
 * @author BlitherBoom812
 * @brief 学生信息，课程信息，成绩信息的类定义
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INFO_H
#define INFO_H

#include <iostream>

class basic_info
{
public:
    virtual void input(std::istream &in) = 0;
    virtual void print(std::ostream &out) const = 0;
    friend std::istream &operator>>(std::istream &in, basic_info &info);
    friend std::ostream &operator<<(std::ostream &out, const basic_info &info);
};

std::istream &operator>>(std::istream &in, basic_info &info);
std::ostream &operator<<(std::ostream &out, const basic_info &info);

class student_info : virtual public basic_info
{
protected:
    std::string id;         //学号
    std::string name;       //姓名
    std::string class_name; //班级
    std::string grade;      //年级
    std::string academy;    //院系
public:
    student_info() {}
    student_info(const std::string &i, const std::string &n, const std::string &c, const std::string &g, const std::string &a) : id(i), name(n), class_name(c), grade(g), academy(a) {}
    student_info(const student_info &cp) : id(cp.id), name(cp.name), class_name(cp.class_name), grade(cp.grade), academy(cp.academy) {}
    const std::string &get_id() const;           //学号
    const std::string &get_name() const;         //姓名
    const std::string &get_class_name() const;   //班级
    const std::string &get_grade() const;        //年级
    const std::string &get_academy() const;      //院系
    void set_id(const std::string &str);         //学号
    void set_name(const std::string &str);       //姓名
    void set_class_name(const std::string &str); //班级
    void set_grade(const std::string &str);      //年级
    void set_academy(const std::string &str);    //院系
    virtual void input(std::istream &in);
    virtual void print(std::ostream &out) const;
    /**
     * @brief
     *
     * @return true 输入完成。
     * @return false 输入中止。
     */
    bool input_guide();
    bool operator==(const student_info &cmp) const;
    const student_info &operator=(const student_info &cp);
};

class course_info : virtual public basic_info
{
protected:
    std::string course_first_id;  //课程号
    std::string course_second_id; //课序号
    std::string course_name;      //课程名
    std::string course_semester;  //授课学期
    std::string course_teacher;   //任课老师
    std::string course_point;     //学分
public:
    course_info() {}
    course_info(const std::string &first_id, const std::string &second_id, const std::string &name, const std::string &semester, const std::string &teacher, const std::string &point) : course_first_id(first_id), course_second_id(second_id), course_name(name), course_semester(semester), course_teacher(teacher), course_point(point) {}
    course_info(const course_info &cp) : course_first_id(cp.course_first_id), course_second_id(cp.course_second_id), course_name(cp.course_name), course_semester(cp.course_semester), course_teacher(cp.course_teacher), course_point(cp.course_point) {}
    const std::string &get_course_first_id() const;    //课程号
    const std::string &get_course_second_id() const;   //课序号
    const std::string &get_course_name() const;        //课程名
    const std::string &get_course_semester() const;    //授课学期
    const std::string &get_course_teacher() const;     //任课老师
    const std::string &get_course_point() const;       //学分
    void set_course_first_id(const std::string &str);  //课程号
    void set_course_second_id(const std::string &str); //课序号
    void set_course_name(const std::string &str);      //课程名
    void set_course_semester(const std::string &str);  //授课学期
    void set_course_teacher(const std::string &str);   //任课老师
    void set_course_point(const std::string &str);     //学分
    virtual void input(std::istream &in);
    virtual void print(std::ostream &out) const;
    /**
     * @brief
     *
     * @return true 查询结束。
     * @return false 中止查询。
     */
    bool input_guide();
    bool operator==(const course_info &cmp) const;
    const course_info &operator=(const course_info &cp);
};

class grade_info : public student_info, public course_info
{
protected:
    std::string grade_type;  //评分制(PF制，等级制)
    std::string course_type; //课程类型（必修，限选，任选）
    std::string grade_level; //等级
    std::string grade_point; //绩点
    std::string percent;     //百分制成绩
public:
    const std::string &get_grade_type() const;    //评分制(PF制，等级制)
    const std::string &get_course_type() const;   //课程类型（必修，限选，任选）
    const std::string &get_grade_level() const;   //等级
    const std::string &get_grade_point() const;   //绩点
    const std::string &get_percent() const;       //百分制成绩
    void set_grade_type(const std::string &str);  //评分制(PF制，等级制)
    void set_course_type(const std::string &str); //课程类型（必修，限选，任选）
    void set_grade_level(const std::string &str); //等级
    void set_grade_point(const std::string &str); //绩点
    void set_percent(const std::string &str);     //百分制成绩
    grade_info() {}
    grade_info(const std::string &cid, const std::string &cname, const std::string &cclass_name, const std::string &cgrade, const std::string &cacademy,
               const std::string &ccourse_first_id, const std::string &ccourse_second_id, const std::string &ccourse_name, const std::string &cc_course_semester, const std::string &cteacher, const std::string &cpoint,
               const std::string &cgrade_type, const std::string &ccourse_type, const std::string &cgrade_level, const std::string &cgrade_point, const std::string &cpercent) : student_info(cid, cname, cclass_name, cgrade, cacademy),
                                                                                                                                                                                 course_info(ccourse_first_id, ccourse_second_id, ccourse_name, cc_course_semester, cteacher, cpoint),
                                                                                                                                                                                 grade_type(cgrade_type), course_type(ccourse_type), grade_level(cgrade_level), grade_point(cgrade_point), percent(cpercent) {}
    grade_info(const grade_info &cp) : student_info(cp),
                                       course_info(cp),
                                       grade_type(cp.grade_type), course_type(cp.course_type), grade_level(cp.grade_level), grade_point(cp.grade_point), percent(cp.percent) {}

    virtual void input(std::istream &in);
    virtual void print(std::ostream &out) const;
    bool input_guide();
    bool operator==(const grade_info &cmp) const;
    const grade_info &operator=(const grade_info &cp);
};

#endif