#ifndef ATTRIBUTE_INFO_H
#define ATTRIBUTE_INFO_H

#include "basic_info.h"
#include "field.h"

/*
������Ϣ�Ļ��࣬�����һЩ�ֶ����ڴ洢��Ϣ
*/
class attribute_info {
private:
	field *const m_dictionary;
	const int m_count;
public:
	attribute_info(field *const dictionary, const int &count);
	int get_key_count() const;
	const value_type &get_value(const std::string &key) const;
	void set_value(const std::string &key, const value_type &new_value);
	bool contains_key(const std::string &key) const;
};
#endif