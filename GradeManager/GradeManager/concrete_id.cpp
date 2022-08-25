#include "course_id.h"
#include "student_id.h"
#include "grade_id.h"
#include "value_type.h"
#include "content_type.h"
#include <cassert>
#include <typeinfo>

// student
const std::string &student_id::get_student_id() const {
	return id;
}
void student_id::set(const value_type &new_value) {
	_ASSERT(typeid(new_value) == typeid(*this));
	set_student_id(dynamic_cast<const student_id&>(new_value).id);
}
void student_id::set_id(const id_type &new_id) {
	_ASSERT(typeid(new_id) == typeid(*this));
	set_student_id((dynamic_cast<const student_id &>(new_id)).id);
}
void student_id::set_student_id(const student_id &new_student_id) {
	set_student_id(new_student_id.id);
}
void student_id::set_student_id(const std::string &new_student_id) {
	id = new_student_id;
}
bool student_id::operator==(const value_type &cmp) const{
	if (typeid(cmp) != typeid(*this)) {
		return false;
	}
	else {
		const student_id &s = dynamic_cast<const student_id &>(cmp);
		return s.id == "*" || id == s.id;
	}
}
bool student_id::operator<(const id_type &cmp) const {
	_ASSERT(typeid(cmp) == typeid(*this));
	return id < (dynamic_cast<const student_id &>(cmp)).id;
}
const value_type &student_id::operator=(const value_type &value) {
	_ASSERT(typeid(value) == typeid(*this));
	set(value);
	return value;
}

// course
const std::string &course_id::get_course_first_id() const {
	return course_first_id;
}
int course_id::get_course_second_id() const {
	return course_second_id;
}
void course_id::set(const value_type &new_value) {
	_ASSERT(typeid(new_value) == typeid(*this));
	const course_id &c = dynamic_cast<const course_id &>(new_value);
	set_course_first_id(c.course_first_id);
	set_course_second_id(c.course_second_id);
}
void course_id::set_id(const id_type &new_id) {
	_ASSERT(typeid(new_id) == typeid(*this));
	const course_id &c = dynamic_cast<const course_id &>(new_id);
	set_course_first_id(c.course_first_id);
	set_course_second_id(c.course_second_id);
}
void course_id::set_course_id(const course_id &new_course_id) {
	set_course_first_id(new_course_id.course_first_id);
	set_course_second_id(new_course_id.course_second_id);
}
void course_id::set_course_first_id(const std::string &new_course_first_id) {
	course_first_id = new_course_first_id;
}
void course_id::set_course_second_id(const int &new_course_second_id) {
	course_second_id = new_course_second_id;
}
bool course_id::operator<(const id_type &cmp) const {
	_ASSERT(typeid(cmp) == typeid(*this));
	const course_id &c = dynamic_cast<const course_id &>(cmp);
	if (course_first_id == c.course_first_id) {
		return course_second_id < c.course_second_id;
	}
	else {
		return course_first_id < c.course_first_id;
	}
}
bool course_id::operator==(const value_type &cmp) const {
	if (typeid(cmp) != typeid(*this)) {
		return false;
	}
	const course_id &c = dynamic_cast<const course_id &>(cmp);
	return (c.course_first_id == "*" || course_first_id == c.course_first_id) && (c.course_second_id == -1 || course_second_id == c.course_second_id);
}
const value_type &course_id::operator=(const value_type &value) {
	set(value);
	return value;
}

//grade
const student_id grade_id::get_student_id_type() const {
	return *this;
}
const course_id grade_id::get_course_id_type() const {
	return *this;
}
void grade_id::set(const value_type &new_value) {
	_ASSERT(typeid(new_value) == typeid(*this));
	const student_id &g1 = dynamic_cast<const student_id &>(new_value);
	const course_id &g2 = dynamic_cast<const course_id &>(new_value);
	set_student_id(g1.get_student_id());
	set_course_id(g2);
}
void grade_id::set_id(const id_type &new_id) {
	_ASSERT(typeid(new_id) == typeid(*this));
	set_student_id(dynamic_cast<const student_id &>(new_id));
	set_course_id(dynamic_cast<const course_id &>(new_id));
}
void grade_id::set_grade_id(const grade_id &new_grade_id) {
	set_student_id(new_grade_id);
	set_course_id(new_grade_id);
}
bool grade_id::operator==(const value_type &cmp) const {
	if (typeid(cmp) != typeid(*this)) {
		return false;
	}
	const student_id &g1 = dynamic_cast<const student_id &>(cmp);
	const course_id &g2 = dynamic_cast<const course_id &>(cmp);
	return g1 == *this && g2 == *this;
}
bool grade_id::operator<(const id_type &cmp) const {
	_ASSERT(typeid(cmp) == typeid(*this));

	if (get_student_id() == dynamic_cast<const student_id &>(cmp).get_student_id()) {
		return  this->course_id::operator<(cmp);
	}
	else {
		return get_student_id() < dynamic_cast<const student_id &>(cmp).get_student_id();
	}
}
const value_type &grade_id::operator=(const value_type &value) {
	_ASSERT(typeid(value) == typeid(*this));
	const student_id &g1 = dynamic_cast<const student_id &>(value);
	const course_id &g2 = dynamic_cast<const course_id &>(value);
	return value;
}