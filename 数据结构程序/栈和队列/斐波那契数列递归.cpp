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
int fab1(int n)
{
	if (n == 1) return 1;
	if (n == 2) return 1;
	else return fab1(n - 1) + fab1(n - 2);
}
long long int f[MAX] = { 0,1,1 };
long long int fab3(int n)
{
	if (f[n] != 0) return f[n];
	if (n == 1) return 1;
	if (n == 2) return 1;
	return f[n] = fab3(n - 1) + fab3(n-2);
}
BigInt fb[MAX] = { BigInt(0),BigInt(1),BigInt(1) };
BigInt fab4(int n)
{
	if (fb[n].getdigit() != 0 &&n!=0) return fb[n];
	if (n == 1) return BigInt(1);
	if (n == 2) return BigInt(1);
	return fb[n] = fab4(n - 1) + fab4(n - 2);
}
int main()
{
	int n;
	
	cout<<"请输入一个整数"<<endl;
	cin>>n;
	clock_t start,end;
	// start=clock();
	// cout<<"第"<<n<<"项斐波那契数列为(非):"<<fab1(n)<<endl;
	// end=clock();
	// cout << (double)(end - start) / CLOCKS_PER_SEC << endl;//CLK_TCK与其等同
	start=clock();
	cout<<"第"<<n<<"项斐波那契数列为(非):"<<fab3(n)<<endl;
	end=clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;//CLK_TCK与其等同
	// cout<<"大数运算递归存在bug,22项之后结果便少一位"<<endl;
	// start=clock();
	// cout<<endl;
	// cout<<"第"<<n<<"项斐波那契数列为(大):"<<fab4(n)<<endl;
	// end=clock();
	// cout << (double)(end - start) / CLOCKS_PER_SEC << endl;//CLK_TCK与其等同
	
	
	
	
	
}