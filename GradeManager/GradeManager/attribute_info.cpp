#ifndef ATTRIBUTE_INFO_CPP
#define ATTRIBUTE_INFO_CPP

#include "attribute_info.h"

attribute_info::attribute_info(field *const dictionary, const int &count) : m_dictionary(dictionary), m_count(count) {

}
int attribute_info::get_key_count() const {
	return m_count;
}
const value_type &attribute_info::get_value(const std::string &key) const {
	int i;
	for (i = 0; i < m_count && m_dictionary[i].get_key() != key; i++);
	return m_dictionary[i].get_value();
}
void attribute_info::set_value(const std::string &key, const value_type &new_value) {
	int i;
	for (i = 0; i < m_count && m_dictionary[i].get_key() != key; i++);
	m_dictionary[i].set_value(new_value);
}
bool attribute_info::contains_key(const std::string &key) const {
	int i;
	for (i = 0; i < m_count && m_dictionary[i].get_key() != key; i++);
	return i < m_count;
}
#endif // !ATTRIBUTE_INFO_CPP
