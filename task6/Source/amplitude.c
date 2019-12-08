#include <stdlib.h>	
#include <stdio.h>	
#include <math.h>
#include "amplitude.h"  
#include <float.h>

float ampli(float* waveData, int length)
{

	float maxValue=-FLT_MAX;
	float minValue=FLT_MAX;
	float *count=0;
	int location;
	float amp;
	
	int i = 0;
	

	/*for(i=0; i<length;i++)
	{
		len = len + waveData[i];
	}

	//while(length[i]!=NULL)
	//{
	//	i++;
	//}

	for(int i = 5; i < len; i++)
	{
	
	}*/

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

		/*if(minValue>count[i])
		{
			minValue = count[i];
			location = i;
			printf("Min Value %i",minValue);
		}

		else if(maxValue<count[i])
		{
			maxValue = count[i];
			location = i;
		}*/
	}

	//printf("\nThe Max Value is %f",maxValue);
	//printf("\nThe min value is %f",minValue);
	amp = ((maxValue-minValue)/2);
	//amp = fabs((maxValue-minValue)/2);
	return amp;

}