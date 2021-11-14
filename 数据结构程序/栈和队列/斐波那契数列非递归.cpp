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
long long int fab(int n)
{
	long long int a = 1;long long int b = 1;
	long long int c;
	// cout<<a<<" "<<b<<" ";
	for (int i = 3; i <= n; i++)
	{
		c = a + b;
		a = b; b = c;
		// cout<<c<<" ";
	}
	// cout<<endl;
	return c;
}
BigInt fab2(int n)
{
	BigInt a(1);
	BigInt b(1);
	BigInt c;
	for (int i = 3; i <=n; i++)
	{
		c = a + b;
		
		a = b; b = c;
	}
	return c;
}
int main()
{
	int n;
	cout<<"������һ������"<<endl;
	cin>>n;
	clock_t start,end;
	start=clock();
	cout<<"��"<<n<<"��쳲���������Ϊ(��):"<<fab(n)<<endl;
	end=clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;//CLK_TCK�����ͬ
	cout<<"��"<<n<<"��쳲���������Ϊ(��):"<<fab2(n)<<endl;
	
}