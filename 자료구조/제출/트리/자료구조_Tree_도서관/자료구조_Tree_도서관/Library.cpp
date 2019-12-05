#include "Library.h"



Library::Library()
{
	m_BookList = NULL;

	ifstream Load;
	Load.open("�������.txt");
	if (!Load.is_open())
		return;
	else
	{
		string BookName;
		string Author;
		int BookSerialNumber;
		string RentalPossibility;
		while (!Load.eof())
		{
			Book*NewBook = new Book;
			Load >> BookName;
			Load >> Author;
			Load >> BookSerialNumber;
			Load >> RentalPossibility;
			if (SerialNumberSerach(&m_BookList, BookSerialNumber) != NULL)
			{
				delete NewBook;
				continue;
			}
			NewBook->BookRegistration(BookName, Author, BookSerialNumber, RentalPossibility);
			Insert(&m_BookList, &NewBook);
		}
		Load.close();
	}
}

bool Library::NodeNullCheck(BookList*Node)
{
	if (Node->Root == NULL)
		return true;
	else
		return false;
}

BookList*Library::SerialNumberSerach(BookList**Node, int Num)
{
	if (*Node == NULL)
		return NULL;
	else if ((*Node)->Root->BookSerialNumberOutput() == Num)
	{
		(*Node)->Root->BookInfoDraw();
		return (*Node);
	}
	else if ((*Node)->Root->BookSerialNumberOutput() > Num)
		SerialNumberSerach(&(*Node)->Left, Num);
	else if ((*Node)->Root->BookSerialNumberOutput() < Num)
		SerialNumberSerach(&(*Node)->Right, Num);
}

void Library::SaveBook(BookList*Node, ofstream&Save)
{
	if (Node->Root == NULL)
		return;

	Save << Node->Root->BookNameOutput() << " " << Node->Root->AuthorOutput() << " " << Node->Root->BookSerialNumberOutput() << " " << Node->Root->RentalPossibilityOutput();
	if (Node->Left != NULL)
	{
		Save << endl;
		SaveBook(Node->Left, Save);
	}
	if (Node->Right != NULL)
	{
		Save << endl;

		SaveBook(Node->Right, Save);
	}
}

void Library::SaveNewBook()
{
	ofstream Save;
	Save.open("�������.txt");
	if (!Save.is_open())
	{
		system("cls");
		cout << "�������.txt ������ �ջ����ϴ�." << endl;
		getch();
		return;
	}
	else
		SaveBook(m_BookList, Save);
	Save.close();
}

void Library::RegisterNewBook()
{
	ofstream Save;
	Save.open("�������.txt", ios::app);
	if (!Save.is_open())
	{
		system("cls");
		cout << "�������.txt ������ �ջ����ϴ�." << endl;
		getch();
		return;
	}
	string BookName;
	string Author;
	int BookSerialNumber;
	string RentalPossibility;
	Book*NewBook = new Book;

	system("cls");
	cout << "å�� �߰�����մϴ�." << endl;;
	cout << "����� å�� �̸��� �Է��ϼ��� : ";
	cin >> BookName;
	cout << "����� å�� ������ �Է��ϼ��� : ";
	cin >> Author;
	cout << "����� å�� �ø���ѹ��� �Է��ϼ��� : ";
	while (1)
	{
		cin >> BookSerialNumber;
		if (SerialNumberSerach(&m_BookList, BookSerialNumber) == NULL)
			break;
		cout << "�ø���ѹ��� �ߺ��Ǿ����ϴ�. �ٽ��Է��ϼ��� : ";
	}

	RentalPossibility = "X";

	Save << endl;
	Save << BookName << " " << Author << " " << BookSerialNumber << " " << RentalPossibility;
	Save.close();

	NewBook->BookRegistration(BookName, Author, BookSerialNumber, RentalPossibility);
	Insert(&m_BookList, &NewBook);
}

void Library::Insert(BookList**Node, Book**NewBook)
{
	if (*Node == NULL)
	{
		*Node = new BookList;
		(*Node)->Root = *NewBook;
		(*Node)->Left = NULL;
		(*Node)->Right = NULL;
	}
	else
	{
		if ((*Node)->Root == *NewBook)
		{
			cout << "�ߺ��� �����Ͱ� �ֽ��ϴ�.";
			return;
		}
		else if ((*Node)->Root->BookSerialNumberOutput() > (*NewBook)->BookSerialNumberOutput())
		{
			Insert(&(*Node)->Left, &(*NewBook));
		}
		else if ((*Node)->Root->BookSerialNumberOutput() < (*NewBook)->BookSerialNumberOutput())
		{
			Insert(&(*Node)->Right, &(*NewBook));
		}
	}
}

void Library::MenuDraw()
{
	system("cls");
	cout << "\t�����������α׷�" << endl;
	cout << "\t1. �������" << endl;
	cout << "\t2. �������" << endl;
	cout << "\t3. �����˻�" << endl;
	cout << "\t4. ��������" << endl;
	cout << "\t5. ����" << endl;
	cout << "�Է� >>> ";
}

void Library::PreOrder(BookList**Node)
{
	if (*Node)
	{
		(*Node)->Root->BookInfoDraw();
		cout << endl;
		Sleep(300);
		PreOrder(&(*Node)->Left);
		PreOrder(&(*Node)->Right);
	}
}

