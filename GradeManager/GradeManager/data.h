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
数据类，存储学生，课程，成绩信息的集合
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
	bool add(const attribute_info &info);	//返回true表示成功
	bool revise(const attribute_info &info);		//返回true表示成功;修改时，通过id查找需修改的信息，用info中的值覆盖原来的值
	bool del(const id_type &id);	//返回true表示成功;删除学生或者课程时，与之相关的成绩也会被删除
	bool contains_id(const id_type &id) const;	//返回true表示存在
	const attribute_info &get_info(const id_type &id) const;
};

#endif // !DATA_H
