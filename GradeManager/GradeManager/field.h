#ifndef FIELD_H
#define FIELD_H

/*
字段
由键和值构成
*/

#include <string>
#include <cassert>
#include "value_type.h"

class field {
private:
	const std::string key;
	value_type &value;
public:
	field(const char* key, value_type &value) : key(key), value(value) {

	}
	field(const std::string &key, value_type &value) : key(key), value(value) {

	}
	virtual const std::string &get_key() const {
		return key;
	};
	virtual const value_type &get_value() const {
		return value;
	};
	virtual const void set_value(const value_type &new_value) {
		value.set(new_value);
	};
};


#endif
