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
		cout << "Ошибка. Список пуст." << endl;
		return;
	}

	cout << "Старое значение итератора = " << *iter << endl;
	cout << "~ Введите новое значение итератора: ";
	*iter = enterNumsAndCheck(MIN_INT, MAX_INT);

	cout << "Новое значение на позиции итератора = " << *iter << endl;
}

void moveIteratorForward(MyList<int>& numsList, MyList<int>::MyIterator& iter)
{
	if (numsList.isEmpty())
	{
		cout << "Ошибка. Список пуст." << endl;
		return;
	}

	iter++;
	cout << "Новое значение итератора = " << *iter << endl;
}

void dataOfIterator(MyList<int>& numsList, MyList<int>::MyIterator& iter)
{
	if (numsList.isEmpty())
	{
		cout << "Ошибка. Список пуст." << endl;
		return;
	}

	cout << "Значение на позиции итератора = " << *iter << endl;
}

void iteratorBegin(MyList<int>& numsList, MyList<int>::MyIterator& iter)
{
	if (numsList.isEmpty())
	{
		cout << "Ошибка. Список пуст." << endl;
		return;
	}

	int data = iter.begin();
	cout << "Итератор установлен на начало, его значение: " << data << endl;
}

void findPositionOfDataInList(MyList<int>& numsList)
{
	int value, index;
	cout << "~ Введите искомое значение, для получения его индекса: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);

	try
	{
		index = numsList.findPositionOfData(value);

		cout << "Индекс элемента: " << index << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what();
	}
}

void findData(MyList<int>& numsList)
{
	int value;
	cout << "~ Введите искомое значение в списке: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);

	cout << "Есть ли такое значение? " << std::boolalpha << numsList.isThereData(value) << endl;
}

void changeDataInList(MyList<int>& numsList)
{
	int index, value;
	cout << "Размер списка = " << numsList.getSize() << endl;
	cout << "~ Введите индекс, для изменения элемента: ";
	index = enterNumsAndCheck(MIN_INT, MAX_INT);
	cout << "~ Введите значение: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);

	numsList.changeData(index, value);
}

void removeAtInList(MyList<int>& numsList)
{
	int index;
	cout << "Размер списка: " << numsList.getSize() << endl;
	cout << "~ Введите индекс, для удаления элемента: ";
	index = enterNumsAndCheck(MIN_INT, MAX_INT); // Демонстрация обработки исключений.

	numsList.removeAt(index);
}

void insertToList(MyList<int>& numsList)
{
	int index;
	int value;

	cout << "Размер списка = " << numsList.getSize() << endl;

	cout << "~ Введите индекс: ";
	index = enterNumsAndCheck(MIN_INT, MAX_INT);

	cout << "~ Введите значение: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);

	numsList.insert(value, index);
}

void pushBackToList(MyList<int>& numsList)
{
	int value;
	cout << "~ Введите значение для вставки в конец: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);
	numsList.push_back(value);
}

void pushFrontToList(MyList<int>& numsList)
{
	int value;
	cout << "~ Введите значение для вставки в начало: ";
	value = enterNumsAndCheck(MIN_INT, MAX_INT);
	numsList.push_front(value);
}

void outputList(MyList<int>& numsList, MyList<int>::MyIterator iter)
{
	if (numsList.isEmpty())
	{
		cout << "Ошибка. Список пуст.\n";
		return;
	}

	iter.begin();
	cout << "Размер списка: " << numsList.getSize() << endl;;
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
		cout << "~ Введите число: ";
		value = enterNumsAndCheck(MIN_INT, MAX_INT);
		numsList.push_back(value);
	}
}

void fillList(MyList<int>& numsList)
{
	if (!(numsList.isEmpty()))
		numsList.clear(); // Очищаем список перед заполнением новыми данными.

	int size;
	int item;
	cout << "~ Введите желаемый размер списка: ";
	size = enterNumsAndCheck(1, MAX_INT);

	cout << "1. Заполнить список автоматически\n";
	cout << "2. Заполнить список самостоятельно\n";
	cout << "~ Ваш выбор: ";
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
		cout << "Список очищен!\n";
		break;
	}

	case 4:
	{
		cout << "Список пуст? " << std::boolalpha << numsList.isEmpty() << endl;
		break;
	}

	case 5:
	{
		cout << "Размер списка: " << numsList.getSize() << endl;
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

	cout << "Нажмите \"Enter\", чтобы продолжить.\n";
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
		cout << "Неверное значение, проверьте правильность ввода.\n";
	}
}

int printMenu(void)
{
	cout << "\n~~~~~~~~~~~~~~~~~~ Меню ~~~~~~~~~~~~~~~~~~\n";
	cout << "1. Заполнение списка\n";
	cout << "2. Вывод списка на экран\n";
	cout << "3. Очистка списка\n";
	cout << "4. Проверка, пустой список\n";
	cout << "5. Получить размер списка\n";
	cout << "6. Добавить новый элемент в начало\n";
	cout << "7. Добавить новый элемент в конец\n";
	cout << "8. Вставить элемент по индексу\n";
	cout << "9. Удалить первый элемент\n";
	cout << "10. Удалить последний элемент\n";
	cout << "11. Удалить элемент по индексу\n";
	cout << "12. Изменить элемент по индексу\n";
	cout << "13. Проверить наличие значения в списке\n";
	cout << "14. Получить индекс значения в списке\n";
	cout << "15. Установить итератор на начало списка\n";
	cout << "16. Получить значение на позиции итератора\n";
	cout << "17. Передвинуть итератор вперёд\n"; // TODO
	cout << "18. Изменить значение на позиции итератора\n"; // TODO
	cout << "19. ОЧИСТИТЬ КОНСОЛЬ\n";
	cout << "0. Выход\n\n";

	cout << "~ Ваш выбор: ";
	return enterNumsAndCheck(MIN_OPTION, MAX_OPTION);
}

// Только для Windows. Используется system("cls")
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