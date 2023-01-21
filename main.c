#include<stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<math.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	float resistence, rms, frequence, simulationTime=1, peakVoltage, rmsCurrent, peakCurrent;
	float degree[3] = {0, -120, 120};
	
	//Inputs setup
	printf("\n\n -Digite o valor das resistências: ");
	scanf("%f", &resistence);

	printf("\n\n -Digite o valor da Tensão Eficaz (RMS): ");
	scanf("%f", &rms);

	printf("\n\n -Digite a frequência: ");
	scanf("%f", &frequence);

	printf("\n\n -Digite o Tempo de simulação em mili-segundos(ms): ");
	scanf("%f", &simulationTime);
	//End of inputs
	
	float resistenceCurrent[(int)simulationTime*100000], resistenceVoltage[(int)simulationTime*100000];
	
	peakVoltage = rms * sqrt(2);
	rmsCurrent = rms/resistence;
	peakCurrent = rmsCurrent*sqrt(2);
	
	printf("pV: %f				pC: %f				rmsC: %f", peakVoltage, peakCurrent, rmsCurrent);
	
	for(int j=0;j<simulationTime*100000;j++)
	{
	resistenceCurrent[j] = peakCurrent*sin(((2*3,14159265359)*frequence*j)+degree[2]);
	resistenceVoltage[j] = peakVoltage*sin(((2*3,14159265359)*frequence*j)+degree[2]);
	
	printf("\n\n -- Corrente de cada resistor: %f Tensão de cada resistor: %f", resistenceCurrent[j], resistenceVoltage[j]);
	}	
	return 0;
}