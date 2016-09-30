#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lesson6practice.h"

int main(int argc, char **argv) {

	//Get file name from command line
	char *fileName = argv[1];

	//pointers for values to get from array of values
	int *start = (int *)malloc(sizeof(int));
	int *end = (int *)malloc(sizeof(int));
	//Number of lines of inputs
	int numLines = 0;

	//open file...
	FILE *file = fopen(fileName, "r");

	//Defensive code...
	if(file == NULL) {

		printf("ERROR: file %s not found.\n", fileName);

	}

	//Find out how many lines of input parameters we have
	while(fscanf(file, "%d %d", start, end) != EOF) {

		numLines++;

	}
	//bring file pointer back to top of file
	rewind(file);

	int counter = 1;
	//Array to load scanned in input parameters in to for use by summation function calls
	int inputArray[numLines][2];
	//travers through array and load input parameters
	while(fscanf(file, "%d %d", start, end) != EOF) {

		inputArray[counter][0] = *start;
		inputArray[counter][1] = *end;

		counter++;

	}
	//reset counter to be used to load held parameters into function calls
	counter = 1;

	//close file...
	fclose(file);

	//returned summation structures
	summation *resultOne, *resultTwo, *resultThree, *resultFour, *resultFive, *resultSix;

	//Pointers to pass values from array to function calls
	int *i = (int *)malloc(sizeof(int));
	int *n = (int *)malloc(sizeof(int));

	//Pass in start and end (i and N) values for summations into function calls
	for(counter = 1; counter <= numLines; counter++) {

		switch(counter) {

			case 1:

				*i = inputArray[counter][0];
				*n = inputArray[counter][1];

				resultOne = problemOne(*i, *n);

				free(i);
				free(n);

				break;

			case 2:
				
				*i = inputArray[counter][0];
				*n = inputArray[counter][1];

				resultTwo =  problemTwo(*i, *n);

				free(i);
				free(n);

				break;

			case 3:

				*i = inputArray[counter][0];
				*n = inputArray[counter][1];

				resultThree = problemThree(*i, *n);

				free(i);
				free(n);

				break;

			case 4:
				
				*i = inputArray[counter][0];
				*n = inputArray[counter][1];

				resultFour = problemFour(*i, *n);

				free(i);
				free(n);

				break;

			case 5:

				*i = inputArray[counter][0];
				*n = inputArray[counter][1];

				resultFive = problemFive(*i, *n);

				free(i);
				free(n);
 
				break;

			case 6:
				
				*i = inputArray[counter][0];
				*n = inputArray[counter][1];

				resultSix = problemSix(*i, *n);
				
				free(i);
				free(n);
				
				break;

		}
	}

	//print them...
	printResults(resultOne, resultTwo, resultThree, resultFour, resultFive, resultSix);

	return 0;

}


summation *problemOne(int i, int n) {
	
	//create space in memory for struct and its elements
	summation *p1Sum = (summation *)malloc(sizeof(summation));
	int *sVal = (int *)malloc(sizeof(10 * sizeof(int)));
	int *fVal = (int *)malloc(sizeof(10 * sizeof(int)));
	double *intermediateProduct = (double *)malloc(sizeof(1000 * sizeof(double) + sizeof(double)));
	int *sumVal =  (int *)malloc(sizeof(10 * sizeof(int)));
	char *thebigO = (char *)malloc(10 * sizeof(char *));

	//sum output
	double sum = 0.0;
	//Big O counter
	int O = 0;

	//Fill p1Sum start and end values
	p1Sum -> sVal = i;
	p1Sum -> fVal = n;

	//Loop until you hit the end value
	for(i = 0; i <= n; i++) {

		//value of i as a double
		double dblI = (double)i;

		//Perform summation calculation for each i
		sum += (5.0 + (sqrt(pow(4.0, dblI))));

		double step = sum;

		//Put each step of calculations into double array in struct
		p1Sum[i].intermediateProduct = step;

	}

	//There's a one loop so increment time complexity counter by 1
	O++;

	//Determine O notation for summation
	switch(O) {

		case 0:

			strcpy(thebigO, "O(1) - Constant time");
			p1Sum -> thebigO = thebigO;

			break;

		case 1:

			strcpy(thebigO, "O(n) - Linear time");
			p1Sum -> thebigO = thebigO;
			
			break;

		case 2:

			strcpy(thebigO, "O(log n) - Logarithmic time");
			p1Sum -> thebigO = thebigO;

			break;

		case 3:

			strcpy(thebigO, "O(n log n) - Lineararithmic time");
			p1Sum -> thebigO = thebigO;

			break;

		case 4:

			strcpy(thebigO, "O(n ^ 2) - Quadratic time");
			p1Sum -> thebigO = thebigO;

			break;

		case 5:

			strcpy(thebigO, "O(n!) - Factorial time");
			p1Sum -> thebigO = thebigO;

			break;

	} 

	//cast sum to int type
	sum = (int)sum;

	//store sum
	p1Sum -> sum = sum;

	return p1Sum;

}

