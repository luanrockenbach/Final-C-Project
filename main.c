/*Created by Luan Rockenbach, Maicon Dickow*/

#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#include<conio.h>

int main()
{
	FILE *archive;
	archive = fopen("calculations.txt","w");
	if(archive==NULL)
	{
		printf("\n\n\n -- ERRO, TENTE NOVAMENTE");
		exit(1);
	}
	
	float resistence, rms, frequence, simulationTime=1, peakVoltage, rmsCurrent, peakCurrent, controll = 0;
	float radius[3] = {0, -2.0944, 2.0944};
	
	//Inputs setup
	printf("\n\n -Digite o valor das resistencias: ");
	scanf("%f", &resistence);

	printf("\n\n -Digite o valor da Tensao Eficaz (RMS): ");
	scanf("%f", &rms);

	printf("\n\n -Digite a frequencia: ");
	scanf("%f", &frequence);

	printf("\n\n -Digite o Tempo de simulacao em segundos(S): ");
	scanf("%f", &simulationTime);
	//End of inputs
	
	peakVoltage = rms * sqrt(2);
	rmsCurrent = rms/resistence;
	peakCurrent = rmsCurrent*sqrt(2);
	
	printf("pV: %f				pC: %f				rmsC: %f", peakVoltage, peakCurrent, rmsCurrent);
	
	fprintf(archive, "time  I1  I2  I3  V1  V2  V3");
	while(controll <= simulationTime)
	{
		
		fprintf(archive, "\n%f  %f  %f  %f  %f  %f  %f", controll, 
		peakCurrent*sin((((2*3.14159265359)*frequence)*controll)+radius[0]), 
		peakCurrent*sin((((2*3.14159265359)*frequence)*controll)+radius[1]), 
		peakCurrent*sin((((2*3.14159265359)*frequence)*controll)+radius[2]), 
		peakVoltage*sin((((2*3.14159265359)*frequence)*controll)+radius[0]), 
		peakVoltage*sin((((2*3.14159265359)*frequence)*controll)+radius[1]), 
		peakVoltage*sin((((2*3.14159265359)*frequence)*controll)+radius[2]));
		
		controll += ((1/frequence)/360)/10;
	}

	return 0;
}