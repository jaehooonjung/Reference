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
		cout << "최정호 컴퓨터 on" << endl;
		Sleep(3000);
		system("cls");
		while (isel != 5) 
		{
			cout << "===== 환 영 합 니 다 =====" << endl;
			cout << "1.컴퓨터 상태" << endl;
			cout << "2.기 능" << endl;
			cout << "3.회원 정보" << endl;
			cout << "4.회원 정보 변경" << endl;
			cout << "5.off" << endl;
			cout << "입력 >>>> ";
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
					cout << "off " << i << " 초전" << endl;
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
	cout << "제 품 명 : " << m_strname << endl;
	cout << "현재 상태 : ON " << endl;
	cout << "그래픽카드 : " << m_strgr << endl;
	cout << "C P U : " << m_strcpu << endl;
	cout << "메 모 리 : " << m_strmemo << endl;
}

void Computer::function()
{
	int i;
	system("cls");
	while (true) {
		cout << "1.계 산 기" << endl;
		cout << "2.메 모 장" << endl;
		cout << "3.그 림 판" << endl;
		cout << "4.돌아가기" << endl;
		cout << "선택 >>>>"; cin >> i;
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
