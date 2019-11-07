#include <stdlib.h>	
#include <stdio.h>	
#include <math.h>  
#include <visa.h>
#include <amplitude.h>
#include <smooth.h>
//#include <iviVisaType.h>

void main(int argc, char** argv)
{

	char inq[] = "*IDN?/n";
	int y;
	char resultBuffer[256];
	char resultVoltage[2500];
	ViUInt32 resultCount;
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	//unsigned int num_inst;
	ViUInt32 num_inst;
	ViUInt32 returnCount = 0;
	ViSession defaultRM, scopeHandle;
	ViChar description[VI_FIND_BUFLEN];
	char dataBuffer[2500];
	char idnResponse[1024];
	float amp;
	float newAmp;
	float smoothWave[2500];
	char message[1024];
	float volts_ADC,volts;
	float f[2500];


	status = viOpenDefaultRM(&defaultRM);
	printf("Opening\n");

	if(status == VI_SUCCESS)
	{

		status = viFindRsrc(defaultRM, "USB[0-9]::0?*INSTR", &resourceList, &num_inst, description);

		if(status == VI_SUCCESS)
		{
			viOpen(defaultRM, description, VI_NULL, VI_NULL, &scopeHandle);

			if(status == VI_SUCCESS)
			{
				printf("Opened %s", description);
				viWrite(scopeHandle, "*IDN?\n",6,&resultCount);
				viRead(scopeHandle,resultBuffer,256,&resultCount);


				viWrite(scopeHandle, "DAT:SOU CH1\n",11,&resultCount);

				printf("\nResult Count = %d",resultCount);
				printf("\nResult Buffer = %s\n",resultBuffer);

				viWrite(scopeHandle, "CURV?\n",6,&resultCount);
				viRead(scopeHandle,dataBuffer,2500,&resultCount);

				viWrite(scopeHandle, "CH1:SCA?\n",9, &resultCount);
				viRead(scopeHandle, resultVoltage, 2500, &resultCount);

				//sscanf(resultVoltage, " %f",&volts);
				volts = atof(resultVoltage);

				volts_ADC = volts/(256/10);
				printf("%s Volts ADC %f  Volts %f",resultVoltage, volts_ADC, volts);

				for(int i=0; i<500; i++)
				{
					y = dataBuffer[i];
					f[i] = y*volts_ADC;
					//printf("Reading: %i  ",i);
					//printf("Raw = %x  Read = %d  ",y,y);
					//printf("Read = %d  ",y);
					printf("%f\n",f[i]);
				}
				
			}
			else
			{
				printf("Failed to open, ASK JAMES");
			}
		}
		else
		{
			printf("Did not find any thing, ASK JAMES");
		}

	}

	else
	{
		printf("Did not open default RM, ASK JAMES");
	}

	//calculate the amplitude of the wave from the amplitude function
	amp = ampli(f,500);
	printf("\nAmplitude from raw wave data: %f",amp);

	//apply the smoothing filter and calculate the amplitude of the smoothed wave
	smooth(f, smoothWave, 500);
	newAmp = ampli(smoothWave, 500);
	printf("\nAmplitude from smooth wave data: %f", newAmp);

}