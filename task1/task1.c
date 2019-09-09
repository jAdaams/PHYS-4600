#include <stdlib.h>	
#include <stdio.h>	
#include <math.h>	

int main()
{
	float data [] ={0.068038, 0.173967, 0.439303, 0.615258, 0.789436, 0.770980, 0.890924, 1.034431, 0.955555, 0.991579, 0.919359, 0.857244, 0.680064, 0.558250, 0.473129, 0.278329, 0.027142, -0.151631, -0.454363, -0.534177, -0.803847, -0.882892, -0.996433, -0.919950, -1.068664, -1.000596, -0.997921, -0.909708, -0.607322, -0.611919, -0.380097, -0.127268};

	float mean;
	float std_dev;
	float totSum=0;
	float totSum2=0;
	int i;
	float variance; 
	int elements=0;

	elements = sizeof(data)/sizeof(data[0]);

	printf("The size of the array is %d", elements);


	/*	Here you can put the code to find the standard deviation of the data array	*/



	//printf("Entries %i", arrayLength);
	
	for(i = 0; i<elements; i++)
		{
		totSum = totSum + data[i];
		
		}
		//return totSum;

		mean = totSum/elements;

		for(i=0; i<elements;i++)
		{
			totSum2 = totSum2 + pow((data[i]-mean),2);
		}
	
		variance = totSum2/elements; 
		std_dev = sqrt(variance);

	


	/* These lines will output the results to console */

	printf(" The total Sum is %f", totSum, ",");
	printf(" The mean value is: %f", mean, ",");
	printf(" The standard deviation is: %f", std_dev);
	//printf("\nMean = %f", mean);
	//printf("\nStandard deviation = %f", std_dev);

	
	return 0;  // Functions which return a value MUST contain at least one return statement
}
