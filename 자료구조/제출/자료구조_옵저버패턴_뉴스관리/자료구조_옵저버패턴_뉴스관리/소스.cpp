#include"Data.h"

void main()
{
	int Select;
	string strTmp;

	while (1)
	{
		system("cls");
		cout << "===����===" << endl;
		cout << " 1. �����" << endl;
		cout << " 2. News ����" << endl;
		cout << " 3. News ������Ʈ" << endl;
		cout << " 4. News ��û" << endl;
		cout << " 5. ����" << endl;
		cout << "���� : ";
		cin >> Select;

		switch (Select)
		{
		case 1:
			cout << "������ �̸��� �Է��ϼ��� : ";
			cin >> strTmp;
			Data::GetInstace()->AddObserver(strTmp);
			break;
		case 2:
			Data::GetInstace()->NotifyObserver();
			break;
		case 3:
			cout << "��系���� �Է��ϼ��� : ";
			cin.ignore();
			getline (cin, strTmp);
			Data::GetInstace()->SetData(strTmp);
			break;
		case 4:
			Data::GetInstace()->Print();
			system("pause");
			break;
		case 5:
			delete Data::GetInstace();
			return;
		}
	}



}