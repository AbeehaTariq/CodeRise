#include<iostream>
#include"String.h"
using namespace std;
String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const char c)
{
	size = 2;
	data = new char[size];
	data[0] = c;
	data[1] = '\0';
}
String::String(const char* str)
{
	size = 50;
	data = new char[size];
	copyString(str, data);
}
String::String(const String& s)
{
	size = s.size;
	data = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		data[i] = s.data[i];
	}
	data[size] = '\0';
}

String& String:: operator =(String&& r)
{
	if (this == &r)
	{
		return*this;
	}
	else
	{
		this->~String();
		data = r.data;
		size = r.size;
		r.data = nullptr;
		r.size = 0;
	}
	return *this;
}
bool String:: operator >=(const String& s2)const
{
	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->data[i] >= s2.data[i])
		{
			return true;
		}
	}
	return false;
}
bool String:: operator <=(const String& s2)const
{

	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->data[i] <= s2.data[i])
		{
			return true;
		}
		
	}
	return false;
}
bool String:: operator !=(const String& s2)const
{

	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->data[i] != s2.data[i])
		{
			return true;
		}
	}
	return false;
}
String:: ~String()
{
	delete[]data;
	data = nullptr;
}
void String::input()
{
	cin >> this->data;
}
char& String:: operator [](const int index)
{
	if (index >= 0 || index < getLength())
	{
		return data[index];
	}
	else
	{
		data = nullptr;

	}
}
const char& String:: operator[](const int index)const
{
	if (index >= 0 || index < getLength())
	{
		return data[index];
	}
	else
	{
		data[0] = '\0';
		return data[0];
	}
}
bool String:: operator !()const
{
	if (data[0] == '\0' || data == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void String::copyString(const char* str, char* data)const
{
	for (int i = 0; i <= getLength(); i++)
	{
		data[i] = str[i];
	}
}
int String::getSize()const
{
	return size;
}
void String::display()const
{
	if (getLength() != 0)
	{
		cout << data;
	}
	else
	{
		data[0] = '\0';
		cout << data;
	}
}
int String::getLength()const
{
	if (this)
	{
		int i = 0;
		while (data[i] != '\0')
		{
			i++;
		}
		return i;
	}
	else
	{
		return -1;
	}
}
void String::remove(const int index, const int count)
{
	int p = index;
	for (int i = 0; i < getLength(); i++)
	{
		if (i != p)
		{
			 cout<< data[i];
		}
		else
		{
			for (int j = 0; j < count - 1; j++)
			{
				i++;
				p++;
			}

		}
	}
}
void String::reverse()
{

	for (int i = getLength() - 1; i >= 0; i--)
	{
		cout << data[i];
	}

}

void String::makeUpper()
{
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - 32;
		}
	}
	cout << data;

}
void String::makeLower()
{
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}
	}
	cout << data;
}
void String::trimLeft()
{
	int count = 0;
	for (int i = 0; data[i] == '\n' || data[i] == '\t' || data[i] == ' '; i++)
	{
		count++;
	}
	remove(0, count);
}
String String:: operator+(const String& s)
{
	String st;
	st.size = this->getLength() + s.getLength();
	st.data = new char[st.size + 1];
	for (int i = 0; i < this->getLength(); i++)
	{
		st.data[i] = data[i];
	}
	int k = 0;
	for (int j = this->getLength(); k < s.getLength(); j++)
	{
		st.data[j] = s.data[k];
		k++;
	}
	st.data[st.size] = '\0';
	return st;
}
int String:: operator ==(const String& s2)const
{
	if (this->size != s2.size)
	{
		return 0;
	}
	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->data[i] != s2.data[i])
		{
			return 0;
		}
	}
	return 1;
}
bool String:: operator >(const String& s2)const
{

	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->data[i] > s2.data[i])
		{
			return true;
		}
		
	}
	return false;

}
bool String:: operator <(const String& s2)const
{
	for (int i = 0; i < this->getLength(); i++)
	{
		if (this->data[i] < s2.data[i])
		{
			return true;
		}
	}
	return false;
}
