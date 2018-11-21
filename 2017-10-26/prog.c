/* Filip Piorski */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int A=7, B=5;
	double t, dt;
	scanf("%lf%lf", &t, &dt);
	for (int i=0; i<10; ++i){
		printf("(x,y) = (%lf,%lf)\n", A*sin(t+i*dt)/(t+i*dt), B*cos(t+i*dt));
	}
	return 0;
}

