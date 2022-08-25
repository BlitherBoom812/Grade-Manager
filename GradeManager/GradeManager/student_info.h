#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

/*
学生信息
*/

#include "student_id.h"
#include "content_type.h"
#include "attribute_info.h"
#include <string>
#include <iostream>
#include <cassert>
#include <typeinfo>

class student_info : public attribute_info {
private:
	student_id m_id;	//学号
	string_type m_name;	//姓名
	string_type m_class_name;		//班级
	string_type m_grade_name;		//年级
	string_type m_academy_name;	//院系
	field *m_dict[5];
public:
	student_info(const student_id &id,
		const std::string &name,
		const std::string &class_name,
		const std::string &grade_name,
		const std::string &academy_name) :
		attribute_info(m_dict, 5),
		m_id(id),
		m_name(name),
		m_class_name(class_name),
		m_grade_name(grade_name),
		m_academy_name(academy_name){

		m_dict[0] = new field("学号", m_id);
		m_dict[1] = new field("姓名", m_name);
		m_dict[2] = new field("班级", m_class_name);
		m_dict[3] = new field("年级", m_grade_name);
		m_dict[4] = new field("院系", m_academy_name);
		for (int i = 0; i < 5; i++)
			if (m_dict[i] == NULL) {
				std::cout << "failed to get memory!\n";
				exit(-1);
			}
	}
	student_info(const std::string &id, 
		const std::string &name, 
		const std::string &class_name, 
		const std::string &grade_name, 
		const std::string &academy_name) : 
		attribute_info(m_dict, 5), 
		m_id(id),
		m_name(name),
		m_class_name(class_name), 
		m_grade_name(grade_name), 
		m_academy_name(academy_name) {

		m_dict[0] = new field("学号", m_id);
		m_dict[1] = new field("姓名", m_name);
		m_dict[2] = new field("班级", m_class_name);
		m_dict[3] = new field("年级", m_grade_name);
		m_dict[4] = new field("院系", m_academy_name);
		for (int i = 0; i < 5; i++)
			if (m_dict[i] == NULL) {
				std::cout << "failed to get memory!\n";
				exit(-1);
			}
	}
	student_info(const attribute_info &cp) :
		attribute_info(m_dict, 5)
	{
		_ASSERT(typeid(cp) == typeid(*this));
		const student_info &a = dynamic_cast<const student_info &>(cp);
		m_id.set_id(a.m_id);
		m_name.set_content(a.m_name);
		m_class_name.set_content(a.m_class_name);
		m_grade_name.set_content(a.m_grade_name);
		m_academy_name.set_content(a.m_academy_name);
		m_dict[0] = new field("学号", m_id);
		m_dict[1] = new field("姓名", m_name);
		m_dict[2] = new field("班级", m_class_name);
		m_dict[3] = new field("年级", m_grade_name);
		m_dict[4] = new field("院系", m_academy_name);
		for (int i = 0; i < 5; i++)
			if (m_dict[i] == NULL) {
				std::cout << "failed to get memory!\n";
				exit(-1);
			}
	}
	student_info(const student_info &cp) :
		attribute_info(m_dict, 5), 
		m_id(cp.m_id),
		m_name(cp.m_name),
		m_class_name(cp.m_class_name),
		m_grade_name(cp.m_grade_name),
		m_academy_name(cp.m_academy_name) {

		m_dict[0] = new field("学号", m_id);
		m_dict[1] = new field("姓名", m_name);
		m_dict[2] = new field("班级", m_class_name);
		m_dict[3] = new field("年级", m_grade_name);
		m_dict[4] = new field("院系", m_academy_name);
		for (int i = 0; i < 5; i++)
			if (m_dict[i] == NULL) {
				std::cout << "failed to get memory!\n";
				exit(-1);
			}
	}
	~student_info() {
		for (int i = 4; i >= 0; i--) {
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

#endif // !STUDENT_INFO_H
