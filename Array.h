#pragma once
#include "User.h"

template <class T> 
class Array {
private:
	T* entities;
	int numberMaxOfLength;
	int currentLength;
public:
	//Constructor fara parametrii
	Array() {
		this->currentLength = 0;
		this->entities = new T[30];
		this->numberMaxOfLength = 30;
	};
	//Destructor
	~Array() = default;
	
	//Functie care adauga un element general in array
	void addElement(T element) {
		if (numberMaxOfLength == currentLength) this->resizeCapacity();
		this->entities[currentLength] = element;
		currentLength++;
	};
	
	//Functie care mareste dimensiunea maxima a arrayului in cazul in care cea declarata mai sus 
	//a fost egalata
	void resizeCapacity() {
		T* auxiliar = new T[numberMaxOfLength];
		for (int i = 0; i < numberMaxOfLength; i++) auxiliar[i] = this->entities[i];

		delete[]entities;
		int newNumberMaxOfLength = numberMaxOfLength + 10;
		entities = new T[newNumberMaxOfLength];
		for (int i = 0; i < numberMaxOfLength; i++) entities[i] = auxiliar[i];
		this->numberMaxOfLength += 10;
		delete[] auxiliar;
	}
	
	//Returneaza dimensiunea curenta a array-ului
	int getCurrentLength() {
		return this->currentLength;
	}

	//Returneaza un vector dinamic de tip T cu toate elementele arrayului generic
	T* getAll() {
		return entities;
	}

	//Functie care sterge elementul dat ca si parametru din array
	void deleteElement(T element) {
		for (int i = 0; i < this->getCurrentLength() ; i++)
		{
			if (element == this->entities[i])
			{
				for (int j = i; j < this->getCurrentLength(); j++)
					this->entities[j] = this->entities[j + 1];
				
			}

		}
		this->currentLength-- ;
	}

	//Returneaza un element de tip T de pe pozitia i din array
	T& getElemByPos(int i) {
		return this->entities[i];
	}

};

