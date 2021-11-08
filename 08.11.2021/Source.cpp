#include <iostream>
using namespace std;

class Fraction
{
	int numerator;
	int denumerator;


	void NOD()
	{

		int n = numerator;
		int d = denumerator;
		while (n != 0 && d != 0)
		{
			if (n > d)
			{
				n = n % d;
			}
			else
			{
				d = d % n;
			}
		}
		numerator = numerator / (n + d);
		denumerator = denumerator / (n + d);

	}

public:

	Fraction(int numerator = 0, int denumerator = 1)
	{
		this->numerator = numerator;
		if (denumerator != 0)
		{
			this->denumerator = denumerator;
		}
		else
		{
			this->denumerator = 1;
		}
	}
	void SetDenumerator(int denumerator)
	{
		if (denumerator != 0)
		{
			this->denumerator = denumerator;
		}
		else
		{
			this->denumerator = 1;
		}
	}

	void SetNumerator(int numerator)
	{
		this->numerator = numerator;
	}

	int GetDenumerator()
	{
		return this->denumerator;
	}

	int GetNumerator()
	{
		return this->numerator;
	}

	void print()
	{
		NOD();
		cout << this->numerator << "/" << this->denumerator << "\n";
	}

	void add(const Fraction& fodj)
	{
		this->numerator = this->numerator * fodj.denumerator + this->denumerator * fodj.numerator;
		this->denumerator = this->denumerator * fodj.denumerator;
	}

	Fraction plus(const Fraction& fodj) //не создается копия и безопасность для себя что бы не изменить fobj
	{
		Fraction temp;
		temp.numerator = this->numerator * fodj.denumerator + this->denumerator * fodj.numerator;
		temp.denumerator = this->denumerator * fodj.denumerator;
		return temp;
	}

};

class Darray
{
	int size;
	int* items;

public:

	Darray(int size = 0)
	{
		cout << "\nМассив создан\n";
		items = new int[size] {1,2,3,4,5,6,7,8,9};
	}

	~Darray()
	{
		cout << "\nМассив удалён\n";
		delete[] items;
	}
};



int main()
{
	setlocale(LC_ALL, "Rus");
	Fraction f1(5, 6);
	Fraction f2(2, 3);
	Fraction f3(3, 8);

	f1.add(f2);
	f1.print();

	f3 = f1.plus(f2);
	f3.print();

	Fraction* pf = new Fraction(2, 4);
	pf->print();
	delete pf;

	//Darray array(10);
	
	{
		Darray* Array = new Darray(10);
		delete Array;
	}







	return 0;
}