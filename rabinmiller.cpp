#include <iostream>
#include <algorithm>
#include <math>

#define big unsigned long long

bool is_prime_prob(big, int);
bool check(big,big,big,big);

int main()
{
	bool Test = is_prime_prob(1001,10);
}


bool check(big a, big s, big d, big n)
{
	x = pow(a, d, n);
	if(x == 1)
		return true;
	for(big i = 0; i < s - 1; i++){
		if(x == n - 1)
			return true;
		x = pow(x, 2, n)
	}
	return x == n - 1
}

bool is_prime_prob(big n, int k)
{
	if(n==2)
		return true;
	if(n%2!=0)
		return false;

	s = 0;
	d = n - 1;

	while(d % 2 == 0){
		d >>= 1
		s += 1
	}

	for(big i = 0; i < k; i++){
		a = random(2, n - 1);
		if(! check(a, s, d, n))
			return false;
	}
	return true;
}
