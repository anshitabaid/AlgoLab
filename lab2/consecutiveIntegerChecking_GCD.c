#include <stdio.h>
#include <stdlib.h>

int min(int m, int n) {
	return (m > n) ? n : m;
}

int gcd(int m, int n) {
	int t = min(m, n);
	while ((m % t != 0 || n % t != 0) && (t > 0)) {
		t--;
	}
	return t;
}

int main() {

	int m, n;

	printf("Enter m and n:\t");
	scanf("%d %d", &m, &n);

	printf("GCD of %d and %d is: %d\n", m, n, gcd(m, n));

}