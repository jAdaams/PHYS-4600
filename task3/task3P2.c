#include <stdlib.h>	
#include <stdio.h>	
#include <math.h> 

int main()

{

	FILE* input_File;
	//FILE* output_File;
	int arrar = 50;
	float x[arrar]; 
	float y[arrar]; 
	float sum = 0;
	float var = 0; 
	float std_dev = 0;
	float mean = 0;

	input_File = fopen("task3.dat","r");
	
	if(input_File != NULL)
	{

		for(int i = 0; i < arrar; i++)
		{

			fscanf(input_File,"%f %f",&x[i],&y[i]);
			sum = y[i]++;
		}

		mean = sum / arrar;
		var = sum/(arrar-1); 
    	std_dev = sqrt(var);

		printf("Mean: %f\n",mean);
		printf("Standard Deviation %f\n",std_dev);
		printf("  X         Y\n");

		for(int i = 0; i < arrar; i++)
		{

			printf("\n%f %f",x[i],y[i]);
		}

		fclose(input_File);
	}

	else
	{
		printf("Ask James");
	}

	return 0;
}