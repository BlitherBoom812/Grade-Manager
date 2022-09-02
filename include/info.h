/**
 * @file info.h
 * @author BlitherBoom812
 * @brief ѧ����Ϣ���γ���Ϣ���ɼ���Ϣ���ඨ��
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
    std::string id;         //ѧ��
    std::string name;       //����
    std::string class_name; //�༶
    std::string grade;      //�꼶
    std::string academy;    //Ժϵ
public:
    student_info() {}
    student_info(const std::string &i, const std::string &n, const std::string &c, const std::string &g, const std::string &a) : id(i), name(n), class_name(c), grade(g), academy(a) {}
    student_info(const student_info &cp) : id(cp.id), name(cp.name), class_name(cp.class_name), grade(cp.grade), academy(cp.academy) {}
    const std::string &get_id() const;           //ѧ��
    const std::string &get_name() const;         //����
    const std::string &get_class_name() const;   //�༶
    const std::string &get_grade() const;        //�꼶
    const std::string &get_academy() const;      //Ժϵ
    void set_id(const std::string &str);         //ѧ��
    void set_name(const std::string &str);       //����
    void set_class_name(const std::string &str); //�༶
    void set_grade(const std::string &str);      //�꼶
    void set_academy(const std::string &str);    //Ժϵ
    virtual void input(std::istream &in);
    virtual void print(std::ostream &out) const;
    /**
     * @brief
     *
     * @return true ������ɡ�
     * @return false ������ֹ��
     */
    bool input_guide();
    bool operator==(const student_info &cmp) const;
    const student_info &operator=(const student_info &cp);
};

class course_info : virtual public basic_info
{
protected:
    std::string course_first_id;  //�γ̺�
    std::string course_second_id; //�����
    std::string course_name;      //�γ���
    std::string course_semester;  //�ڿ�ѧ��
    std::string course_teacher;   //�ο���ʦ
    std::string course_point;     //ѧ��
public:
    course_info() {}
    course_info(const std::string &first_id, const std::string &second_id, const std::string &name, const std::string &semester, const std::string &teacher, const std::string &point) : course_first_id(first_id), course_second_id(second_id), course_name(name), course_semester(semester), course_teacher(teacher), course_point(point) {}
    course_info(const course_info &cp) : course_first_id(cp.course_first_id), course_second_id(cp.course_second_id), course_name(cp.course_name), course_semester(cp.course_semester), course_teacher(cp.course_teacher), course_point(cp.course_point) {}
    const std::string &get_course_first_id() const;    //�γ̺�
    const std::string &get_course_second_id() const;   //�����
    const std::string &get_course_name() const;        //�γ���
    const std::string &get_course_semester() const;    //�ڿ�ѧ��
    const std::string &get_course_teacher() const;     //�ο���ʦ
    const std::string &get_course_point() const;       //ѧ��
    void set_course_first_id(const std::string &str);  //�γ̺�
    void set_course_second_id(const std::string &str); //�����
    void set_course_name(const std::string &str);      //�γ���
    void set_course_semester(const std::string &str);  //�ڿ�ѧ��
    void set_course_teacher(const std::string &str);   //�ο���ʦ
    void set_course_point(const std::string &str);     //ѧ��
    virtual void input(std::istream &in);
    virtual void print(std::ostream &out) const;
    /**
     * @brief
     *
     * @return true ��ѯ������
     * @return false ��ֹ��ѯ��
     */
    bool input_guide();
    bool operator==(const course_info &cmp) const;
    const course_info &operator=(const course_info &cp);
};

class grade_info : public student_info, public course_info
{
protected:
    std::string grade_type;  //������(PF�ƣ��ȼ���)
    std::string course_type; //�γ����ͣ����ޣ���ѡ����ѡ��
    std::string grade_level; //�ȼ�
    std::string grade_point; //����
    std::string percent;     //�ٷ��Ƴɼ�
public:
    const std::string &get_grade_type() const;    //������(PF�ƣ��ȼ���)
    const std::string &get_course_type() const;   //�γ����ͣ����ޣ���ѡ����ѡ��
    const std::string &get_grade_level() const;   //�ȼ�
    const std::string &get_grade_point() const;   //����
    const std::string &get_percent() const;       //�ٷ��Ƴɼ�
    void set_grade_type(const std::string &str);  //������(PF�ƣ��ȼ���)
    void set_course_type(const std::string &str); //�γ����ͣ����ޣ���ѡ����ѡ��
    void set_grade_level(const std::string &str); //�ȼ�
    void set_grade_point(const std::string &str); //����
    void set_percent(const std::string &str);     //�ٷ��Ƴɼ�
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