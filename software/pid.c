#include <stdlib.h>
#include <time.h>

extern PID_struct PID;
extern amostra_lista amostras;

void bumplessTransfer()
{
	//COb = CO
	
	//SP = PV

	return;
}

void bumpTest(double objective)
{
	double currentPV = 0;
	double currentCO = 0;
	double startTime, middleTime;

	//O controlador envia um sinal na amplitude do objetivo

	//O controlador monitora valores de PV (armazenando num array?) até que fique estável
	//--Ou seja, até que PV[x] - PV[x-1] < epsilon
	//Essa função também retorna valor de início de resposta
	monitorBump(&startTime, &currentPV);
		
	//Calcula o ganho do processo com base na variação de PV e CO
	PID.Kp = (currentPV - PID.PV) / (currentCO - PID.CO);

	//Calcula a constante de tempo do processo, com base na variação de PV
	currentPV = PID.PV - 0.63 * (currentPV - PID.PV);

	//Calcula o tempo correspondente a 63% (busca no array)
	middleTime = getTimeAt(currentPV);

	//Calcula variação entre início da resposta e os 63% (PT)
	PID.Tp = middleTime - startTime;

	//Aproximação moderada
	PID.Tc = PID.Tp;
	//Aproximação agressiva
	//PID.Tc = 0.1 * PID.Tp;
	//Aproximação conservadora
	//PID.Tc = 10 * PID.Tp;

	//Calcula Kc
	PID.Kc = ((PID.Tp + 0.5 * PID.Thetap) / (PID.Tc + 0.5 * PID.Thetap)) * (1 / PID.Kp);

	//Calcula Ti
	PID.Ti = PID.Tp + 0.5 * PID.Thetap;

	//Calcula Td
	PID.Td = (PID.Tp * PID.Thetap) / (2 * PID.Tp + PID.Thetap);
}


void monitorBump(double *startTime, double *currentPV)
{
	double startMonitoring = 0; //Tempo do início do monitoramento
	//Verifica leituras do sensor do instante atual até que
	//ele se estabilize
	*startTime = 0;
	*currentPV = 0;
}	

double getTimeAt(double currentPV)
{
	//Lê o array de PVs e encontra instante da leitura mais
	//próxima do valor calculado (currentPV)
	return 0;	
}
