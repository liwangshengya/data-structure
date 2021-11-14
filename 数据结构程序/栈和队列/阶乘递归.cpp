#include<iostream>
using namespace std;
#include<time.h>
const int MAX = 150;

class BigInt
{
public:
	BigInt() ;
	BigInt(int n);
	BigInt& operator=(BigInt bg);
	friend BigInt operator+(BigInt num1, BigInt num2);
	friend BigInt operator *(BigInt num1, BigInt num2);
	friend ostream& operator<<(ostream& cout, BigInt x);
	int* operator [](int i) { return num; }
	int getdigit() { return digit; }
	~BigInt();

private:
	int num[MAX] = {0};
	int digit;
};
BigInt::BigInt()
{
	digit = 0;
	
}
BigInt::BigInt(int n)
{
	int i;
	i = 0; 
	while(n)
	{
		i++;
		num[i - 1] = n % 10;
		n = n / 10;

	}
	digit = i;
	
}
BigInt& BigInt::operator=(BigInt bg)
{
	this->digit = bg.digit;
	for (int i = 0; i <digit; i++)
	{
		num[i] = bg.num[i];
	}
	return *this;
}
BigInt::~BigInt()
{
}
BigInt operator+(BigInt num1, BigInt num2)
{
	BigInt result;
	int i = 0;
	int carry = 0;
	result.digit = num1.digit ? num2.digit : num1.digit, num2.digit;
	for (int i = 0; i < num1.digit; i++)
	{
		result.num[i] = num1.num[i];
	}

	for (i = 0; i < num2.digit; i++)
	{
		result.num[i] = result.num[i] + num2.num[i] + carry;
		//cout << "result.num[i]=" << result.num[i] << endl;
		carry = result.num[i] / 10;
	//	cout << "carry=" << carry << endl;
		result.num[i] = result.num[i] % 10;
		//cout << "result.num[i]=" << result.num[i] << endl;

	}
//	cout << "i=" << i << endl;
	if (carry) result.num[i] = result.num[i] + carry;
	//cout << "result.num[i]=" << result.num[i] << endl;
	if (carry && result.digit == num2.digit)  result.digit++;
	//cout << "result.digit=" << result.digit << endl;
	return result;
}


BigInt operator*(BigInt num1, BigInt num2)
{
	BigInt result;
	result.digit = num1.digit + num2.digit;
	int i, j, pos;
	int carry, temp;
	for ( i = 0; i <num2.digit; i++)
	{
		carry = 0;
		for ( j = 0; j < num1.digit; j++)
		{
			temp = num2.num[i] * num1.num[j] + carry;
			carry = temp / 10;
			temp = temp % 10;
			pos = i + j;
			result.num[pos] += temp;
			carry = carry + result.num[pos] / 10;
			result.num[pos] = result.num[pos] % 10;
		}
		if (carry > 0)
		{
			result.num[i + j] = carry;
			result.digit = i + j + 1;
		}
		else result.digit = i + j;
	}
	return result;
}
ostream& operator<<(ostream& cout, BigInt x)
{
	for (int i = x.digit-1; i>=0; i--)
	{
		cout << x.num[i];
	}
	cout << endl;
	//cout << x.digit << endl;
	return cout;
}
BigInt jc[MAX] = { BigInt(1),BigInt(1),BigInt(0) };
BigInt jiecheng3(int n)
{
	if (jc[n].getdigit() != 0) return jc[n];
	if (n == 0) return BigInt(1);
	return jc[n]=BigInt(n)* jiecheng3(n - 1);
}
int jiecheng1(int n)
{
	
	if (n == 0) return 1;
	else return n*jiecheng1(n - 1);
}

int main()
{
	int n;
	cout<<"请输入一个整数"<<endl;
	cin>>n;
	cout<<"非大数运算"<<jiecheng1(n)<<endl;
	cout<<"大数运算:"<<jiecheng3(n)<<endl;
}