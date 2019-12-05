#include "Login.h"

Login::Login()
{
	m_iId_Count = 0;
}

int Login::LoginMain()
{
	string TmpId, TmpPassword;
	int Select;
	bool Id_Flag, PasswordFlag;
	while (1)
	{
		m_bLoginFlag = false;
		Menu(m_iId_Count);
		cin >> Select;
		switch (Select)
		{
		case 1:
			if (m_iId_Count >= IDMAX)
			{
				cout << "더이상 회원을 등록할 수 없습니다." << endl;
				system("pause");
				break;
			}
			Join(&m_Id_List[m_iId_Count], m_iId_Count, m_Id_List);
			m_iId_Count++;
			break;
		case 2:
			while (!m_bLoginFlag)
			{
				Id_Flag = false;
				PasswordFlag = false;
				system("cls");
				cout << "아이디 입력 : ";
				cin >> TmpId;
				cout << "비밀번호 입력 : ";
				cin >> TmpPassword;
				for (int i = 0; i < m_iId_Count; i++)
				{
					if (TmpId == m_Id_List[i].m_strId)
					{
						Id_Flag = true;
						if (TmpPassword == m_Id_List[i].m_strPassword)
						{
							PasswordFlag = true;
							//Display(&m_Id_List[i]);
							m_bLoginFlag = true;
							return i;
						}
					}
				}
				if (!Id_Flag)
					cout << "해당 아이디가 없습니다." << endl;
				else if (!PasswordFlag)
					cout << "비밀번호가 틀렸습니다." << endl;
			}
			break;
		case 3:
			return 0;
		}
	}
}

void Login::Menu(int Num)
{
	system("cls");
	cout << "=====Login=====(회원수[" << Num << "명])" << endl;
	cout << "   1.회원 가입" << endl;
	cout << "   2.로그인" << endl;
	cout << "   3.종료" << endl;
	cout << "입력 : ";
}

void Login::Join(ID* P1, int Id_Count, ID Id_List[])
{
	bool Flag, Flag2, Flag3;
	int CountNum = 0;
	string CheckPassword;
	while (1)
	{
		Flag = true;
		Flag3 = true;
		system("cls");
		cout << "아이디 입력([3글자↑] AND [한글X]) : ";
		cin >> P1->m_strId;
		for (int i = 0; i < P1->m_strId.length(); i++)
		{
			if (StringCheck('A', 'Z', P1->m_strId[i]) == false && StringCheck('a', 'z', P1->m_strId[i]) == false
				&& StringCheck('0', '9', P1->m_strId[i]) == false)
			{
				Flag = false;
				break;
			}
		}
		for (int i = 0; i < Id_Count; i++)
		{
			if (Id_List[i].m_strId == P1->m_strId)
				Flag3 = false;
		}
		if (!Flag3)
		{
			cout << "동일한 아이디가 존재합니다." << endl;
		}
		if (Flag && Flag3 && P1->m_strId.length() >= IDLEN)
			break;
		if (!Flag)
			cout << "id가 영문이 아닙니다." << endl;
		if (P1->m_strId.length() < IDLEN)
			cout << "id가 세글자 이하 입니다." << endl;
		system("pause");
	}
	while (1)
	{
		Flag = true;
		Flag2 = true;
		system("cls");
		cout << "비밀번호 입력([8글자↑]AND[영문]AND[숫자 포함]) : ";
		cin >> P1->m_strPassword;
		CountNum = 0;
		for (int i = 0; i < P1->m_strPassword.length(); i++)
		{
			if (StringCheck('A', 'Z', P1->m_strPassword[i]) == false && StringCheck('a', 'z', P1->m_strPassword[i]) == false)
			{
				if (P1->m_strPassword[i] >= '0' &&P1->m_strPassword[i] <= '9')
					CountNum++;
				else
					Flag = false;
			}
		}
		cout << "비밀번호 확인 : ";
		cin >> CheckPassword;
		if (CheckPassword != P1->m_strPassword)
			Flag2 = false;
		if (Flag && Flag2 && P1->m_strPassword.length() >= PASSWORDLEN && CountNum >= 1)
			break;
		if (!Flag)
			cout << "password가 영문이 아닙니다." << endl;
		if (P1->m_strPassword.length() < PASSWORDLEN)
			cout << "Password가 여덟글자 이하 입니다." << endl;
		if (CountNum == 0)
			cout << "숫자가 포함되어 있지 않습니다." << endl;
		if (!Flag2)
			cout << "비밀번호가 일치하지 않습니다." << endl;
		system("pause");
	}
	system("cls");
	cout << "닉네임 입력 : ";
	cin >> P1->m_strName;
	cout << "나이 입력 :";
	cin >> P1->m_iAge;
	cout << "휴대폰 번호 입력 : ";
	cin >> P1->m_strPhonNumber;
	cout << "회원가입 성공 !! 마일리지 1000원 등록" << endl;
	P1->m_iMileage = 1000;
	system("pause");
}

bool Login::StringCheck(char Start, char End, char Check)
{
	if (Check >= Start && Check <= End)
		return true;
	else return false;
}

void Login::Display(ID* id)
{
	int Select;
	while (1)
	{
		system("cls");
		cout << "========Menu========" << endl;
		cout << "  1.회원 정보" << endl;
		cout << "  2.회원 정보 변경" << endl;
		cout << "  3.로그아웃" << endl;
		cout << "입력 : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			ShowID(*id);
			system("pause");
			break;
		case 2:
			SetID(id);
			break;
		case 3:
			return;
		}
	}
}

void Login::ShowID(ID id)
{
	system("cls");
	SimpleShowID(id);
	cout << " 나이 : " << id.m_iAge << "살" << "   휴대폰 번호 : " << id.m_strPhonNumber << endl;
	cout << "마일리지 : " << id.m_iMileage << "원" << endl;
}

void Login::SimpleShowID(ID id)
{
	cout << "============회원 정보============" << endl;
	cout << "ID : " << id.m_strId << "   닉네임 : " << id.m_strName << endl;
}

void Login::SetID(ID* id)
{
	int Select;
	while (1)
	{
		ShowID(*id);
		cout << "===================" << endl;
		cout << "1.닉네임 변경" << endl;
		cout << "2.나이 변경" << endl;
		cout << "3.휴대폰 번호 변경" << endl;
		cout << "4.돌아가기" << endl;
		cout << "입력 : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			Setstring(&id->m_strName, "닉네임");
			break;
		case 2:
			Setint(&id->m_iAge, "나이");
			break;
		case 3:
			Setstring(&id->m_strPhonNumber, "휴대폰 번호");
			break;
		case 4:
			return;
		}
	}
}

void Login::Setstring(string* str, string tmp)
{
	string tmpstr;
	tmpstr = *str;
	cout << "현재 " << tmp << ": " << tmpstr << endl;
	cout << "변경할 " << tmp << "입력 : ";
	cin >> *str;
	cout << tmpstr << " -> " << *str << endl;
	system("pause");
}

void Login::Setint(int* num, string tmp)
{
	int tmpint;
	tmpint = *num;
	cout << "현재 " << tmp << " : " << tmpint << endl;
	cout << "변경할 " << tmp << "입력 : ";
	cin >> *num;
	cout << tmpint << " -> " << *num << endl;
	system("pause");
}

Login::~Login()
{
}
