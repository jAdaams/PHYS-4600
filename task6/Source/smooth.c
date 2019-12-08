#include <stdlib.h>	
#include <stdio.h>	
#include <math.h> 
#include <smooth.h>


float smooth(float* waveData, float* smoothData, int length)
{
	float movAvg=0;
	int avgPoints = 11;
	float trans[length];
	int i = 0; 
	int x = 0;
	

	//For loop which ommits the first and last 11 data points
	for(int i = 0; i < (length-(10)); i++) 
	{
		movAvg = 0;

		for(int x = i; x < (i+10); x++)
		{
			movAvg = movAvg + (waveData[x]); //moving average with 9 data points 
		}

		trans[x]=movAvg; 
		printf("\n%f", movAvg);
		smoothData[x] = trans[x]/avgPoints; 
		
	}

}


