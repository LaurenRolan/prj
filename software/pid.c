#include <stdlib.h>
#include <time.h>

extern double error;		// Erro anterior na medida
extern double integral;		// Acumuladora da integral
extern double Kc;		// Parâmetro do produto
extern double Ti;		// Parâmetro da integral
extern double Td;		// Parâmetro da divisão
extern double Tc;		// Cte de tempo do loop
extern double CO;		// Output do controlador (pwm?)
extern double COb;		// Bias do output
extern double PV;		// Variável do processo (leitura do sensor)
extern double Kp;		// Ganho do processo, usado no modelo
extern double Tp;		// Cte de tempo do processo, usado no modelo
extern double Thetap;		// Dead-time

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
	Kp = (currentPV - PV) / (currentCO - CO);

	//Calcula a constante de tempo do processo, com base na variação de PV
	currentPV = PV - 0.63 * (currentPV - PV);

	//Calcula o tempo correspondente a 63% (busca no array)
	middleTime = getTimeAt(currentPV);

	//Calcula variação entre início da resposta e os 63% (PT)
	Tp = middleTime - startTime;

	//Aproximação moderada
	Tc = Tp;
	//Aproximação agressiva
	//Tc = 0.1 * Tp;
	//Aproximação conservadora
	//Tc = 10 * Tp;

	//Calcula Kc
	Kc = ((Tp + 0.5 * Thetap) / (Tc + 0.5 * Thetap)) * (1 / Kp);

	//Calcula Ti
	Ti = Tp + 0.5 * Thetap;

	//Calcula Td
	Td = (Tp * Thetap) / (2 * Tp + Thetap);
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
