#include "Computer.h"



Computer::Computer()
{
	m_strname = "Atents";
	m_strgr = "GTX990";
	m_strcpu = "I7";
	m_strmemo = "8G";
}


void Computer::COMdisplay()
{
	int tmp;
	int isel;
	while (1)
	{
		isel = NULL;
		tmp=LoginMain();
		if (m_bLoginFlag != true)
			return;
		cout << "����ȣ ��ǻ�� on" << endl;
		Sleep(3000);
		system("cls");
		while (isel != 5) 
		{
			cout << "===== ȯ �� �� �� �� =====" << endl;
			cout << "1.��ǻ�� ����" << endl;
			cout << "2.�� ��" << endl;
			cout << "3.ȸ�� ����" << endl;
			cout << "4.ȸ�� ���� ����" << endl;
			cout << "5.off" << endl;
			cout << "�Է� >>>> ";
			cin >> isel;
			switch (isel) {
			case 1:
				condition();
				break;
			case 2:
				function();
				break;
			case 3:
				ShowID(m_Id_List[tmp]);
				system("pause");
				break;

			case 4:
				SetID(&m_Id_List[tmp]);
				break;

			case 5:
				for (int i = 5; i > 0; i--)
				{
					cout << "off " << i << " ����" << endl;
					Sleep(1000);
				}
				break;
			}

			system("pause");
			system("cls");
		}
	}
}

void Computer::condition()
{
	system("cls");
	cout << "�� ǰ �� : " << m_strname << endl;
	cout << "���� ���� : ON " << endl;
	cout << "�׷���ī�� : " << m_strgr << endl;
	cout << "C P U : " << m_strcpu << endl;
	cout << "�� �� �� : " << m_strmemo << endl;
}

void Computer::function()
{
	int i;
	system("cls");
	while (true) {
		cout << "1.�� �� ��" << endl;
		cout << "2.�� �� ��" << endl;
		cout << "3.�� �� ��" << endl;
		cout << "4.���ư���" << endl;
		cout << "���� >>>>"; cin >> i;
		switch (i) {
		case 1:
			system("calc");
			break;
		case 2:
			system("notepad");
			break;
		case 3:
			system("mspaint");
			break;
		default:
			return;
		}
		system("pause"); system("cls");
	}
}

Computer::~Computer()
{
}
