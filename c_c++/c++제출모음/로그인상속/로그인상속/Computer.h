#pragma once
#include"Login.h"

class Computer :public Login
{
private:
	string m_strname;
	string m_strgr;
	string m_strcpu;
	string m_strmemo;
public:
	void COMdisplay();
	void condition();
	void function();
	Computer();
	~Computer();
};

