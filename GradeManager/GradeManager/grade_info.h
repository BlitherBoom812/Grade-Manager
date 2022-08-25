#ifndef GRADE_INFO_H
#define GRADE_INFO_H
#pragma warning(disable:26812)	//忽略enum未设定范围警告
#include "attribute_info.h"
#include "grade_id.h"
#include "content_type.h"
#include "enum.h"
#include <iostream>
#include <cassert>
#include <typeinfo>
class grade_info : public attribute_info{
private:
	grade_id m_id;	//成绩主键(id)，包括学号，课程号，课序号
	grade_type m_grade_type;	//评分制
	string_type m_grade;		//等级
	double_type m_grade_point;		//绩点
	int_type m_percent;	//百分制成绩
	field *m_dict[5];
public:
	grade_info(const grade_id &id,
		const GradeType &grade_type,
		const std::string &grade,
		double grade_point,
		int percent) :
		attribute_info(m_dict, 5),
		m_id(id),
		m_grade_type(grade_type),
		m_grade(grade),
		m_grade_point(grade_point),
		m_percent(percent) {
		m_dict[0] = new field("grade_id", m_id);
		m_dict[1] = new field("评分制", m_grade_type);
		m_dict[2] = new field("等级", m_grade);
		m_dict[3] = new field("绩点", m_grade_point);
		m_dict[4] = new field("百分制成绩", m_percent);
		for(int i = 0; i < 5; i++)
			if (m_dict[i] == NULL) {
			std::cout << "failed to get memory!\n";
			exit(-1);
		}
	}
	grade_info(const attribute_info &cp) : attribute_info(m_dict, 5) {
		_ASSERT(typeid(cp) == typeid(grade_info));
		const grade_info &g = dynamic_cast<const grade_info &>(cp);
		m_id.set_id(g.m_id);
		m_grade_type.set_content(g.m_grade_type);
		m_grade.set_content(g.m_grade);
		m_grade_point.set_content(g.m_grade_point);
		m_percent.set_content(g.m_percent);
		m_dict[0] = new field("grade_id", m_id);
		m_dict[1] = new field("评分制", m_grade_type);
		m_dict[2] = new field("等级", m_grade);
		m_dict[3] = new field("绩点", m_grade_point);
		m_dict[4] = new field("百分制成绩", m_percent);
		for (int i = 0; i < 5; i++)
			if (m_dict[i] == NULL) {
				std::cout << "failed to get memory!\n";
				exit(-1);
			}
	}
	grade_info(const grade_info &cp) :
		attribute_info(m_dict, 5),
		m_id(cp.m_id),
		m_grade_type(cp.m_grade_type),
		m_grade(cp.m_grade),
		m_grade_point(cp.m_grade_point),
		m_percent(cp.m_percent) {
		m_dict[0] = new field("grade_id", m_id);
		m_dict[1] = new field("评分制", m_grade_type);
		m_dict[2] = new field("等级", m_grade);
		m_dict[3] = new field("绩点", m_grade_point);
		m_dict[4] = new field("百分制成绩", m_percent);
		for (int i = 0; i < 5; i++)
			if (m_dict[i] == NULL) {
				std::cout << "failed to get memory!\n";
				exit(-1);
			}
	}
	~grade_info() {
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

#endif // !GRADE_INFO_H

