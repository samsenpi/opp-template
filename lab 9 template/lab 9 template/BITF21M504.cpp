
#include"iostream"
//#include "Array "
using namespace std;



template<class t>



class Array
{

	t* data;
	int size;

public:

	//default constructor

	Array()
	{
		this->size = 5;
		data = new t[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = 0;
		}

	}


	//para constructor

	Array(int s)
	{
		size = s;

		data = new t[size];

		for (int i = 0; i < size;i++)
		{
			data[i] = 0;
		}

	}

	//copy constructor

	Array(const Array& obj)
	{
		this->size = obj.size;

		data = new t[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = obj.data[i];
		}

	}


	//destructor

	~Array()
	{



		delete[]data;

	}

	//member -function

	int getSize() {

		return size;
	}

	void setELement(t k, int i)
	{
		if (i >= 0 && i < size) {
			data[i] = k;
		}
		else {
			cout << "error invalid index." << endl;
		}
	}

	int countElement(t key)
	{
		int count = 0;

		for (int i = 0; i < size; i++)
		{
			if (data[i] == key) {
				count++;

			}
		}
		return count;
	}

	Array operator=(const Array& obj)
	{

		if (this != &obj)
		{
			if (size != obj.size) {

				delete[]data;
				size = obj.size;
				data = new t[size];
				for (int i = 0; i < size; i++)
				{
					data[i] = obj.data[i];
				}
			}
			else
			{
				for (int i = 0; i < size; i++)
				{
					data[i] = obj.data[i];
				}
			}



		}
		return *this;
	}

	Array getSubArray(int start, int end)
	{
		if (start >= 0 && start < size && end >= 0 && end < size)
		{
			size = (end - start) + 1;

			Array obj(size);
			int j = 0;
			for (int i = start; i < size; i++)
			{
				obj.data[j] = data[i];
				j++;
			}
			return obj;
		}
		else {
			cout << "error in index." << endl;

			Array obj2(0);
			obj2.data = NULL;
			return obj2;

		}

	}
	Array operator+(const Array& obj)const
	{

		int ns = size + obj.size;

		Array result(ns);

		for (int i = 0;i < size;i++)
		{

			result.data[i] = data[i];
		}
		int i = 0;
		for (int j = size;j < ns;j++) {


			result.data[j] = obj.data[i];
			i++;
		}

		return result;
	}

	bool operator==(const Array& obj)
	{

		/*if (size != obj.size)
		{
			return false;
		}*/

		for (int i = 0;i < size;i++)
		{

			if (data[i] == obj.data[i])
			{
				return true;
			}

			return false;
		}
	}

		t& operator[](int index)
		{


			if (index >= 0 && index < size)
			{
				return data[index];

			}
			else
			{
				cout << "error out off the bound" << endl;
				static int i = -1;
				return i;
			}


		}
		t operator[](int index)const
		{
			if (index >= 0 && index < size)
			{
				return data[index];
			}
			else {
				cout << "out of th bound error!" << endl;
				return -1;
			}
		}

		friend ostream& operator<<(ostream & out, const Array & obj)
		{
			for (int i = 0; i < obj.size; i++)
			{
				out << obj.data[i];
			}
			return out;
		}

		friend istream& operator>>(istream & in, Array & obj)
		{
			for (int i = 0; i < obj.size;i++)
			{


				cout << "enter input for arr[" << i << "]:";
				in >> obj.data[i];
			}
			return in;
		}
	

};

	int main()
	{

		Array<int> arr1;

		// create an empty Array object with size 10
		Array<int> arr2(10);

		// insert elements into arr1
		arr1.setELement(3, 0);
		arr1.setELement(7, 1);
		arr1.setELement(2, 2);
		arr1.setELement(5, 3);
		arr1.setELement(1, 4);

		// display the contents of arr1 using stream extraction (<<)
		cout << "arr1: " << arr1 << endl;

		// display the size of arr1 using getSize()
		cout << "size of arr1: " << arr1.getSize() << endl;

		// create a copy of arr1 using copy constructor
		Array<int> arr3(arr1);

		// display the contents of arr3 using stream extraction (<<)
		cout << "arr3: " << arr3 << endl;

		// insert an element into arr3 using setElement()
		arr3.setELement(10, 1);

		// display the contents of arr3 using stream extraction (<<)
		cout << "arr3: " << arr3 << endl;

		// check if arr1 and arr3 are equal using comparison operator (==)
		cout << "Checking an array :" << arr1.operator==(arr3);
		


		// create a sub-array of arr1 using getSubArray()
		Array<int> subarr = arr1.getSubArray(1, 3);

		// display the contents of subarr using stream extraction (<<)
		cout << "subarr: " << subarr << endl;

		// append arr3 to arr1 using arithmetic binary operator (+)
		Array<int> arr4 = arr1 + arr3;

		// display the contents of arr4 using stream extraction (<<)
		cout << "arr4: " << arr4 << endl;

		// access an element of arr using subscript operator []
		cout << "arr1[2]: " << arr1[2] << endl;

		// create an Array object with default size 5 for float data type
		Array<float> floatArr1;

		// insert elements into floatArr1
		floatArr1.setELement(2.71f, 1);
		floatArr1.setELement(3.14f, 0);
		floatArr1.setELement(1.23f, 2);
		floatArr1.setELement(4.56f, 3);
		floatArr1.setELement(7.89f, 4);

		// display the contents of floatArr1 using stream extraction (<<)
		cout << "floatArr1: " << floatArr1 << endl;

		// display the size of floatArr1 using getSize()
		cout << "size of floatArr1: " << floatArr1.getSize() << endl;

		// create an empty Array object with default size 5 for char data type

		return 0;
	}
