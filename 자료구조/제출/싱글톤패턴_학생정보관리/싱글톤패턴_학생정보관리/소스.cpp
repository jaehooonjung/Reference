#include"Std_manager.h"

void main() 
{
	int sel;
	while (true)
	{
		cout << "=========================" << endl;
		cout << "   1.�л� ���" << endl;
		cout << "   2.��ü �л����� ���" << endl;
		cout << "   3.�л� ��ȣ �˻�" << endl;
		cout << "   4.�л� �̸� �˻�" << endl;
		cout << "   5.��޺� ���" << endl;
		cout << "   0.����" << endl;
		cout << "=========================" << endl;
		cin >> sel;
		switch (sel) {
		case 1:
			Std_manager::GetInstace()->setStudent();
			break;
		case 2:
			Std_manager::GetInstace()->showStudent();
			break;
		case 3:
			Std_manager::GetInstace()->findNumber();
			break;
		case 4:
			Std_manager::GetInstace()->findname();
			break;
		case 5:
			Std_manager::GetInstace()->findClass();
			break;
		case 0:
			delete Std_manager::GetInstace();
			return;

		
		default:cout << "�߸� �Է� " << endl;
		}
		system("pause"); system("cls");
	}

}