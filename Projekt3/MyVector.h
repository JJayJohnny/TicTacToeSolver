#pragma once
#include "GameState.h"

#define VECTOR_BLOCK_SIZE 20

class MyVector {
	GameState* tab;
	int size;
	int actualSize;
public:
	MyVector() {
		tab = nullptr;
		size = 0;
		actualSize = 0;
	}

	void PushBack(GameState &g) {
		if (size == actualSize) {
			GameState* newTab = new GameState[size + VECTOR_BLOCK_SIZE];
			for (int i = 0; i < size; i++)
				newTab[i] = tab[i];
			newTab[size] = g;
			size++;
			actualSize += VECTOR_BLOCK_SIZE;
			delete[] tab;
			tab = newTab;
		}
		else {
			tab[size] = g;
			size++;
		}
	}

	void PopBack(){
		if (size > 0) {
			size--;
		}
	}

	int GetSize() const {
		return size;
	}

	GameState& operator[](int i) { return tab[i]; }

	~MyVector() {
		if (tab != nullptr) {
			delete[] tab;
		}
	}

	/*MyVector& operator=(MyVector *other) {

		if (tab != nullptr)
			delete[] tab;
		size = other->size;
		actualSize = other->actualSize;

		tab = new GameState[actualSize];
		for (int i = 0; i < size; i++)
			tab[i] = other->tab[i];

		return *this;
	}*/

	/*MyVector(MyVector& other) {
		this->size = other.size;
		this->actualSize = other.actualSize;
		this->tab = new GameState[actualSize];
		for (int i = 0; i < size; i++)
			this->tab[i] = other.tab[i];
	}*/
};