// Pointer.cpp
// Created by gparap

#include <iostream>

using namespace std;

void addOne(int *value) {
	(*value)++;
}
void addOne(int &value) {
	value++;
}

int main() {
	//PTRS
	//----
	cout << "Ptrs: " << endl;
	//init all
	int *ptr = nullptr;
	int var = 9;
	LOG(var);

	// change memory data (stack)
	ptr = &var;
	*ptr = 10;
	LOG(ptr);
	LOG(var);

	//allocate and deallocate (heap)
	char *charArray = new char[4];
	memset(charArray, 1, 4);
	delete[] charArray;

	//REFS
	//----
	cout << "Refs: " << endl;
	var = 11;
	int &ref = var;
	LOG(ref);
	LOG(&ref);

	addOne(&var);
	cout << "var = "; LOG(var);
	addOne(var);
	cout << "var = "; LOG(var);

	// hold screen
	cin.get();
}
