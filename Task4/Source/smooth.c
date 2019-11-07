#include <stdlib.h>	
#include <stdio.h>	
#include <math.h> 
#include <smooth.h>


float smooth(float* waveData, float* smoothData, int length, int window)
{
	float movAvg=0;
	int avgPoints = 5;
	float trans[length];
	int i = 0; 
	int x = 0;
	

	for(int i = 0; i < (length-(window-1)); i++) //start after the 5th data point on the sin wave
	{
		movAvg = 0;

		for(int j = i; x < (i+window); x++)
		{
			movAvg = movAvg + (waveData[x]/avgPoints); //moving average with 9 data points 
		}

		trans[x]=movAvg; 
		printf("\ndata: %f", movAvg);
		smoothData[x] = trans[x]/window; 
		
	}

}


