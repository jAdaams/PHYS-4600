#include <stdlib.h>	
#include <stdio.h>	
#include <math.h>  
//#include <smooth.h>
#include <amplitude.h>

void main(int argc, char** argv)
{

	FILE* sin_File;
	int length = 500; 
	float x[length]; 
	float y[length]; 
	float sum = 0; 
	float rNoise = 0;
	//float processData = M_PI;

	sin_File = fopen("task4.dat","r"); //open the file containing the sine wave data 

	if(sin_File == NULL)
	{
		fscanf(sin_File,"%f %f",&x,&y);
		fclose(sin_File);
		printf("You suck");

	}
	else if(sin_File != NULL)
	{
		for(int i = 0; i < length; i++)
		{

			fscanf(sin_File,"%f %f",&x[i],&y[i]);
			sum = y[i]++;
		}
		//smooth(data, rNoise);
		float amp = ampli(y,500);
		for(int i = 0; i < length; i++)
		{

			printf("\nUnfiltered wave: %f %f",x[i],y[i]);
		}

		printf("The Amplitude is %f",amp);
	}

}