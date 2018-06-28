#include "pid.h"

int main()
{
	double startTime, currentPV;
	double objective = 1.2;
	//Inicializa PID
	initPID();
	//Inicializa amostras
	initSamples();
	//"Coleta" amostras
	monitorBump(&startTime, &currentPV);
	
	//Limpa amostras
	cleanSamples();

	//Realiza um bumpTest
	bumpTest(objective);

	//Realiza uma bumplessTransfer
	bumplessTransfer();

	return 0;
}
