#include <stdio.h>
#include <stdlib.h>

double two_d_random(int n)
{
	int len = 1;
	for (int i = 1; i < n; i++) len += 2;
	
	int coords[129][129] = {0};

	int x = (len/2), y = (len/2);
	while (x > -1 && x < len && y > -1 && y < len) {
		coords[x][y] = 1;
		int r = rand() % 4;
		if (r == 0) y += 1;
		else if (r == 1) x += 1;
		else if (r == 2) y -= 1;
		else if (r == 3) x -= 1;
	}

	double ans = 0.0;
	for (int i = 0; i <= len; i++)
		for (int j = 0; j <= len; j++)
			if (coords[i][j] == 1) ans += 1;

	return ans / (len * len);
}

int main(int argc, char *argv[])
{
	int trials = 1000;
	int i, n, seed;
	if (argc == 2) seed = atoi(argv[1]);
	else seed = 12345;

	srand(seed);
	for(n=1; n<=64; n*=2)
	{	
		double sum = 0.;
		for(i=0; i < trials; i++)
		{
			double p = two_d_random(n);
			sum += p;
		}
		printf("%d %.3lf\n", n, sum/trials);
	}
	return 0;
}
