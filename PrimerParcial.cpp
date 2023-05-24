#include "PrimerParcial.h"
#include "ResumenDiario.h"
#include "ResumenDiarioArchivo.h"
#include "Fecha.h"


#include <iostream>
using namespace std;
void PrimerParcial::setVentaPorMes(float ventaPorMes)
{

    _ventaPorMes = ventaPorMes;

}

void PrimerParcial::ejercicio1() {
//El nombre del tipo de combustible que haya registrado el precio por litro más caro.
//Si existe más de un tipo de combustible que cumpla esta condición, mostrar el primero que encuentren en el archivo.

ResumenDiarioArchivo resumenArch;

float precioPorLitroMasCaro;
int largoDelArchivo = resumenArch.getCantidad();

precioPorLitroMasCaro = resumenArch.leer(0).getPrecioPorLitro();

for(int i = 0; i < largoDelArchivo; i++){

if (  precioPorLitroMasCaro < resumenArch.leer(i).getPrecioPorLitro() ) {   precioPorLitroMasCaro = resumenArch.leer(i).getPrecioPorLitro(); cout << resumenArch.leer(i).getIDTipoCombustible()<< endl;     }

}



for ( int j = 0; j < largoDelArchivo; j++){

    if ( resumenArch.leer(j).getPrecioPorLitro() == precioPorLitroMasCaro ) { cout << "el nombre del combustible mas caro es: " << resumenArch.leer(j).getIDTipoCombustible()<< "y el precio es:" << resumenArch.leer(j).getPrecioPorLitro(); break;      }



}





}




/*{
//El nombre del tipo de combustible que haya registrado el precio por litro más caro.
//Si existe más de un tipo de combustible que cumpla esta condición, mostrar el primero que encuentren en el archivo.


    ResumenDiarioArchivo resumendiarioArchivo;
    int vecCombustibles[5] = {};
    int combustibleMasCaro;


    for (int i = 0; i < resumendiarioArchivo.getCantidad(); i++)
    {
        cout <<i;
        if (vecCombustibles[resumendiarioArchivo.leer(i).getIDTipoCombustible() -1 ] == 0 )
        {
            vecCombustibles [resumendiarioArchivo.leer(i).getIDTipoCombustible() - 1] = resumendiarioArchivo.leer(i).getPrecioPorLitro();

        }

    }
    combustibleMasCaro = vecCombustibles[0];
    for ( int i = 0; i < 5 ; i++)
    {
        cout << vecCombustibles[i] << endl;
        if (vecCombustibles[i] >  combustibleMasCaro )
        {
            combustibleMasCaro = vecCombustibles[i];
        }

    }



    for (int x = 0; x < resumendiarioArchivo.getCantidad(); x++ )
    {


        if(resumendiarioArchivo.leer(x).getPrecioPorLitro() == combustibleMasCaro  )
        {
            cout <<"el combustible mas caro es: "<<resumendiarioArchivo.leer(x).getIDTipoCombustible()<<"y sale " <<resumendiarioArchivo.leer(x).getPrecioPorLitro() << endl;
            break;
        }


    }



}

*/



void PrimerParcial::ejercicio2()
{
//A partir de un IDEstación que se ingresa como parámetro, mostrar los meses en los que no se haya vendido Nafta Súper en esa estación.
    ResumenDiarioArchivo resumendiarioArch;
    ResumenDiario resDiario;

    int idEstacionDeServicio;
    int vecMeses[12] = {};



    cout <<"ingrese el id de estacion"<< endl;
    cin >> idEstacionDeServicio;


    for (int i = 0; i < resumendiarioArch.getCantidad(); i++)
    {
        if (resumendiarioArch.leer(i).getIDEstacion() == idEstacionDeServicio)
        {

            resDiario  = resumendiarioArch.leer(i);
            break;
        }


    }


    for (int i = 0; i < resumendiarioArch.getCantidad(); i++  )
    {




        if      (  resumendiarioArch.leer(i).getIDEstacion() == resDiario.getIDEstacion()
                   && resumendiarioArch.leer(i).getLitrosIniciales() == resumendiarioArch.leer(i).getLitrosFinales()
                   && resumendiarioArch.leer(i).getIDTipoCombustible() == 1    )



        {
            cout <<"ok"<< endl;
            vecMeses[ resumendiarioArch.leer(i).getFecha().getMes() - 1] = 1;
        }


    }
    cout <<"--------------------------------------"<< endl;
    for (int x = 0; x < 12; x++)
    {

        if (vecMeses[x] == 0 )
        {
            cout << x + 1 << endl;
        }
    }




}