summation *problemTwo(int i, int n) {
	
	//create space in memory for struct and its elements
	summation *p2Sum = (summation *)malloc(sizeof(summation));
	int *sVal = (int *)malloc(sizeof(10 * sizeof(int)));
	int *fVal = (int *)malloc(sizeof(10 * sizeof(int)));
	double *intermediateProduct = (double *)malloc(sizeof(10 * sizeof(double)));
	int *sumVal =  (int *)malloc(sizeof(10 * sizeof(int)));
	char *thebigO = (char *)malloc(10 * sizeof(char *));

	//sum output
	double sum = 0.0;
	//Big O counter
	int O = 0;

	//Fill p1Sum start and end values
	p2Sum -> sVal = i;
	p2Sum -> fVal = n;

	//Loop until you hit the end value
	for(i = 1; i <= n; i++) {

		sum += 4.0 + (3.0 * (double) i );

		double step = sum;

		//Put each step of calculations into double array in struct
		//p2Sum[i].intermediateProduct = step;

	}

	//There's a one loop so increment time complexity counter by 1
	O++;

	switch(O) {

		case 0:

			strcpy(thebigO, "O(1) - Constant time");
			p2Sum -> thebigO = thebigO;

			break;

		case 1:

			strcpy(thebigO, "O(n) - Linear time");
			p2Sum -> thebigO = thebigO;

			break;

		case 2:

			strcpy(thebigO, "O(log n) - Logarithmic time");
			p2Sum -> thebigO = thebigO;

			break;

		case 3:

			strcpy(thebigO, "O(n log n) - Lineararithmic time");
			p2Sum -> thebigO = thebigO;

			break;

		case 4:

			strcpy(thebigO, "O(n ^ 2) - Quadratic time");
			p2Sum -> thebigO = thebigO;

			break;

		case 5:

			strcpy(thebigO, "O(n!) - Factorial time");
			p2Sum -> thebigO = thebigO;

			break;

	} 

	//cast sum to int type
	sum = (int)sum;

	//store sum
	p2Sum -> sum = sum;

	return p2Sum;

}

summation *problemThree(int i, int n) {

	//create space in memory for struct and its elements
	summation *p3Sum = (summation *)malloc(sizeof(summation));
	int *sVal = (int *)malloc(sizeof(10 * sizeof(int)));
	int *fVal = (int *)malloc(sizeof(10 * sizeof(int)));
	double *intermediateProduct = (double *)malloc(sizeof(10 * sizeof(double)));
	int *sumVal =  (int *)malloc(sizeof(10 * sizeof(int)));
	char *thebigO = (char *)malloc(10 * sizeof(char *));

	//sum output
	double sum = 0.0;
	//Big O counter
	int O = 0;

	//Fill p1Sum start and end values
	p3Sum -> sVal = i;
	p3Sum -> fVal = n;

	//Loop until you hit the end value
	for(i = 4; i <= n; i++) {

		sum += (double)i;

		double step = sum;
		//Put each step of calculations into double array in struct
		p3Sum[i].intermediateProduct = step;
	}

	//There's a one loop so increment time complexity counter by 1
	O++;

	switch(O) {

		case 0:

			strcpy(thebigO, "O(1) - Constant time");
			p3Sum -> thebigO = thebigO;

			break;

		case 1:

			strcpy(thebigO, "O(n) - Linear time");
			p3Sum -> thebigO = thebigO;

			break;

		case 2:

			strcpy(thebigO, "O(log n) - Logarithmic time");
			p3Sum -> thebigO = thebigO;

			break;

		case 3:

			strcpy(thebigO, "O(n log n) - Lineararithmic time");
			p3Sum -> thebigO = thebigO;

			break;

		case 4:

			strcpy(thebigO, "O(n ^ 2) - Quadratic time");
			p3Sum -> thebigO = thebigO;

			break;

		case 5:

			strcpy(thebigO, "O(n!) - Factorial time");
			p3Sum -> thebigO = thebigO;

			break;

	} 

	//cast sum to int type
	sum = (int)sum;

	//store sum
	p3Sum -> sum = sum;

	return p3Sum;
	
}

