#include "pid.h"

lista* amostras;
pid_struct* PID_struct;

void initPID()
{
	PID_struct = (pid_struct*) malloc(sizeof(pid_struct));
}

void initSamples()
{
	amostras = (lista*) malloc(sizeof(lista));
}

void cleanSamples()
{
	free(amostras);
	amostras = (lista*) malloc(sizeof(amostras));
}

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

	if(PID_struct == NULL)
		initPID(PID_struct);
	if(amostras == NULL)
		initSamples(amostras);

	//O controlador envia um sinal na amplitude do objetivo

	//O controlador monitora valores de PV (armazenando num array?) até que fique estável
	//--Ou seja, até que PV[x] - PV[x-1] < epsilon
	//Essa função também retorna valor de início de resposta
	monitorBump(&startTime, &currentPV);
		
	//Calcula o ganho do processo com base na variação de PV e CO
	PID_struct->Kp = (currentPV - PID_struct->PV) / (currentCO - PID_struct->CO);

	//Calcula a constante de tempo do processo, com base na variação de PV
	currentPV = PID_struct->PV - 0.63 * (currentPV - PID_struct->PV);

	//Calcula o tempo correspondente a 63% (busca no array)
	middleTime = getTimeAt(currentPV);

	//Calcula variação entre início da resposta e os 63% (PT)
	PID_struct->Tp = middleTime - startTime;

	//Aproximação moderada
	PID_struct->Tc = PID_struct->Tp;
	//Aproximação agressiva
	//PID.Tc = 0.1 * PID.Tp;
	//Aproximação conservadora
	//PID.Tc = 10 * PID.Tp;

	//Calcula Kc
	PID_struct->Kc = ((PID_struct->Tp + 0.5 * PID_struct->Thetap) / (PID_struct->Tc + 0.5 * PID_struct->Thetap)) * (1 / PID_struct->Kp);

	//Calcula Ti
	PID_struct->Ti = PID_struct->Tp + 0.5 * PID_struct->Thetap;

	//Calcula Td
	PID_struct->Td = (PID_struct->Tp * PID_struct->Thetap) / (2 * PID_struct->Tp + PID_struct->Thetap);
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
