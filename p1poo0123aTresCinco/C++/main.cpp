//TresCinco  p1  Tiempo=00:30
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado"
#endif

#include <iostream>
using namespace std;

//Declaración y definición de constantes
#define PORCENTAJE_IVA 16
#define PORCENTAJE_ISR 11 
#define ISR_RETENIDO 10
#define IVA_RETENIDO 10
#define CIEN 100
//Prototipo
void pausar();
int main(){
    // Declaración de variables
    float ingreso, gasto, IVA, retencionISR, subtotal;	
    float retencionIVA, gananciaBruta, ISR, gastoIVA;
    //Entrada de datos
    cout << "CALCULO DE IMPUESTOS" << endl;
    cout << "Dame el ingreso: ";
    cin >> ingreso;
    cout << "Dame el gasto: ";
    cin >> gasto;
    system(CLEAR);
    getchar();
    //Cálculo de impuestos
    IVA = (ingreso * PORCENTAJE_IVA) / CIEN;
    subtotal = ingreso + IVA;
    retencionISR = (ingreso * ISR_RETENIDO) / CIEN;
    retencionIVA = (ingreso * IVA_RETENIDO) / CIEN;
    gananciaBruta = ingreso - gasto;
    ISR = (gananciaBruta * PORCENTAJE_ISR) / CIEN;
    gastoIVA = (gasto * PORCENTAJE_IVA) / CIEN;
    //Salida de datos
    cout << "CALCULO DE IMPUESTOS" << endl;
    cout << "**** Tabla Recibo de Honorarios ****" << endl; 
    cout << "Ingresos                   " << ingreso << endl;
    cout << "(+) IVA 		   " << IVA <<endl;
    cout << "(=) Subtotal 	           " << subtotal <<endl; 
    cout << "(-) Retencion ISR 	   " << retencionISR << endl;
    cout << "(-) Retencion IVA 	   " << retencionIVA << endl;
    cout << "(=) Total 		   " << (subtotal - retencionISR) - retencionIVA << endl;
    cout << "**** Tabla Ganancias ***" << endl; 
    cout << "Ingresos                   " << ingreso << endl;
    cout << "(-) Gastos                 " << gasto << endl;
    cout << "(=) Ganancia Bruta         " << gananciaBruta << endl;
    cout << "(-) ISR                    " << ISR << endl;
    cout << "(=) Ganancia Neta          " << gananciaBruta - ISR<< endl;
    cout << "**** Tabla ISR ****" << endl;
    cout << "ISR                        "<< ISR << endl;
    cout << "(-) ISR Retenido           "<< retencionISR << endl;
    cout << "(=) ISR a Pagar            "<< ISR - retencionISR << endl;
    cout << "**** Tabla IVA ****" << endl;
    cout << "IVA                        " << IVA << endl;
    cout << "(-) Gastos IVA             " << gastoIVA  << endl;
    cout << "(-) Retencion IVA          " << retencionIVA << endl;
    cout << "(=) IVA a Pagar            " << (IVA - retencionIVA) - gastoIVA << endl;
    pausar();
    return 0;
}
void pausar(){
    cout << "Presiona ENTER para continuar..." << endl;
    cin.get();
}
