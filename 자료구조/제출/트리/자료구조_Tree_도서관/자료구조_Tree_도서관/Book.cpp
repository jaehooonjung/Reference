#include "Book.h"



Book::Book()
{
}

void Book::BookRegistration(string BookName, string Author, int BookSerialNumber, string RentalPossibility)
{
	m_strBookName = BookName;
	m_strAuthor = Author;
	m_iBookSerialNumber = BookSerialNumber;
	if (RentalPossibility == "X")
		m_RentalPossibility = RentalPossibility;

}

void Book::BookInfoDraw()
{
	cout << "���� : " << m_strBookName << endl;
	cout << "���� : " << m_strAuthor << endl;
	cout << "�ø���ѹ� : " << m_iBookSerialNumber << endl;
	cout << "�뿩���ɿ��� : " << m_RentalPossibility << endl;
}

bool Book::BookInfoModify()
{
	int Select;
	string tmp;
	bool UpdataFlag = false;
	while (1)
	{
		system("cls");
		BookInfoDraw();
		cout << endl;
		cout << "å�� ������ �����մϴ�." << endl;
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. �뿩���ɿ���" << endl;
		cout << "4. ����" << endl;
		cout << "�Է� >>> ";
		cin >> Select;
		if (Select > 0 && Select < 4)
			UpdataFlag = true;

		switch (Select)
		{
		case 1:
			cout << "������ ������ �Է��ϼ���";
			cin >> tmp;
			m_strBookName = tmp;
			break;
		case 2:
			cout << "���ڸ� �����մϴ�. ������ ������ �Է��ϼ���";
			cin >> tmp;
			m_strAuthor = tmp;
		case 3:
			cout << "�뿩���ɿ��θ� �����մϴ�.";
			if (m_RentalPossibility == "O")
				m_RentalPossibility = "X";
			else
				m_RentalPossibility = "O";
			break;
		case 4:
			return UpdataFlag;
		}
		cout << "�����Ϸ�" << endl;
		getch();
	}

}


Book::~Book()
{
}
