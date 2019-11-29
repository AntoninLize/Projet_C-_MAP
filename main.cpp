#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "math.h"
using namespace std;

ifstream Flux("Donnees.txt");  //Ouverture d'un fichier en lecture

void GPS_to_XY(float &lx, float &ly)
{
    double r_0 = 6371000;
    double lx_0 = 48.29762887;
    double ly_0 = -004.41737340;

    lx = r_0*cos(ly)*(lx-lx_0);
    ly = r_0*(ly-ly_0);
}

int main()
{

    vector<float> X;
    vector<float> Y;
    vector<float> Z;

    while(Flux)

    {

        float lx, ly, lz;
        Flux >> lx;
        Flux >> ly;
        GPS_to_XY(lx,ly);
        X.push_back(lx);
        Y.push_back(ly);
        Flux >> lz;
        Z.push_back(lz);
        
    }
    cout << setprecision(10)<<X[10] << endl;
}

