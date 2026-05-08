#include <iostream>

int defaultparm(int a, int b, int c, int d, int e, int f = 10, int g = 11) {
	return (a + b + c + d + e + f + g) / 7;
}

int main() {
	int a = defaultparm(1, 2, 3, 4, 5);
	int b = defaultparm(1, 2, 3, 4, 5, 6, 7);
	return 0;
}