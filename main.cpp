#include <iostream>
#include <set>
#include <memory>
#include "Hashmap.h"

using namespace std;

struct Node
{
	int dummy;
	string dummy1;
};

int main()
{
	Hashmap<shared_ptr<Node>> h1(5);
	cout << h1.load() << endl;

	shared_ptr<Node> n1(new Node());
	n1->dummy = 11;
	n1->dummy1 = "one";

	h1.set("first", n1);
	cout << h1.load() << endl;
	cout << h1.getValue("first")->dummy << " " << h1.getValue("first")->dummy1<< endl;

	cout << h1.deleteValue("first") << endl;
	cout << h1.load() << endl;
	
	system("pause");
	return 0;
}