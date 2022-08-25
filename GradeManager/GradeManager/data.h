#ifndef DATA_H
#define DATA_H

#include "student_info.h"
#include "course_info.h"
#include "grade_info.h"
#include <map>

typedef std::map<student_id, student_info> student_map;
typedef std::map<course_id, course_info> course_map;
typedef std::map<grade_id, grade_info> grade_map;

/*
�����࣬�洢ѧ�����γ̣��ɼ���Ϣ�ļ���
*/

class data {
private:
	student_map student_table;
	course_map course_table;
	grade_map grade_table;
public:
	data() {}
	data(const data &cp) : student_table(cp.student_table), course_table(cp.course_table), grade_table(cp.grade_table) {}
	const student_map &get_student_table() const;
	const course_map &get_course_table() const;
	const grade_map &get_grade_table() const;
	bool add(const attribute_info &info);	//����true��ʾ�ɹ�
	bool revise(const attribute_info &info);		//����true��ʾ�ɹ�;�޸�ʱ��ͨ��id�������޸ĵ���Ϣ����info�е�ֵ����ԭ����ֵ
	bool del(const id_type &id);	//����true��ʾ�ɹ�;ɾ��ѧ�����߿γ�ʱ����֮��صĳɼ�Ҳ�ᱻɾ��
	bool contains_id(const id_type &id) const;	//����true��ʾ����
	const attribute_info &get_info(const id_type &id) const;
};

#endif // !DATA_H
