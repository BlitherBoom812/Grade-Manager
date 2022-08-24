#ifndef STUDENT_ID_H
#define STUDENT_ID_H

/*
学生id信息
*/
#include "id_type.h"
#include <string>

class student_id : public id_type {
private:
	std::string id;
public:
	student_id(const std::string &id) : id(id){}
	student_id(const student_id &cp) : id(cp.id){}
	virtual bool operator==(const value_type &cmp) const;
	virtual const std::string &get_student_id() const;
	virtual void set(const value_type &new_value);
	virtual void set_id(const id_type &new_id);
	virtual void set_student_id(const student_id &new_student_id);
	virtual void set_student_id(const std::string &new_student_id);
	virtual bool operator<(const id_type &cmp) const;
	virtual const value_type &operator=(const value_type &value);
};

#endif // !STUDENT_ID_H
