#include <iostream>
#include "MyList.h"
using namespace std;

const int MIN_OPTION = 0;
const int MAX_OPTION = 19;
const int MIN_INT = -2147483648;
const int MAX_INT = 2147483647;

// ----
void changeDataOnIterPosition(MyList<int>& numsList, MyList<int>::MyIterator& iter);
void moveIteratorForward(MyList<int>& numsList, MyList<int>::MyIterator& iter);
void dataOfIterator(MyList<int>& numsList, MyList<int>::MyIterator& iter);
void iteratorBegin(MyList<int>& numsList, MyList<int>::MyIterator& iter);
void findPositionOfDataInList(MyList<int>& numsList);
void findData(MyList<int>& numsList);
void changeDataInList(MyList<int>& numsList);
void removeAtInList(MyList<int>& numsList);
void insertToList(MyList<int>& numsList);
void pushBackToList(MyList<int>& numsList);
void pushFrontToList(MyList<int>& numsList);
void outputList(MyList<int>& numsList, MyList<int>::MyIterator iter);
void fillAutomaticaly(MyList<int>& numsList, const int& size);
void fillManually(MyList<int>& numsList, const int& size);
void fillList(MyList<int>& numsList);
bool actionByChoice(MyList<int>& numsList, MyList<int>::MyIterator& iter, const int& choice);
int enterNumsAndCheck(const int& MIN, const int& MAX);
int printMenu(void);
// ----

void changeDataOnIterPosition(MyList<int>& numsList, MyList<int>::MyIterator& iter)
{
	if (numsList.isEmpty())
	{
		cout << "������. ������ ����." << endl;
		return;
	}

	cout << "������ �������� ��������� = " << *iter << endl;
	cout << "~ ������� ����� �������� ���������: ";
	*iter = enterNumsAndCheck(MIN_INT, MAX_INT);

	cout << "����� �������� �� ������� ��������� = " << *iter << endl;
}

void moveIteratorForward(MyList<int>& numsList, MyList<int>::MyIterator& iter)
{
	if (numsList.isEmpty())
	{
		cout << "������. ������ ����." << endl;
		return;
	}

	iter++;
	cout << "����� �������� ��������� = " << *iter << endl;
}

void dataOfIterator(MyList<int>& numsList, MyList<int>::MyIterator& iter)
{
	if (numsList.isEmpty())
	{
		cout << "������. ������ ����." << endl;
		return;
	}

	cout << "�������� �� ������� ��������� = " << *iter << endl;
}

void iteratorBegin(MyList<int>& numsList, MyList<int>::MyIterator& iter)
{
	if (numsList.isEmpty())
	{
		cout << "������. ������ ����." << endl;
		return;
	}

	int data = iter.begin();
	cout << "�������� ���������� �� ������, ��� ��������: " << data << endl;
}

void findPositionOfDataInList(MyList<int>& numsList)
{
	int value, index;
	cout << "~ ������� ������� ��������, ��� ��������� ��� �������: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);

	try
	{
		index = numsList.findPositionOfData(value);

		cout << "������ ��������: " << index << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}
}

void findData(MyList<int>& numsList)
{
	int value;
	cout << "~ ������� ������� �������� � ������: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);

	cout << "���� �� ����� ��������? " << std::boolalpha << numsList.isThereData(value) << endl;
}

void changeDataInList(MyList<int>& numsList)
{
	int index, value;
	cout << "������ ������ = " << numsList.getSize() << endl;
	cout << "~ ������� ������, ��� ��������� ��������: ";
	index = enterNumsAndCheck(MIN_INT, MAX_INT);
	cout << "~ ������� ��������: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);

	numsList.changeData(index, value);
}

void removeAtInList(MyList<int>& numsList)
{
	int index;
	cout << "������ ������: " << numsList.getSize() << endl;
	cout << "~ ������� ������, ��� �������� ��������: ";
	index = enterNumsAndCheck(MIN_INT, MAX_INT); // ������������ ��������� ����������.

	numsList.removeAt(index);
}

void insertToList(MyList<int>& numsList)
{
	int index;
	int value;

	cout << "������ ������ = " << numsList.getSize() << endl;

	cout << "~ ������� ������: ";
	index = enterNumsAndCheck(MIN_INT, MAX_INT);

	cout << "~ ������� ��������: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);

	numsList.insert(value, index);
}

void pushBackToList(MyList<int>& numsList)
{
	int value;
	cout << "~ ������� �������� ��� ������� � �����: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);
	numsList.push_back(value);
}

void pushFrontToList(MyList<int>& numsList)
{
	int value;
	cout << "~ ������� �������� ��� ������� � ������: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);
	numsList.push_front(value);
}

void outputList(MyList<int>& numsList, MyList<int>::MyIterator iter)
{
	if (numsList.isEmpty())
	{
		cout << "������. ������ ����.\n";
		return;
	}

	iter.begin();
	cout << "������ ������: " << numsList.getSize() << endl;;
	for (iter; iter != numsList.end(); iter++)
		cout << *iter << endl;
}

