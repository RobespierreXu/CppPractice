#ifndef __MYSTRING_H__
#define __MYSTRING_H__

using namespace std;

#include <string.h>

class MyString
{
public:
	MyString(const char *cstr = 0);

	// 拷貝構造
	MyString(const MyString &str);

	// 拷貝賦值
	MyString &operator=(const MyString &str);

	// 析構函數
	~MyString();

	// 不去改變data，所以要加const修飾
	char *get_c_str() const { return m_data; }

private:
	char *m_data;
};

inline MyString::MyString(const char *cstr)
{
	if (cstr)
	{
		/* 分配空間並拷貝 */
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	}
	else
	{
		/* 未指定初值，創建一個字符，存放'\0' */
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline MyString::MyString(const MyString& str)
{

	/* 分配空間並拷貝 */
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
	
}

inline MyString::~MyString()
{
	delete[] m_data;
}

inline MyString &MyString::operator=(const MyString &str)
{
	if (this == &str)
	{
		return *this;
	}

	/* 刪除原有的數據 */
	delete[] m_data;
	/* 分配空間並拷貝 */
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
	return *this;
}

#endif