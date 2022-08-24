#ifndef COURSE_ID_H
#define COURSE_ID_H
/*
¿Î³Ìid
*/
#include "id_type.h"
#include <string>
class course_id : public id_type{
private:
	std::string course_first_id;
	int course_second_id;
public:
	course_id(const std::string &first, int second) : course_first_id(first), course_second_id(second){}
	course_id(const course_id &cp) : course_first_id(cp.course_first_id), course_second_id(cp.course_second_id){}
	virtual const std::string &get_course_first_id() const;
	virtual int get_course_second_id() const;
	virtual void set(const value_type &new_value);
	virtual void set_id(const id_type &new_id);
	virtual void set_course_id(const course_id &new_course_id);
	virtual void set_course_first_id(const std::string &new_course_first_id);
	virtual void set_course_second_id(const int &new_course_second_id);
	virtual bool operator<(const id_type &cmp) const;
	virtual bool operator==(const value_type &cmp) const;
	virtual const value_type &operator=(const value_type &value);
};

#endif