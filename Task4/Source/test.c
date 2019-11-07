#include <stdlib.h>	
#include <stdio.h>	
#include <math.h>  
#include <smooth.h>
#include <amplitude.h>

void main(int argc, char** argv)
{

	FILE* sin_File;
	int length = 500; 
	float x[length]; 
	float y[length]; 
	float rNoise = 0;
	float amp;
	float newAmp;
	float smoothWave[500];
	float f[500];

	//open the file containing the sine wave data 
	sin_File = fopen("task4.dat","r"); 

	if(sin_File == NULL)
	{
		fscanf(sin_File,"%f %f",&x,&y);
		fclose(sin_File);
		printf("You suck");
	}

	else if(sin_File != NULL)
	{
		printf("File has been opened");

		//read the data from the text file and print it out
		for(int i = 0; i < length; i++)
		{
			fscanf(sin_File,"%f %f",&x[i],&y[i]);
			printf("\nUnfiltered Wave %f %f",x[i],y[i]);
		}

	}

	//calculate amplitude of wave function from amplitude function
	amp = ampli(y,500);
	printf("\nThe Amplitude from the unfiltered wave is: %f",amp);

	//apply the smoothing function to the wave and print out the smoothed wave
	smooth(y, smoothWave, 500);
	newAmp = ampli(smoothWave, 500);
	printf("\nAmplitude from smooth wave data is: %f", newAmp);
	printf("\nFile Closed");
}