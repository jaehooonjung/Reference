#pragma once
#include"Mecro.h"
#define IDLEN 3
#define PASSWORDLEN 8
#define IDMAX 10

struct ID
{
	string m_strId;
	string m_strPassword;
	string m_strName;
	int m_iAge;
	string m_strPhonNumber;
	int m_iMileage;
};

class Login
{
private:
protected:
	int m_iId_Count;
	ID m_Id_List[IDMAX];
	bool m_bLoginFlag;
public:
	int LoginMain();
	void Menu(int Num);
	void Join(ID* P1, int Id_Count, ID Id_List[]);
	bool StringCheck(char Start, char End, char Check);
	void Display(ID* id);
	void ShowID(ID id);
	void SimpleShowID(ID id);
	void SetID(ID* id);
	void Setstring(string* str, string tmp);
	void Setint(int* num, string tmp);
	Login();
	~Login();
};

