#ifndef BASIC_INFO_H
#define BASIC_INFO_H

/*
抽象类
基本信息，所有信息的基类
*/

#include "id_type.h"
#include <string>

class basic_info {
public:
	virtual const id_type &get_id() const = 0;
	virtual const std::string &get_name() const = 0;
	virtual void set_id(const id_type &new_id) = 0;
	virtual void set_name(const std::string &new_name) = 0;
	virtual bool operator<(const basic_info &cmp) const = 0;
	virtual bool operator==(const basic_info &cmp) const = 0;
	virtual const basic_info &operator=(const basic_info &info) = 0;
	
};

#endif // !BASIC_INFO_H