void PrimerParcial::ejercicio3()
{
//El nombre del tipo de combustible que haya registrado el precio por litro promedio más caro. Mostrar todos los tipos de combustibles que cumplan esta condición.

    ResumenDiarioArchivo resumendiarioArch;
    ResumenDiario resDiario;

    resumendiarioArch.grabar(resumendiarioArch.leer(2),2);

    float vecPromedioPrecioCombustible[5] = {};
    int vecAux[5] = {};

    for (int i = 0; i < resumendiarioArch.getCantidad(); i++  )
    {
        if  (  resumendiarioArch.leer(i).getIDTipoCombustible() == 1  )
        {
            vecPromedioPrecioCombustible[0] += resumendiarioArch.leer(i).getPrecioPorLitro();
            vecAux[0]++;
        }

        if  (  resumendiarioArch.leer(i).getIDTipoCombustible() == 2  )
        {
            vecPromedioPrecioCombustible[1] += resumendiarioArch.leer(i).getPrecioPorLitro();
            vecAux[1]++;
        }
        if  (  resumendiarioArch.leer(i).getIDTipoCombustible() == 3  )
        {
            vecPromedioPrecioCombustible[2] += resumendiarioArch.leer(i).getPrecioPorLitro();
            vecAux[2]++;
        }
        if  (  resumendiarioArch.leer(i).getIDTipoCombustible() == 4  )
        {
            vecPromedioPrecioCombustible[3] += resumendiarioArch.leer(i).getPrecioPorLitro();
            vecAux[3]++;
        }
        if  (  resumendiarioArch.leer(i).getIDTipoCombustible() == 5  )
        {
            vecPromedioPrecioCombustible[4] += resumendiarioArch.leer(i).getPrecioPorLitro();
            vecAux[4]++;
        }


    }


    for (int i = 0; i < 5; i++)
    {
        cout << vecPromedioPrecioCombustible[i] / vecAux[i] << endl;


    }


}
//Hacer un archivo llamado Anuario.dat que a partir de un año que se ingrese por teclado genere un resumen mensual
//con el total de litros de combustibles vendidos en ese año y mes (en total se deben generar 12 registros).
void PrimerParcial::ejercicio4()
{

    PrimerParcial primerP;
    int anio;
    ResumenDiarioArchivo resArch;
    int vecMese[12] = {};


    cout <<"ingrese el anio para ver los registros por mes"<< endl;
    cin >> anio;

    for (int i = 0; i < resArch.getCantidad(); i ++   )
    {
        float ventaPorDia = (resArch.leer(i).getLitrosIniciales() - resArch.leer(i).getLitrosFinales()) ;


        if ( resArch.leer(i).getFecha().getAnio() == anio  )
        {

            vecMese[resArch.leer(i).getFecha().getMes() - 1 ] += ventaPorDia;

        }
    }
    for (int j=0; j < 12; j++)
    {

        FILE *p;
        p = fopen("Anuario.dat","ab");
        if (p == NULL) cout <<" no se pudo abrir"<< endl;

        primerP.setVentaPorMes(vecMese[j]) ;


        fwrite(this, sizeof (PrimerParcial), 1, p);
        fclose(p);



    }

    for (int j=0; j < 12; j++) {

        cout << vecMese[j]<< endl;



    }


}






