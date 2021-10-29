using namespace std;

#include <iostream>

class CDocument
{
public:
	void OnFileOpen()
	{
		cout << "dialog..." << endl;
		cout << "check file status..." << endl;
		cout << "open file ..." << endl;

		Serialize();

		cout << "close file" << endl;
		cout << "update all views..." << endl;
	}

	virtual void Serialize(){};
};

class CDoc : public CDocument
{
public:
	virtual void Serialize()
	{
		cout << "CDoc::Serialize()" << endl;
	}
};
