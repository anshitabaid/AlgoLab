#include <stdio.h>
#include <stdlib.h>

int min(int m, int n) {
	return (m < n) ? m : n;
}

int asqrt(int m) {
	int root = m/2;
	while(m < root*root) {
		root--;
	}
	return root;
}

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

int* primeFactors(int a) {

	int i = 0;
	int count = 0;
	int * primeFactorsArray = (int*)malloc((asqrt(a))*sizeof(int));

	printf("Finding prime factors for %d\n", a);

	while(primes[i] <= a) {
		while(a % primes[i] == 0) {
			*(primeFactorsArray + count++) = primes[i];
			a /= primes[i];
		}
		i++;
	}

	return primeFactorsArray;

}

int gcd(int m, int n) {

	int * primeFactorsOfM = primeFactors(m);
	int * primeFactorsOfN = primeFactors(n);

	int * commonPrimes = (int*)malloc((min(m,n))*sizeof(int));
	int count = 0;

	while(primeFactorsOfM != NULL && primeFactorsOfN != NULL) {

		if (*primeFactorsOfN == 0 || *primeFactorsOfM == 0) break;

		if (*primeFactorsOfM == *primeFactorsOfN) {
			*(commonPrimes + count++) = *primeFactorsOfM;
			primeFactorsOfM++;
			primeFactorsOfN++;
		}
		else if (*primeFactorsOfM > *primeFactorsOfN) {
			primeFactorsOfN++;
		}
		else {
			primeFactorsOfM++;
		}
	}

	int gcd = 1;
	for(int i = 0; i < count; i++) {
		if (*(commonPrimes + i) == NULL) 
			break;
		gcd *= *(commonPrimes + i);
	}

	return gcd;
}

int main() {
	int m, n;
	printf("Enter m and n:\t");
	scanf("%d %d", &m, &n);

	printf("GCD of %d and %d is: %d\n", m, n, gcd(m, n));
}