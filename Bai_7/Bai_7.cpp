/*0
Cài đặt lớp cArray để biểu diễn mảng một chiều các
số nguyên cho phép thực hiện các yêu cầu sau:
 Tạo lập mảng gồm n số nguyên ngẫu nhiên bằng
constructor
 Xuất mảng ra màn hình
 Tìm số âm lớn nhất
 Đếm lần xuất hiện của một số nguyên x
 Kiểm tra mảng có giảm dần không
 Sắp xếp mảng tăng dần*/

#include<iostream>
using namespace std;
class cArray
{
private:
		int* arr;
		int size;
public:
	cArray(int n) {			//Constructor
		size = n;
		arr = new int[size];
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand()%50 ;   // arr[i]=-50 den 49
		}
	}
	void print()     // xuat mang ra man hinh
	{
		for (int i = 0; i < size; i++)
			cout << arr[i]<<"  ";
	}

	int maxNegative()	// số âm lớn nhất 
	{
		int max = -50;
		for (int i = 1; i < size; i++)
			if (arr[i]<0 && arr[i]>max)
				max = arr[i];
		return max;
	}

	int count(int x)   // đếm số lần xuất hiện của số nguyên x
	{
		int count = 0;
		for (int i = 0; i < size; i++)
			if (x == arr[i])
				count++;
		return count;
	}

	bool isDecreasing() {// Kiểm tra mảng có giảm dần khônk
		for (int i = 0; i < size; i++)
			if (arr[i] < arr[i + 1])
				return false;
		return true;
	}
	void sort()     //Sắp xếp mảng tăng dần
	{
		int temp;
		for(int i=0;i<size;i++)
			for(int j=i+1;j<size;j++)
				if (arr[i] > arr[j])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
	}
	~cArray()
	{
		delete[]arr;
	}
};
int main()
{
	srand(time(NULL));
	cArray arr(10);

	arr.print();

	cout << "\n So am lon nhat:" << arr.maxNegative()<<endl;

	int x = 3;
	cout << " So lan so nguyen " << x << " xuat hien:" << arr.count(x)<<endl;

	cout << " Ham co giam dan khong? " << arr.isDecreasing()<<endl;

	cout << "Sap xep lai mang ";
	arr.sort();
	arr.print();

}