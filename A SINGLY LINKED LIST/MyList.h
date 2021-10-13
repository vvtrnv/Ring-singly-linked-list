#pragma once
#include <iostream>
using std::exception;
using std::cout;

template <typename T>
class MyList
{
private:
	class Node
	{
	public:
		T data;
		Node* pNext;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int size;
	Node* ficNode; // head

public:
	class MyIterator;

	MyList();
	MyList(const MyList& other);
	~MyList();
	T push_front(T nData);
	T push_back(T nData);
	void clear();
	T pop_back();
	T pop_front();
	T removeAt(const int& index);
	T insert(T nData, const int& index);
	T changeData(const int& index, const T& newData); //  Изменение значения с заданным номером в списке 
	bool isThereData(T findData);  // Опрос наличия заданного значения
	int findPositionOfData(const T& findData);
	int getSize() { return this->size; }
	bool isEmpty();
	Node* end() { return this->ficNode; }

	class MyIterator //вложенный класс,выполняющий функции итератора
	{
		MyList<T>* list;
		Node* currentNode;
	public:
		MyIterator(MyList<T>* list)
		{
			this->list = list;
			this->currentNode = list->ficNode->pNext;
		}

		T operator++(int)
		{
			T temp = currentNode->data;
			this->currentNode = this->currentNode->pNext;
			return temp;
		}

		T& operator *() { return this->currentNode->data; }

		bool operator==(const T& otherData)
		{
			if (this->currentNode->data == otherData)
				return true;
			return false;
		}

		bool operator!=(const T& otherData)
		{
			if (this->currentNode->data == otherData)
				return false;
			return true;
		}

		bool operator!=(Node* otherNode) // Обнаружение конца списка (фиктивного узла)
		{
			if (this->currentNode == otherNode)
				return false;
			return true;
		}

		T begin()
		{
			this->currentNode = this->list->ficNode->pNext;
			return this->currentNode->data;
		}
	};
};

template<typename T>
MyList<T>::MyList()
{
	this->size = 0;
	this->ficNode = new Node(NULL);
	this->ficNode->pNext = ficNode;
}

template<typename T>
MyList<T>::MyList(const MyList& other)
{
	this->size = 0;
	this->ficNode = new Node(NULL);
	this->ficNode->pNext = ficNode;

	Node* temp = this->ficNode;
	for (Node* otherNode = other.ficNode->pNext;
		otherNode != other.ficNode; otherNode = otherNode->pNext)
	{
		Node* item = new Node(otherNode->data, this->ficNode);
		temp->pNext = item;
		temp = temp->pNext;
		this->size++;
	}
}

template<typename T>
MyList<T>::~MyList()
{
	clear();
}

template<typename T>
T MyList<T>::push_front(T nData)
{
	Node* newNode = new Node(nData, ficNode->pNext);
	this->ficNode->pNext = newNode;

	size++;
	return this->ficNode->pNext->data;
}

template<typename T>
T MyList<T>::push_back(T nData)
{
	Node* newNode = new Node(nData, this->ficNode);

	Node* temp = this->ficNode;
	while (temp->pNext != ficNode)
		temp = temp->pNext;

	temp->pNext = newNode;

	size++;
	return temp->pNext->data;
}

template<typename T>
bool MyList<T>::isEmpty()
{
	if (this->size == 0)
		return true;
	else
		return false;
}

template<typename T>
T MyList<T>::pop_front()
{
	try
	{
		if (isEmpty())
			throw exception("Ошибка удаления. Список пуст.\n");

		Node* deleteNode = this->ficNode->pNext;
		this->ficNode->pNext = deleteNode->pNext;

		T* toReturn = new T(deleteNode->data);
		delete deleteNode;

		size--;
		return *toReturn;
	}
	catch (const exception& ex)
	{
		cout << ex.what();
		return NULL;
	}
}


template<typename T>
T MyList<T>::pop_back()
{
	try
	{
		if (isEmpty())
			throw exception("Ошибка удаления. Список пуст\n");

		// Поиск предпоследнего узла.
		Node* previous = this->ficNode;
		while (previous->pNext->pNext != ficNode)
			previous = previous->pNext;

		T* toReturn = new T(previous->pNext->data);
		delete previous->pNext;
		previous->pNext = ficNode;

		size--;
		return *toReturn;
	}
	catch (const exception& ex) {
		cout << ex.what();
		return NULL;
	}
}

template<typename T>
void MyList<T>::clear()
{
	while (size)
		pop_front();
}

template<typename T>
T MyList<T>::removeAt(const int& index)
{
	try
	{
		if (index >= this->size || index < 0)
			throw exception("Ошибка удаления. Такого индекса не существует.\n");
		else if (index == 0)
			return pop_front();
		else if (index == this->size - 1)
			return pop_back();
		else
		{
			Node* previous = this->ficNode->pNext;
			for (int i = 0; i < index - 1; i++)
				previous = previous->pNext;

			Node* toDelete = previous->pNext;
			T* toReturn = new T(toDelete->data);
			previous->pNext = toDelete->pNext;
			delete toDelete;

			size--;
			return *toReturn;
		}
	}
	catch (const exception& ex) {
		cout << ex.what();
		return NULL;
	}
}

template<typename T>
T MyList<T>::insert(T nData, const int& index)
{
	try
	{
		if (index >= this->size || index < 0)
			throw exception("Ошибка добавления. Такого индекса не существует.\n");
		else if (index == 0)
			return push_front(nData);
		else if (index == this->size - 1)
			return push_back(nData);
		else
		{
			Node* previous = this->ficNode->pNext;
			for (int i = 0; i < index - 1; i++)
				previous = previous->pNext;

			Node* newNode = new Node(nData, previous->pNext);
			previous->pNext = newNode;
			size++;

			return previous->pNext->data;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what();
		return NULL;
	}
}

template<typename T>
T MyList<T>::changeData(const int& index, const T& newData)
{
	try
	{
		if (index >= this->size || index < 0)
			throw exception("Ошибка изменения узла. Такого индекса не существует.\n");
		else if (isEmpty())
			throw exception("Ошибка изменения узла. Список пуст");
		else
		{
			Node* previous = this->ficNode->pNext;
			for (int i = 0; i < index - 1; i++)
				previous = previous->pNext;

			previous->pNext->data = newData;

			return previous->pNext->data;
		}
	}
	catch (const exception& ex)
	{
		cout << ex.what();
		return NULL;
	}
}

template<typename T>
bool MyList<T>::isThereData(T findData)
{
	Node* temp = this->ficNode->pNext;
	while (temp != ficNode)
	{
		if (temp->data == findData)
			return true;
		temp = temp->pNext;
	}

	return false;
}

template<typename T>
int MyList<T>::findPositionOfData(const T& findData)
{
	int index = 0;
	Node* temp = this->ficNode->pNext;
	while (temp != ficNode)
	{
		if (temp->data == findData)
			return index;
		temp = temp->pNext;
		index++;
	}

	// Если мы прошли весь список и не нашли нужный элемент.
	throw exception("Такого элемента не найдено!\n");
}