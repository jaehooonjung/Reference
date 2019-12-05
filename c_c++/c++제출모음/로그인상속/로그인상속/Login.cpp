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
				cout << "���̻� ȸ���� ����� �� �����ϴ�." << endl;
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
				cout << "���̵� �Է� : ";
				cin >> TmpId;
				cout << "��й�ȣ �Է� : ";
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
					cout << "�ش� ���̵� �����ϴ�." << endl;
				else if (!PasswordFlag)
					cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
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
	cout << "=====Login=====(ȸ����[" << Num << "��])" << endl;
	cout << "   1.ȸ�� ����" << endl;
	cout << "   2.�α���" << endl;
	cout << "   3.����" << endl;
	cout << "�Է� : ";
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
		cout << "���̵� �Է�([3���ڡ�] AND [�ѱ�X]) : ";
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
			cout << "������ ���̵� �����մϴ�." << endl;
		}
		if (Flag && Flag3 && P1->m_strId.length() >= IDLEN)
			break;
		if (!Flag)
			cout << "id�� ������ �ƴմϴ�." << endl;
		if (P1->m_strId.length() < IDLEN)
			cout << "id�� ������ ���� �Դϴ�." << endl;
		system("pause");
	}
	while (1)
	{
		Flag = true;
		Flag2 = true;
		system("cls");
		cout << "��й�ȣ �Է�([8���ڡ�]AND[����]AND[���� ����]) : ";
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
		cout << "��й�ȣ Ȯ�� : ";
		cin >> CheckPassword;
		if (CheckPassword != P1->m_strPassword)
			Flag2 = false;
		if (Flag && Flag2 && P1->m_strPassword.length() >= PASSWORDLEN && CountNum >= 1)
			break;
		if (!Flag)
			cout << "password�� ������ �ƴմϴ�." << endl;
		if (P1->m_strPassword.length() < PASSWORDLEN)
			cout << "Password�� �������� ���� �Դϴ�." << endl;
		if (CountNum == 0)
			cout << "���ڰ� ���ԵǾ� ���� �ʽ��ϴ�." << endl;
		if (!Flag2)
			cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
		system("pause");
	}
	system("cls");
	cout << "�г��� �Է� : ";
	cin >> P1->m_strName;
	cout << "���� �Է� :";
	cin >> P1->m_iAge;
	cout << "�޴��� ��ȣ �Է� : ";
	cin >> P1->m_strPhonNumber;
	cout << "ȸ������ ���� !! ���ϸ��� 1000�� ���" << endl;
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
		cout << "  1.ȸ�� ����" << endl;
		cout << "  2.ȸ�� ���� ����" << endl;
		cout << "  3.�α׾ƿ�" << endl;
		cout << "�Է� : ";
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
	cout << " ���� : " << id.m_iAge << "��" << "   �޴��� ��ȣ : " << id.m_strPhonNumber << endl;
	cout << "���ϸ��� : " << id.m_iMileage << "��" << endl;
}

void Login::SimpleShowID(ID id)
{
	cout << "============ȸ�� ����============" << endl;
	cout << "ID : " << id.m_strId << "   �г��� : " << id.m_strName << endl;
}

void Login::SetID(ID* id)
{
	int Select;
	while (1)
	{
		ShowID(*id);
		cout << "===================" << endl;
		cout << "1.�г��� ����" << endl;
		cout << "2.���� ����" << endl;
		cout << "3.�޴��� ��ȣ ����" << endl;
		cout << "4.���ư���" << endl;
		cout << "�Է� : ";
		cin >> Select;
		switch (Select)
		{
		case 1:
			Setstring(&id->m_strName, "�г���");
			break;
		case 2:
			Setint(&id->m_iAge, "����");
			break;
		case 3:
			Setstring(&id->m_strPhonNumber, "�޴��� ��ȣ");
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
	cout << "���� " << tmp << ": " << tmpstr << endl;
	cout << "������ " << tmp << "�Է� : ";
	cin >> *str;
	cout << tmpstr << " -> " << *str << endl;
	system("pause");
}

void Login::Setint(int* num, string tmp)
{
	int tmpint;
	tmpint = *num;
	cout << "���� " << tmp << " : " << tmpint << endl;
	cout << "������ " << tmp << "�Է� : ";
	cin >> *num;
	cout << tmpint << " -> " << *num << endl;
	system("pause");
}

Login::~Login()
{
}
