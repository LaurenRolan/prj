#ifndef PID
#define PID

typedef struct lista_amostras
{
	double valor;
	double timestamp;
	struct lista_amostras *proximo;
}amostra_lista;

typedef struct pid_struct
{
	double error;		// Erro anterior na medida
	double integral;		// Acumuladora da integral
	double Kc;		// Parâmetro do produto
	double Ti;		// Parâmetro da integral
	double Td;		// Parâmetro da divisão
	double Tc;		// Cte de tempo do loop
	double CO;		// Output do controlador (pwm?)
	double COb;		// Bias do output
	double PV;		// Variável do processo (leitura do sensor)
	double Kp;		// Ganho do processo, usado no modelo
	double Tp;		// Cte de tempo do processo, usado no modelo
	double Thetap;		// Dead-time
}PID_struct;

amostra_lista amostras;
PID_struct PID;

void bumpTest(double objective);
void bumplessTransfer();
void monitorBump(double *startTime, double *currentPV);
double getTimeAt(double currentPV);
#endif
