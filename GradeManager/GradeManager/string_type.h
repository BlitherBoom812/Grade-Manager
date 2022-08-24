#ifndef STRING_TYPE_H
#define STRING_TYPE_H

#include "value_type.h"
#include <string>
class string_type : public value_type{
private:
	std::string content;
public:
	string_type(const std::string &s);
	string_type(const char *cs);
	const std::string &get();
	void set(const std::string &value);
	virtual bool operator==(const value_type &cmp);
};

#endif // !STRING_TYPE_H
