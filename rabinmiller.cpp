#include <iostream>
#include <algorithm>
#include <math>

bool is_prime_prob(int, int);
bool check(int,int,int,int);

int main()
{
	bool Test = is_prime_prob(1001,10);
}


bool check(int a, int s, int d, int n)
{
	x = pow(a, d, n);
	if(x == 1)
		return true;
	for(int i = 0; i < s - 1; i++){
		if(x == n - 1)
			return true;
		x = pow(x, 2, n)
	}
	return x == n - 1
}

bool is_prime_prob(int n, int k)
{
	if(n==2)
		return true;
	if(n%2!=0)
		return false;


}
