#ifndef VALUE_TYPE_H
#define VALUE_TYPE_H

/*
������
һ��ֵ���͵Ļ���
*/

class value_type {
public:
	virtual void set(const value_type &new_value) = 0;
	virtual const value_type &operator=(const value_type &value) = 0;
	virtual bool operator==(const value_type &cmp)  const = 0;
};
#endif // !VALUE_TYPE_H