#pragma once
class String
{
	char* data;
	int size;
public:
	String();
	String(const char c);
	String(const char*);
	String(const String&);
	String(String&&);
	void input();
	char& operator [](const int index);
	const char& operator[](const int index)const;
	bool operator !()const;
	int operator ==(const String& s2)const;
	bool operator >(const String& s2)const;
	bool operator <(const String& s2)const;
	bool operator >=(const String& s2)const;
	bool operator <=(const String& s2)const;
	bool operator !=(const String& s2)const;
	String operator+(const String&);
	int getLength()const;
	int getSize()const;
	void display()const;
	void remove(const int index, const int count);
	void trimLeft();
	void trim();
	void copyString(const char*, char*)const;
	void reverse();
	void makeUpper();
	void makeLower();
	void shirnk();
	String left(const int count);
	String right(const int count);
	~String();
}; 