void Library::InOrder(BookList**Node)
{
	if (*Node)
	{
		InOrder(&(*Node)->Left);
		(*Node)->Root->BookInfoDraw();
		cout << endl;
		Sleep(300);
		InOrder(&(*Node)->Right);
	}

}

void Library::PostOrder(BookList**Node)
{
	if (*Node)
	{
		PostOrder(&(*Node)->Left);
		PostOrder(&(*Node)->Right);
		(*Node)->Root->BookInfoDraw();
		cout << endl;
		Sleep(300);
	}
}

void Library::ShowBookListMenu()
{
	int Select;
	while (1)
	{
		system("cls");
		cout << "\t�ص������Ĺ���� �����ϼ���." << endl;
		cout << "\t1. ������ȸ(PreOrder)" << endl;
		cout << "\t2. ������ȸ(InOrder)" << endl;
		cout << "\t3. ������ȸ(PostOrder)" << endl;
		cout << "\t4. ����" << endl;
		cout << "�Է� >>> ";
		cin >> Select;
		system("cls");
		switch (Select)
		{
		case 1:
			PreOrder(&m_BookList);
			break;
		case 2:
			InOrder(&m_BookList);
			break;
		case 3:
			PostOrder(&m_BookList);
			break;
		case 4:
			return;
		}
		system("pause");
	}
}

void Library::SerachMenu()
{
	system("cls");
	int Num;
	Book*Tmp;
	cout << "�˻��� ������ �ø���ѹ��� �Է��ϼ��� : ";
	cin >> Num;
	Tmp = SerialNumberSerach(&m_BookList, Num)->Root;
	if (Tmp == NULL)
	{
		cout << "�ش� �ø���ѹ��� �����ϴ�." << endl;
		return;
	}
	else
	{
		system("cls");
		Tmp->BookInfoModify();//�������� �� å�� ���� ������Ʈ
		SaveNewBook();
	}
}

void Library::DeleteAll(BookList*Node)
{
	if (NodeNullCheck(Node) == true)
		return;
	else
	{
		if (Node->Left != NULL)
			DeleteAll(Node->Left);
		if (Node->Right != NULL)
			DeleteAll(Node->Right);
		delete Node;
		Node = NULL;
	}
}

BookList* Library::FindMinNode(BookList**Node)
{
	if ((*Node)->Left == NULL)
	{
		BookList*Tmp = (*Node);
		(*Node) = (*Node)->Right;
		return Tmp;
	}
	return FindMinNode(&(*Node)->Left);
}

void Library::NextLink(BookList**Node)
{
	if ((*Node)->Left != NULL && (*Node)->Right != NULL)
	{
		BookList*Tmp = (*Node);
		(*Node) = FindMinNode(&(*Node)->Right);
	}
	else if ((*Node)->Left != NULL)
	{
		(*Node) = (*Node)->Left;
	}
	else if ((*Node)->Right != NULL)
	{
		(*Node) = (*Node)->Right;
	}
	else
		return;
}

bool Library::Delete(BookList**Node, int data)
{
	if (NodeNullCheck(*Node) == true)
		return false;
	else if ((*Node)->Root->BookSerialNumberOutput() > data)
	{
		if(Delete(&(*Node)->Left, data) == true)
			(*Node)->Right = NULL;
	}
	else if ((*Node)->Root->BookSerialNumberOutput() < data)
	{
		if (Delete(&(*Node)->Right, data) == true)
			(*Node)->Right = NULL;
	}
	else
	{
		BookList*Tmp = (*Node);
		NextLink(Node);
		(*Node)->Left = Tmp->Left;
		(*Node)->Right = Tmp->Right;
		delete Tmp;
		Tmp = NULL;
		return true;
	}

	if (NodeNullCheck(*Node) == true)
		return false;
	else if ((*Node)->Root->BookSerialNumberOutput() > data)
	{
		SerialNumberSerach(&(*Node)->Left, data);

	}

}

/*
BookList*Library::SerialNumberSerach(BookList**Node, int Num)
{
	if (*Node == NULL)
		return NULL;
	else if ((*Node)->Root->BookSerialNumberOutput() == Num)
	{
		(*Node)->Root->BookInfoDraw();
		return (*Node)->Root;
	}
	else if ((*Node)->Root->BookSerialNumberOutput() > Num)
		SerialNumberSerach(&(*Node)->Left, Num);
	else if ((*Node)->Root->BookSerialNumberOutput() < Num)
		SerialNumberSerach(&(*Node)->Right, Num);
}
*/

void Library::DeleteMenu()
{
	int data;
	system("cls");
	cout << "������ å�� �ø���ѹ��� �Է��ϼ��� :";
	cin >> data;

	if (SerialNumberSerach(&m_BookList, data) != NULL)
	{
		Delete(&m_BookList, data);
		cout << endl << "�����Ϸ�" << endl;
		SaveNewBook();
	}
	else
	{
		cout << endl << "�ش� �ø���ѹ��� å�� �����ϴ�." << endl;
	}
	getch();
	return;
}

void Library::LibraryMain()
{
	int Select;
	while (1)
	{
		MenuDraw();
		cin >> Select;

		switch (Select)
		{
		case 1: //������� 
			RegisterNewBook();
			break;
		case 2: //������� 
			ShowBookListMenu();
			break;
		case 3: //�����˻�
			SerachMenu();
			break;
		case 4: // ��������
			DeleteMenu();
			break;
		case 5:
			return;

		}
		system("pause");
	}

}

Library::~Library()
{
	DeleteAll(m_BookList);
}


