#ifndef GRADE_INFO_H
#define GRADE_INFO_H
#pragma warning(disable:26812)	//����enumδ�趨��Χ����
#include "attribute_info.h"
#include "grade_id.h"
#include "content_type.h"
#include "enum.h"
#include <iostream>
#include <cassert>
#include <typeinfo>
class grade_info : public attribute_info{
private:
	grade_id m_id;	//�ɼ�����(id)������ѧ�ţ��γ̺ţ������
	grade_type m_grade_type;	//������
	string_type m_grade;		//�ȼ�
	double_type m_grade_point;		//����
	int_type m_percent;	//�ٷ��Ƴɼ�
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
		m_dict[1] = new field("������", m_grade_type);
		m_dict[2] = new field("�ȼ�", m_grade);
		m_dict[3] = new field("����", m_grade_point);
		m_dict[4] = new field("�ٷ��Ƴɼ�", m_percent);
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
		m_dict[1] = new field("������", m_grade_type);
		m_dict[2] = new field("�ȼ�", m_grade);
		m_dict[3] = new field("����", m_grade_point);
		m_dict[4] = new field("�ٷ��Ƴɼ�", m_percent);
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
		m_dict[1] = new field("������", m_grade_type);
		m_dict[2] = new field("�ȼ�", m_grade);
		m_dict[3] = new field("����", m_grade_point);
		m_dict[4] = new field("�ٷ��Ƴɼ�", m_percent);
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

