#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{
	int divisor = 1;
	while (n / divisor >= 10)
		divisor *= 10;

	while (n != 0)
	{
		int leading = n / divisor;
		int trailing = n % 10;

		// If first and last digit
		// not same return false
		if (leading != trailing)
			return false;

		// Removing the leading and trailing
		// digit from number
		n = (n % divisor) / 10;

		// Reducing divisor by a factor
		// of 2 as 2 digits are dropped
		divisor = divisor / 100;
	}
	return true;
}

int main()
{
	isPalindrome(1002) ? cout << "Yes, it is Palindrome" :
	cout << "No, not Palindrome";
	return 0;
}
 
