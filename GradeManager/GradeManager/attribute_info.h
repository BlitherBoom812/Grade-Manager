#ifndef ATTRIBUTE_INFO_H
#define ATTRIBUTE_INFO_H

#include "basic_info.h"
#include "field.h"

/*
所有信息的基类，添加了一些字段用于存储信息
*/
class attribute_info : public basic_info{
private:
	field **const m_dictionary;
	const int m_count;
public:
	attribute_info(field **const dictionary, const int &count);
	int get_key_count() const;
	const std::string &get_key(int i) const;
	const value_type &get_value(const std::string &key) const;
	void set_value(const std::string &key, const value_type &new_value);
	bool contains_key(const std::string &key) const;
	virtual const id_type &get_id() const = 0;
	virtual const std::string &get_name() const = 0;
	virtual void set_id(const id_type &new_id) = 0;
	virtual void set_name(const std::string &new_name) = 0;
	virtual bool operator<(const basic_info &cmp) const = 0;
	virtual bool operator==(const basic_info &cmp) const = 0;
	virtual const basic_info &operator=(const basic_info &info) = 0;
};
#endif