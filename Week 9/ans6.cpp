#include <set>
#include<cmath>
#include <cstdio>
using namespace std;

bool prime(int x)
{
	for (int i = 2; i <= sqrt(x); i ++)
	{

		if (x % i == 0)
			return false;
	}
	return true;
}

int getprimefactor(int a)
{
	int sum = 0;
	int k = 0;
	for (int i = 2; i <= sqrt(a); i ++)
	{
		if (a % i == 0)
		{
			k = a / i;
			if (prime(i))
			{
				sum++;
			}
			if (k != i && prime(k))
			{
				sum++;
			}
		}
	}
	return sum;
}


class primefactor
{
public:
	bool operator()( const int& a, const int& b)
	{
		int suma = 0;
		int sumb = 0;
		suma = getprimefactor( a );
		sumb = getprimefactor( b );
		if (suma == sumb)
		{
			if (a < b )
				return true;
			else
				return false;
		}
		else
			if (suma > sumb)
			{
				return false;
			}
		else
			return true;
	}
};



int main()
{
	set < int, primefactor > op;
	int n = 0;;
	scanf("%d", &n);
	while (n--)
	{
		int m;
		for (int i = 0; i < 10; i++)
        {
            scanf("%d", &m);
            op.insert(m);
        }
		int min = *(op.begin());
		int max = *(op.rbegin());
		op.erase(max);
		op.erase(min);
		printf("%d %d\n",max, min);
	}

	return 0;
}
