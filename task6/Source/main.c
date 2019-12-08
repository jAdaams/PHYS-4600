#include <stdlib.h>	
#include <stdio.h>	
#include <math.h>  
#include <visa.h>
//#include <iviVisaType.h>

void main(int argc, char** argv)
{

	char inq[] = "*IDN?/n";
	int y;
	unsigned char resultBuffer[256];
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
	char message[1024];
	float f;


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

				viWrite(scopeHandle, "CH1:SCA?\n",7, &resultCount);
				viRead(scopeHandle, resultVoltage, 2500, &resultCount);

				viWrite(scopeHandle, "DAT:SOU CH1\n",11,&resultCount);

				printf("\nResult Count = %d",resultCount);
				printf("\nResult Buffer = %s\n",resultBuffer);

				//viWrite(scopeHandle, "DAT:STOP\n",400,&resultCount);
				viWrite(scopeHandle, "CURV?\n",6,&resultCount);
				viRead(scopeHandle,dataBuffer,2500,&resultCount);

				viWrite(scopeHandle, "CH1:SCA?\n",7, &resultCount);
				viRead(scopeHandle, resultVoltage, 2500, &resultCount);

				char ret[36];

				sscanf(ret, " %f\n", resultVoltage);

				for(int i=0; i<200; i++)
				{
					y = dataBuffer[i];
					f = resultVoltage[i];
					printf("Reading: %i\n",i);
					printf("\nRaw = %x\nRead = %d\n",y,y);
					printf("Voltage = %f\n",f);
					printf("\n");
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

	
}