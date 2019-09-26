#include <stdlib.h>	
#include <stdio.h>	
#include <math.h> 

int main()
{


	FILE * output_File;
	int data = 50; 
	float x[data]; 
	float y[data]; 
	float processData = M_PI;


	output_File = fopen("task3.dat","w");

	if(output_File == NULL)
	{
		fscanf(output_File,"%f %f",&x,&y);

		fclose(output_File);

	}

	else //if(output_File != NULL)
	{
		for(int i = 0; i < data; i++)
		{	
			x[i] = ((i*processData)/2); 
			y[i] = sin((i*processData)/2);
		}

		for(int i = 0; i < data; i++)
		{
			fprintf(output_File, "\n%f %f", x[i], y[i]);
		}
		fclose(output_File);

	}
	
	

	return 0;

}