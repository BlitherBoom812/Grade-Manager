#ifndef CONTENT_TYPE_H
#define CONTENT_TYPE_H

/*
对value_type抽象类的实现
模板类，用于存放不同的类型
模板类必须在头文件内部实现
*/

#include "value_type.h"
#include "enum.h"
#include <string>
#include <cassert>
#include <typeinfo>

template <class T>
class content_type : public value_type {
private:
	T content;
public:
	content_type(const T &content);
	content_type(const content_type<T> &cp);
	const T &get_content() const;
	void set_content(const T &new_value);
	void set_content(const content_type<T> &new_value);
	virtual const value_type &get() const;
	virtual void set(const value_type &new_value);
	virtual const value_type &operator=(const value_type &value);
	virtual bool operator==(const value_type &cmp) const;
};
template <class T>
content_type<T>::content_type(const T &content) : content(content) {

}
template <class T>
content_type<T>::content_type(const content_type<T> &cp) : content(cp.content) {
}
template <class T>
const T &content_type<T>::get_content() const {
	return content;
}
template <class T>
void content_type<T>::set_content(const T &new_value) {
	content = new_value;
}
template <class T>
void content_type<T>::set_content(const content_type<T> &new_value) {
	content = new_value.content;
}
template <class T>
const value_type &content_type<T>::get() const {
	return *this;
}
template <class T>
void content_type<T>::set(const value_type &new_value) {
	_ASSERT(typeid(*this) == typeid(new_value));
	content = ((const content_type<T> &)new_value).content;
}
template <class T>
bool content_type<T>::operator==(const value_type &cmp) const{
	if (typeid(*this) != typeid(cmp)) {
		return false;
	}
	else {
		return content == ((const content_type<T>&)cmp).content;
	}
};
template <class T>
const value_type &content_type<T>::operator=(const value_type &value) {
	_ASSERT(typeid(*this) == typeid(value));
	content = ((const content_type<T>&)value).get_content();
	return value;
}


typedef content_type<std::string> string_type;
typedef content_type<CourseType> course_type;
typedef content_type<GradeType> grade_type;

#endif