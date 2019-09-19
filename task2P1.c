#include <stdlib.h>	
#include <stdio.h>	
#include <math.h>	


float mean(float* data1,  int len)
{

	float entries = 0;
	float m=0;
	int i = 0; 

	for(i=0; i<len; i++)
	{
		entries = entries + data1[i];
	}

	m = entries/len;

	return m;
}


float stdD(float* data1, int len, int m)
{

	float sum=0; 
	float variance = 0;
	float std_dev = 0;
	int i = 0;

	for(i=0; i<len;i++)
		{
			sum = sum + pow((data1[i]-m),2);
		}

		variance = sum/len; 
		std_dev = sqrt(variance);

		return std_dev;

}


int main()
{
	float data [] ={0.068038, 0.173967, 0.439303, 0.615258, 0.789436, 0.770980, 0.890924, 1.034431, 0.955555, 0.991579, 0.919359, 0.857244, 0.680064, 0.558250, 0.473129, 0.278329, 0.027142, -0.151631, -0.454363, -0.534177, -0.803847, -0.882892, -0.996433, -0.919950, -1.068664, -1.000596, -0.997921, -0.909708, -0.607322, -0.611919, -0.380097, -0.127268};

	float avg=0;
	float std_D=0;

	avg = mean(data, 32);
	std_D = stdD(data, 32, avg);

	printf("The mean is %f\n", avg);
	printf("The standard deviation is: %f\n", std_D);

	return 0; 

	}