summation *problemFour(int i, int n) {

	//create space in memory for struct and its elements
	summation *p4Sum = (summation *)malloc(sizeof(summation));
	int *sVal = (int *)malloc(sizeof(10 * sizeof(int)));
	int *fVal = (int *)malloc(sizeof(10 * sizeof(int)));
	double *intermediateProduct = (double *)malloc(sizeof(10 * sizeof(double)));
	int *sumVal =  (int *)malloc(sizeof(10 * sizeof(int)));
	char *thebigO = (char *)malloc(10 * sizeof(char *));

	//sum output
	double sum = 0.0;
	//Big O counter
	int O = 0;

	//Fill p1Sum start and end values
	p4Sum -> sVal = i;
	p4Sum -> fVal = n;

	//Loop until you hit the end value
	for(i = 0; i <= n; i++) {

		sum += (double)(4.0 * i) + 1.0;

		double step = sum;
		//Put each step of calculations into double array in struct
		p4Sum[i].intermediateProduct = step;
	}

	//There's a one loop so increment time complexity counter by 1
	O++;

	switch(O) {

		case 0:

			strcpy(thebigO, "O(1) - Constant time");
			p4Sum -> thebigO = thebigO;

			break;

		case 1:

			strcpy(thebigO, "O(n) - Linear time");
			p4Sum -> thebigO = thebigO;

			break;

		case 2:

			strcpy(thebigO, "O(log n) - Logarithmic time");
			p4Sum -> thebigO = thebigO;

			break;

		case 3:

			strcpy(thebigO, "O(n log n) - Lineararithmic time");
			p4Sum -> thebigO = thebigO;

			break;

		case 4:

			strcpy(thebigO, "O(n ^ 2) - Quadratic time");
			p4Sum -> thebigO = thebigO;

			break;

		case 5:

			strcpy(thebigO, "O(n!) - Factorial time");
			p4Sum -> thebigO = thebigO;

			break;

	} 

	//cast sum to int type
	sum = (int)sum;

	//store sum
	p4Sum -> sum = sum;

	return p4Sum;
	
}

summation *problemFive(int i, int n) {

	//create space in memory for struct and its elements
	summation *p5Sum = (summation *)malloc(sizeof(summation));
	int *sVal = (int *)malloc(sizeof(10 * sizeof(int)));
	int *fVal = (int *)malloc(sizeof(10 * sizeof(int)));
	double *intermediateProduct = (double *)malloc(sizeof(10 * sizeof(double)));
	int *sumVal =  (int *)malloc(sizeof(10 * sizeof(int)));
	char *thebigO = (char *)malloc(10 * sizeof(char *));

	//sum output
	double sum = 0.0;
	//Big O counter
	int O = 0;

	//Fill p1Sum start and end values
	p5Sum -> sVal = i;
	p5Sum -> fVal = n;

	//Loop until you hit the end value
	for(i = 3; i <= n; i++) {

		sum += (double)(pow(i, 2)) + 2.0;

		double step = sum;
		//Put each step of calculations into double array in struct
		p5Sum[i].intermediateProduct = step;

	}
	
	//There's a one loop so increment time complexity counter by 1
	O++;

	switch(O) {

		case 0:

			strcpy(thebigO, "O(1) - Constant time");
			p5Sum -> thebigO = thebigO;

			break;

		case 1:

			strcpy(thebigO, "O(n) - Linear time");
			p5Sum -> thebigO = thebigO;

			break;

		case 2:

			strcpy(thebigO, "O(log n) - Logarithmic time");
			p5Sum -> thebigO = thebigO;

			break;

		case 3:

			strcpy(thebigO, "O(n log n) - Lineararithmic time");
			p5Sum -> thebigO = thebigO;

			break;

		case 4:

			strcpy(thebigO, "O(n ^ 2) - Quadratic time");
			p5Sum -> thebigO = thebigO;

			break;

		case 5:

			strcpy(thebigO, "O(n!) - Factorial time");
			p5Sum -> thebigO = thebigO;

			break;

	} 

	//cast sum to int type
	sum = (int)sum;

	//store sum
	p5Sum -> sum = sum;

	return p5Sum;
}

