#ifndef COURSE_INFO_H
#define COURSE_INFO_H
#pragma warning(disable:26812)	//����enumδ�趨��Χ����
#include "attribute_info.h"
#include "course_id.h"
#include "content_type.h"
#include "enum.h"
#include <iostream>
#include <cassert>
#include <typeinfo>

class course_info : public attribute_info{
private:
	course_id m_id;	//�γ�id,�����γ̺źͿ����
	string_type m_name;	//�γ���
	string_type m_semester;		//�ڿ�ѧ��
	string_type m_teacher;		//�ο���ʦ
	int_type m_point;		//ѧ��
	course_type m_course_type;	//�γ�����

	field *m_dict[6];
public:
	course_info(const course_id &id,
		const std::string &name,
		const std::string &semester,
		const std::string &teacher,
		const int &point,
		const CourseType &course_type) :
		attribute_info(m_dict, 6),
		m_id(id),
		m_name(name),
		m_semester(semester),
		m_teacher(teacher),
		m_point(point),
		m_course_type(course_type) {

		m_dict[0] = new field("�γ�id", m_id);
		m_dict[1] = new field("�γ���", m_name);
		m_dict[2] = new field("�ڿ�ѧ��", m_semester);
		m_dict[3] = new field("�ο���ʦ", m_teacher);
		m_dict[4] = new field("ѧ��", m_point);
		m_dict[5] = new field("�γ�����", m_course_type);
		for (int i = 0; i < 6; i++)
			if (m_dict[i] == NULL) {
				std::cout << "failed to get memory!\n";
				exit(-1);
			}
	}
	course_info(const std::string &course_first_id,
		int course_second_id,
		const std::string &name,
		const std::string &semester,
		const std::string &teacher,
		const int &point,
		const CourseType &course_type) :
		attribute_info(m_dict, 6),
		m_id(course_first_id, course_second_id),
		m_name(name),
		m_semester(semester),
		m_teacher(teacher),
		m_point(point),
		m_course_type(course_type) {

		m_dict[0] = new field("�γ�id", m_id);
		m_dict[1] = new field("�γ���", m_name);
		m_dict[2] = new field("�ڿ�ѧ��", m_semester);
		m_dict[3] = new field("�ο���ʦ", m_teacher);
		m_dict[4] = new field("ѧ��", m_point);
		m_dict[5] = new field("�γ�����", m_course_type);
		for (int i = 0; i < 6; i++)
			if (m_dict[i] == NULL) {
				std::cout << "failed to get memory!\n";
				exit(-1);
			}
	}
	course_info(const attribute_info &cp) : attribute_info(m_dict, 6) {
		_ASSERT(typeid(cp) == typeid(course_info));
		const course_info &c = dynamic_cast<const course_info &>(cp);
		m_id.set_id(c.m_id);
		m_name.set_content(c.m_name);
		m_semester.set_content(c.m_semester);
		m_teacher.set_content(c.m_teacher);
		m_point.set_content(c.m_point);
		m_course_type.set_content(c.m_course_type);
		m_dict[0] = new field("�γ�id", m_id);
		m_dict[1] = new field("�γ���", m_name);
		m_dict[2] = new field("�ڿ�ѧ��", m_semester);
		m_dict[3] = new field("�ο���ʦ", m_teacher);
		m_dict[4] = new field("ѧ��", m_point);
		m_dict[5] = new field("�γ�����", m_course_type);
		for (int i = 0; i < 6; i++)
			if (m_dict[i] == NULL) {
				std::cout << "failed to get memory!\n";
				exit(-1);
			}
	}
	course_info(const course_info &cp) :
		attribute_info(m_dict, 6),
		m_id(cp.m_id),
		m_name(cp.m_name),
		m_semester(cp.m_semester),
		m_teacher(cp.m_teacher),
		m_point(cp.m_point),
		m_course_type(cp.m_course_type) {

		m_dict[0] = new field("�γ�id", m_id);
		m_dict[1] = new field("�γ���", m_name);
		m_dict[2] = new field("�ڿ�ѧ��", m_semester);
		m_dict[3] = new field("�ο���ʦ", m_teacher);
		m_dict[4] = new field("ѧ��", m_point);
		m_dict[5] = new field("�γ�����", m_course_type);
		for (int i = 0; i < 6; i++)
			if (m_dict[i] == NULL) {
				std::cout << "failed to get memory!\n";
				exit(-1);
			}
	}
	~course_info() {
		for (int i = 5; i >= 0; i--) {
			delete m_dict[i];
		}
	}
	virtual const id_type &get_id() const;
	virtual const std::string &get_name() const;
	virtual void set_id(const id_type &new_id);
	virtual void set_name(const std::string &new_name);
	virtual bool operator<(const basic_info &cmp) const;
	virtual bool operator==(const basic_info &cmp) const;
	virtual const basic_info &operator=(const basic_info &info);

};

#endif // !COURSE_INFO_H
