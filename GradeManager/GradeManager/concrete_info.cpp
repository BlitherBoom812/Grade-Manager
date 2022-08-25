#include "student_info.h"
#include "student_id.h"
#include "content_type.h"
#include <cassert>
#include <typeinfo>
//student


const id_type &student_info::get_id() const {
	return m_id;
}
const std::string &student_info::get_name() const {
	return m_name.get_content();
}
void student_info::set_id(const id_type &new_id) {
	m_id.set_id(new_id);
}
void student_info::set_name(const std::string &new_name) {
	m_name.set_content(new_name);
}
bool student_info::operator<(const basic_info &cmp) const {
	return m_id < cmp.get_id();
}
bool student_info::operator==(const basic_info &cmp) const {
	return m_id == cmp.get_id();
}
const basic_info &student_info::operator=(const basic_info &info) {
	_ASSERT(typeid(info) == typeid(*this));
	const student_info &s = dynamic_cast<const student_info &>(info);
	for (int i = 0; i < get_key_count(); i++) {
		set_value(get_key(i), s.get_value(s.get_key(i)));
	}
	return info;
}

#include "course_info.h"
//course

const id_type &course_info::get_id() const {
	return m_id;
}
const std::string &course_info::get_name() const {
	return m_name.get_content();
}
void course_info::set_id(const id_type &new_id) {
	m_id.set_id(new_id);
}
void course_info::set_name(const std::string &new_name) {
	m_name.set_content(new_name);
}
bool course_info::operator<(const basic_info &cmp) const {
	return m_id < cmp.get_id();
}
bool course_info::operator==(const basic_info &cmp) const {
	return m_id == cmp.get_id();
}
const basic_info &course_info::operator=(const basic_info &info) {
	_ASSERT(typeid(info) == typeid(*this));
	const course_info &s = dynamic_cast<const course_info &>(info);
	for (int i = 0; i < get_key_count(); i++) {
		set_value(get_key(i), s.get_value(s.get_key(i)));
	}
	return info;
}

#include "grade_info.h"
//grade
const id_type &grade_info::get_id() const {
	return m_id;
}
const std::string &grade_info::get_name() const {
	return "";
}
void grade_info::set_id(const id_type &new_id) {
	m_id.set_id(new_id);
}
void grade_info::set_name(const std::string &new_name) {
	
}
bool grade_info::operator<(const basic_info &cmp) const {
	return m_id < cmp.get_id();
}
bool grade_info::operator==(const basic_info &cmp) const {
	return m_id == cmp.get_id();
}
const basic_info &grade_info::operator=(const basic_info &info) {
	_ASSERT(typeid(info) == typeid(*this));
	const grade_info &s = dynamic_cast<const grade_info &>(info);
	for (int i = 0; i < get_key_count(); i++) {
		set_value(get_key(i), s.get_value(s.get_key(i)));
	}
	return info;
}