summation *problemSix(int i, int n) {

	//create space in memory for struct and its elements
	summation *p6Sum = (summation *)malloc(sizeof(summation));
	int *sVal = (int *)malloc(sizeof(10 * sizeof(int)));
	int *fVal = (int *)malloc(sizeof(10 * sizeof(int)));
	double *intermediateProduct = (double *)malloc(sizeof(10 * sizeof(double)));
	int *sumVal =  (int *)malloc(sizeof(10 * sizeof(int)));
	char *thebigO = (char *)malloc(10 * sizeof(char *));

	//sum output
	double sum = 0.0;
	double dblI;
	//Big O counter
	int O = 0;

	//Fill p1Sum start and end values
	p6Sum -> sVal = i;
	p6Sum -> fVal = n;

	//Loop until you hit the end value
	for(i = 0; i <= n; i++) {

		dblI = (double)i;

		sum += (3.0 * (dblI * dblI)) + (pow(4.0, dblI) / 2.0);

		double step = sum;
		//Put each step of calculations into double array in struct
		p6Sum[i].intermediateProduct = step;

	}

	//There's a one loop so increment time complexity counter by 1
	O++;

	switch(O) {

		case 0:

			strcpy(thebigO, "O(1) - Constant time");
			p6Sum -> thebigO = thebigO;

			break;

		case 1:

			strcpy(thebigO, "O(n) - Linear time");
			p6Sum -> thebigO = thebigO;

			break;

		case 2:

			strcpy(thebigO, "O(log n) - Logarithmic time");
			p6Sum -> thebigO = thebigO;

			break;

		case 3:

			strcpy(thebigO, "O(n log n) - Lineararithmic time");
			p6Sum -> thebigO = thebigO;

			break;

		case 4:

			strcpy(thebigO, "O(n ^ 2) - Quadratic time");
			p6Sum -> thebigO = thebigO;

			break;

		case 5:

			strcpy(thebigO, "O(n!) - Factorial time");
			p6Sum -> thebigO = thebigO;

			break;

	} 

	//cast sum to int type
	sum = (int)sum;

	//store sum
	p6Sum -> sum = sum;

	return p6Sum;
}

void printResults(summation *resultOne, summation *resultTwo, summation *resultThree, summation *resultFour, summation *resultFive, summation *resultSix) {
	
	int resultNumber;

	for(resultNumber = 1; resultNumber < 7; resultNumber++) { 

		switch(resultNumber) {

			case 1:

				printf("Summation %d:\n\tstart value = %d\n\tend value = %d\n", 
					resultNumber, resultOne->sVal, resultOne->fVal);

				printf("\tThe sum of problem %d is: %d\n\tThe time complexity for this Sum is: %s\n\n", 
					resultNumber, resultOne -> sum, resultOne -> thebigO);

				break;

			case 2:

				printf("Summation %d:\n\tstart value = %d\n\tend value = %d\n\t", 
					resultNumber, resultTwo->sVal, resultTwo->fVal);

				printf("The sum of problem %d is: %d\n\tThe time complexity for this Sum is: %s\n\n", 
					resultNumber, resultTwo -> sum, resultTwo -> thebigO);

				break;

			case 3:

				printf("Summation %d:\n\tstart value = %d\n\tend value = %d\n\t", 
					resultNumber, resultThree->sVal, resultThree->fVal);

				printf("The sum of problem %d is: %d\n\tThe time complexity for this Sum is: %s\n\n", 
					resultNumber, resultThree -> sum, resultThree -> thebigO);

				break;

			case 4:

				printf("Summation %d:\n\tstart value = %d\n\tend value = %d\n\t", 
					resultNumber, resultFour->sVal, resultFour->fVal);

				printf("The sum of problem %d is: %d\n\tThe time complexity for this Sum is: %s\n\n", 
					resultNumber, resultFour -> sum, resultFour -> thebigO);

				break;

			case 5:

				printf("Summation %d:\n\tstart value = %d\n\tend value = %d\n\t", 
					resultNumber, resultFive->sVal, resultFive->fVal);

				printf("The sum of problem %d is: %d\n\tThe time complexity for this Sum is: %s\n\n", 
					resultNumber, resultFive -> sum, resultFive -> thebigO);

				break;

			case 6:

				printf("Summation %d:\n\tstart value = %d\n\tend value = %d\n\t", 
					resultNumber, resultSix->sVal, resultSix->fVal);

				printf("The sum of problem %d is: %d\n\tThe time complexity for this Sum is: %s\n\n", 
					resultNumber, resultSix -> sum, resultSix -> thebigO);

				break;

		}
	}
}