void fillAutomaticaly(MyList<int>& numsList, const int& size)
{
	for (int i = 0; i < size; i++)
		numsList.push_back(rand() % 1000);
}

void fillManually(MyList<int>& numsList, const int& size)
{
	int value;
	for (int i = 0; i < size; i++)
	{
		cout << "~ ������� �����: ";
		value = enterNumsAndCheck(MIN_INT, MAX_INT);
		numsList.push_back(value);
	}
}

void fillList(MyList<int>& numsList)
{
	if (!(numsList.isEmpty()))
		numsList.clear(); // ������� ������ ����� ����������� ������ �������.

	int size;
	int item;
	cout << "~ ������� �������� ������ ������: ";
	size = enterNumsAndCheck(1, MAX_INT);

	cout << "1. ��������� ������ �������������\n";
	cout << "2. ��������� ������ ��������������\n";
	cout << "~ ��� �����: ";
	item = enterNumsAndCheck(1, 2);
	if (item == 1)
		fillAutomaticaly(numsList, size);
	else
		fillManually(numsList, size);
}

bool actionByChoice(MyList<int>& numsList, MyList<int>::MyIterator& iter, const int& choice)
{
	switch (choice)
	{
	case 0:
	{
		numsList.clear();
		return true;
	}

	case 1:
	{
		fillList(numsList);
		break;
	}

	case 2:
	{
		outputList(numsList, iter);
		break;
	}

	case 3:
	{
		numsList.clear();
		cout << "������ ������!\n";
		break;
	}

	case 4:
	{
		cout << "������ ����? " << std::boolalpha << numsList.isEmpty() << endl;
		break;
	}

	case 5:
	{
		cout << "������ ������: " << numsList.getSize() << endl;
		break;
	}

	case 6:
	{
		pushFrontToList(numsList);
		break;
	}

	case 7:
	{
		pushBackToList(numsList);
		break;
	}

	case 8:
	{
		insertToList(numsList);
		break;
	}

	case 9:
	{
		numsList.pop_front();
		break;
	}

	case 10:
	{
		numsList.pop_back();
		break;
	}

	case 11:
	{
		removeAtInList(numsList);
		break;
	}

	case 12:
	{
		changeDataInList(numsList);
		break;
	}

	case 13:
	{
		findData(numsList);
		break;
	}

	case 14:
	{
		findPositionOfDataInList(numsList);
		break;
	}

	case 15:
	{
		iteratorBegin(numsList, iter);
		break;
	}

	case 16:
	{
		dataOfIterator(numsList, iter);
		break;
	}

	case 17:
	{
		moveIteratorForward(numsList, iter);
		break;
	}
	case 18:
	{
		changeDataOnIterPosition(numsList, iter);
		break;
	}

	case 19:
	{
		system("cls");
		break;
	}
	}

	cout << "������� \"Enter\", ����� ����������.\n";
	cin.get();
	cin.get();

	return false;
}

int enterNumsAndCheck(const int& MIN, const int& MAX)
{
	int choice;
	while (true)
	{
		if ((cin >> choice).good() && (choice >= MIN) && (choice <= MAX))
			return choice;

		if (cin.fail())
			cin.clear();

		cin.ignore(100, '\n');
		cout << "�������� ��������, ��������� ������������ �����.\n";
	}
}

int printMenu(void)
{
	cout << "\n~~~~~~~~~~~~~~~~~~ ���� ~~~~~~~~~~~~~~~~~~\n";
	cout << "1. ���������� ������\n";
	cout << "2. ����� ������ �� �����\n";
	cout << "3. ������� ������\n";
	cout << "4. ��������, ������ ������\n";
	cout << "5. �������� ������ ������\n";
	cout << "6. �������� ����� ������� � ������\n";
	cout << "7. �������� ����� ������� � �����\n";
	cout << "8. �������� ������� �� �������\n";
	cout << "9. ������� ������ �������\n";
	cout << "10. ������� ��������� �������\n";
	cout << "11. ������� ������� �� �������\n";
	cout << "12. �������� ������� �� �������\n";
	cout << "13. ��������� ������� �������� � ������\n";
	cout << "14. �������� ������ �������� � ������\n";
	cout << "15. ���������� �������� �� ������ ������\n";
	cout << "16. �������� �������� �� ������� ���������\n";
	cout << "17. ����������� �������� �����\n"; // TODO
	cout << "18. �������� �������� �� ������� ���������\n"; // TODO
	cout << "19. �������� �������\n";
	cout << "0. �����\n\n";

	cout << "~ ��� �����: ";
	return enterNumsAndCheck(MIN_OPTION, MAX_OPTION);
}

// ������ ��� Windows. ������������ system("cls")
int main()
{
	setlocale(LC_ALL, "rus");

	MyList<int> numsList;
	MyList<int>::MyIterator iter(&numsList);
	int optionFromMenu;
	bool forExit = false;
	while (!forExit)
	{
		optionFromMenu = printMenu();
		forExit = actionByChoice(numsList, iter, optionFromMenu);
	}

	return 0;
}