#include <iostream>
#include <algorithm>

bool is_prime_prob(int, int);
bool check(int,int,int,int);

int main()
{
	bool Test = is_prime_prob(1001,10);
}


bool is_prime_prob(int n, int k)
{
	if(n==2)
		return true;
	if(n%2!=0)
		return false;

}
