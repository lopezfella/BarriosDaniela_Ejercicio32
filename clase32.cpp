#include <iostream>
#include <fstream>
#include <cmath>
/* Basado en el repositorio del profesor */

using namespace std;

int main(){
    double L = 1.0;
    double T = 40.0;
    double rho = 0.01;
    double C=sqrt(T/rho);  
    double t_max = 0.1;
    double dt = 0.01;
    double t;
    double razon;
    double dx = 10/100;
    int N = L/(dx) + 1;
    double viejo[N][3];
    double nuevo[N][3];
    int i;
    
    ofstream outfile;
    

    for(i=0;i<N;i++){
        viejo[i][0] = (1*10^(-4))*sin(i*((2*M_PI)/L));
    }
    nuevo[0][0] = 0.0;
    nuevo[N-1][0] = 0.0;

    razon = (dx/dt);
    cout << razon << endl;


    outfile.open("datos.dat");
    while(t < t_max){
        for(i=1;i<N-1;i++){
            nuevo[i][0] = viejo[i][0] + razon * (viejo[i+1][0]+viejo[i-1][0]-2.0*viejo[i][0]);
            nuevo[i][1] = 2.0 * viejo[i][1] - viejo[i][0] + razon * (viejo[i+1][0]+viejo[i-1][0]-2.0*viejo[i][0]);
        }
        for(i=0;i<N;i++){
        outfile << nuevo[i][0] << " " << nuevo[i][1]; 
        }
        outfile << "\n";
        for(i=1;i<N-1;i++){
            viejo[i][0] = nuevo[i][0];
            viejo[i][1] = nuevo[i][1];
        }
        t = t + dt;
    }
    outfile.close();
    return 0;
}
