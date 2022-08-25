#include "data.h"
#include <cassert>
#include <typeinfo>
#include <utility>
#include <iterator>

const student_map &data::get_student_table() const {
	return student_table;
}
const course_map &data::get_course_table() const {
	return course_table;
}
const grade_map &data::get_grade_table() const {
	return grade_table;
}
bool data::add(const attribute_info &info) {
	if (contains_id(info.get_id())) {
		return false;
	}
	else {
		if (typeid(info) == typeid(student_info)) {
			std::make_pair<std::string, std::string>("ing", "ads");
			student_table.insert(std::make_pair(dynamic_cast<const student_id &>(info.get_id()), dynamic_cast<const student_info &>(info)));
			return true;
		}
		else if (typeid(info) == typeid(course_info)) {
			course_table.insert(std::make_pair(dynamic_cast<const course_id &>(info.get_id()), dynamic_cast<const course_info &>(info)));
			return true;
		}
		else if (typeid(info) == typeid(grade_info)) {
			grade_table.insert(std::make_pair(dynamic_cast<const grade_id &>(info.get_id()), dynamic_cast<const grade_info &>(info)));
			return true;
		}
		return false;
	}
}
bool data::revise(const attribute_info &info) {
	if (typeid(info) == typeid(student_info)) {
		student_table.find(dynamic_cast<const student_id &>(info.get_id()))->second = info;
		return true;
	}
	else if (typeid(info) == typeid(course_info)) {
		course_table.find(dynamic_cast<const course_id &>(info.get_id()))->second = info;
		return true;
	}
	else if (typeid(info) == typeid(grade_info)) {
		grade_table.find(dynamic_cast<const grade_id &>(info.get_id()))->second = info;
		return true;
	}
	else {
		return false;
	}
}		//返回true表示成功 {}修改时，通过id查找需修改的信息，用info中的值覆盖原来的值
bool data::del(const id_type &id) {
	if (typeid(id) == typeid(student_id)) {
		const student_id &s = dynamic_cast<const student_id &>(id);
		student_table.erase(s);
		grade_map::iterator i = grade_table.begin();
		while (i != grade_table.end()) {
			if (s == i->first.get_student_id_type()) {
				grade_table.erase(i++);
			}
			else {
				i++;
			}
		}
		return true;
	}
	else if (typeid(id) == typeid(course_id)) {
		const course_id &c = dynamic_cast<const course_id &>(id);
		course_table.erase(c);
		for (grade_map::iterator i = grade_table.begin(); i != grade_table.end(); i++) {
			if (c == i->first.get_course_id_type()) {
				grade_table.erase(i);
			}
		}
		return true;
	}
	else if (typeid(id) == typeid(grade_id)) {
		grade_table.erase(dynamic_cast<const grade_id &>(id));
		return true;
	}
	else {
		return false;
	}
}	//返回true表示成功 {}删除学生或者课程时，与之相关的成绩也会被删除
bool data::contains_id(const id_type &id) const {
	if (typeid(id) == typeid(student_id)) {
		
		return student_table.count(dynamic_cast<const student_id &>(id)) == 1;
	}
	else if (typeid(id) == typeid(course_id)) {
		return course_table.count(dynamic_cast<const course_id &>(id)) == 1;
	}
	else if (typeid(id) == typeid(grade_id)) {
		return grade_table.count(dynamic_cast<const grade_id &>(id)) == 1;
	}
	else {
		return false;
	}
}	//返回true表示存在
const attribute_info &data::get_info(const id_type &id) const {
	_ASSERT(contains_id(id));
	if (typeid(id) == typeid(student_id)) {
		return student_table.find(dynamic_cast<const student_id &>(id))->second;
	}
	else if (typeid(id) == typeid(course_id)) {
		return course_table.find(dynamic_cast<const course_id &>(id))->second;
	}
	else if (typeid(id) == typeid(grade_id)) {
		return grade_table.find(dynamic_cast<const grade_id &>(id))->second;
	}
}