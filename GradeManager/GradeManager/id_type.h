#ifndef ID_TYPE_H
#define ID_TYPE_H

/*
抽象类，id类型
所有id的基类
*/

#include "value_type.h"

class id_type : public value_type{
public:
	virtual void set(const value_type &new_value) = 0;
	virtual const value_type &operator=(const value_type &value) = 0;
	virtual bool operator==(const value_type &cmp) const = 0;
	virtual void set_id(const id_type &new_id) = 0;
	virtual bool operator<(const id_type &cmp) const = 0;
};

#endif // !ID_TYPE_H
