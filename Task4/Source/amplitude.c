#include <stdlib.h>	
#include <stdio.h>	
#include <math.h>
#include "amplitude.h"  
#include <float.h>

float ampli(float* waveData, int length)
{

	float maxValue=-FLT_MAX;
	float minValue=FLT_MAX;
	float amp;
	int i = 0;
	
	//Determine the maximum and minimum values of the sine wave
	for(int i = 0; i<length; i++)
	{

		if(waveData[i]>maxValue)
		{
			maxValue = waveData[i];
		}
		if(waveData[i]<minValue)
		{
			minValue = waveData[i];
		}

	}

	//calculate the amplitude of the sine wave
	amp = ((maxValue-minValue)/2);
	return amp;

}