#include <iostream>
#include <set>
#include <memory>
#include <cmath>
#include "Hashmap.h"

using namespace std;

struct Node
{
public:
	Node(int a, string b) : dummy(a), dummy1(b) {};
	int dummy;
	string dummy1;
};

int main()
{
	int size = 0;
	while (1)
	{
		cout << "Please specify the initial size of the map ";
		cin >> size;
		if ((size > 0 && size < INT_MAX))
			break;
		cout << "Please enter a valid number" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	Hashmap<shared_ptr<Node>> h1(size);
	cout << "Current load is " << h1.load() << endl;
	cout << endl;

	string temp = "";

	// Test setting values
	while (1)
	{
		cout << "Please specify the number of elements to attempt to insert ";
		try {
			cin >> size;
			if ((size > 0 && size < INT_MAX))
				break;
			cout << "Please enter a valid number" << endl;
		}
		catch (...) {
			cout << "Please enter a valid number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	for (int i = 1; i <= size; i++)
	{
		cout << "Test " << i << endl;
		auto n3 = make_shared<Node>(i*10, "s"+to_string(i));
		cout << "Address of the current Object: " << n3 << endl;
		if (h1.set("" + to_string(i), n3))
		{
			cout << "Success! " << endl;
			cout << "Values : " << h1.getValue("" +
				to_string(i))->dummy << " " << 
				h1.getValue("" + to_string(i))->dummy1 << endl;
		}
		else
		{
			cout << "Failure" << endl;
			cout << "Collision with ";
			cout << "Values : " << h1.getValue("" +
				to_string(i))->dummy << " " <<
				h1.getValue("" + to_string(i))->dummy1 << endl;
		}
		cout << "Current load is : " << h1.load() << endl;
		cout << endl;
	}

	// Test deleting values
	while (1)
	{
		cout << "Please specify the number of elements to attempt to delete ";
		try {
			cin >> size;
			if ((size > 0 && size < INT_MAX))
				break;
			cout << "Please enter a valid number" << endl;
		}
		catch (...) {
			cout << "Please enter a valid number" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	for (int i = 1; i <= size; i++)
	{
		cout << "Test " << i << endl;
		auto n3 = h1.deleteValue(to_string(i));
		if (n3)
		{
			cout << "Success! " << endl;
			cout << "Values : " << n3->dummy << " " << n3->dummy1 << endl;
		}
		else
		{
			cout << "Failure" << endl;
			cout << "No value associated with " << i << endl;
		}
		cout << "Current load is : " << h1.load() << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}