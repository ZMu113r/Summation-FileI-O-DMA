#ifndef Lesson6practice_h
#define Lesson6practice_h
#endif

//Summation structure definition
typedef struct Summation {

	int sVal;
	int fVal;
	double intermediateProduct;
	int sum;
	char *thebigO;

} summation;

//Function declarations
summation *problemOne(int i, int n);
summation *problemTwo(int i, int n);
summation *problemThree(int i, int n);
summation *problemFour(int i, int n);
summation *problemFive(int i, int n);
summation *problemSix(int i, int n);
void printResults(summation *resultOne, summation *resultTwo, summation *resultThree, summation *resultFour, summation *resultFive, summation *resultSix);


