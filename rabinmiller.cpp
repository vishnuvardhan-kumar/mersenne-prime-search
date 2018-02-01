#include <iostream>
#include <algorithm>
#include <math>
#include <random>

#define big unsigned long long

bool is_prime_prob(big, int);
bool check(big,big,big,big);
bool unittest(int);

int main()
{
	bool result = unittest(100);
	if(result)
		cout << "Tests sucessful.";
	else
		cout << "Tests failed";
}

bool unittest(int n)
{
	std::random_device rd;     
	std::mt19937 rng(rd());    
	std::uniform_int_distribution<int> uni(min,max); 

	for(int k=0;k<n;k++)
	{
		auto random_integer = uni(rng);
		bool result = check(random_integer);
	}
	return result;
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
