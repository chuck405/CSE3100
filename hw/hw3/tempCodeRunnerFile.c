#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

void one_particle(int *grid, int n)
{
    int len = 2*n + 1;
    int x = n, y = n, z = n;
    for (int i = 0; i <= n; i++) {
        int r = rand() % 6;
        if (r == 0) x -= 1;
        else if (r == 1) x += 1;
        else if (r == 2) y += 1;
        else if (r == 3) y -= 1;
        else if (r == 4) z += 1;
        else if (r == 5) z -= 1;
    }
    int index = x + len * (y + len * z);
    grid[index] += 1;
}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int *grid, int n, double r)
{
    int len = 2*n + 1;
    double particles = 0.0, total = 0.0;
    int x, y, z, i;
    for (i = 0; i <= (len*len*len); i++) {
        x = i % len;
        z = i / (len * len);
        y = (i - z * len * len) / len;
        if ((double)(r*n*r*n) >= (double)((n-x)*(n-x) + (n-y)*(n-y) + (n-z)*(n-z))) particles += grid[i];
        total += grid[i];
    }
    return particles / total;
}

//use this function to print results
void print_result(int *grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
	//fill in a few line of code below
    int grid_len = (2*n+1)*(2*n+1)*(2*n+1);
    int* grid = (int*)malloc(grid_len * sizeof(int));
	for(int i = 1; i<=m; i++) one_particle(grid, n);

	print_result(grid, n);
	//fill in some code below
    free(grid);
}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}