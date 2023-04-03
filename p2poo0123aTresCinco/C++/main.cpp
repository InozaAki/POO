//TresCinco p2 Tiempo = 00:50
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix) || defined(__unix__) || defined (__unix) || defined(__APPLE__) || defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO NO SOPORTADO"
#endif

#include <iostream>
#include <cstdlib>
using namespace std;

// Declaracion y definicion de constantes simbolicas
enum{ESTABLECE_MES = 1, CAPTURA_INGRESOS, CAPTURA_GASTOS, MOSTRAR_INGRESOS, MOSTRAR_GASTOS,
    CALCULO_IMPUESTO, SALIR};
#define PORCENTAJE_IVA 16
#define PORCENTAJE_ISR 11
#define ISR_RETENIDO 10
#define IVA_RETENIDO 10
#define C_100 100
#define TOTAL_MESES 12

int main(){
    // Declaracion de variables para entrada de datos
    float ingreso = 0, gasto = 0;
    int opcion, opcionMes;
    int mes = 0;
    //Declaracion de variables para computo
    float IVA, retencionISR, subtotal, retencionIVA;
    float gananciaBruta, ISR, gastoIVA;
    bool continuar = true;
    int i;
    //
    string meses[TOTAL_MESES] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", 
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    float ingresosMensuales[TOTAL_MESES] = {0};
    float gastosMensuales[TOTAL_MESES] = {0};
    do{ 
        system(CLEAR);
        cout << "CALCULO DE IMPUESTOS ANUAL\n" << endl;
        cout << "Menu principal:" << endl;
        cout << "1. Establecer mes para captura (el mes actual es " << meses[mes] << ")" << endl;
        cout << "2. Captura de ingresos" << endl;
        cout << "3. Captura de gastos" << endl;
        cout << "4. Mostrar lista de ingresos anual" << endl;
        cout << "5. Mostrar lista de gastos anual" << endl;
        cout << "6. Calculo de impuesto anual" << endl;
        cout << "7. Salir" << endl;
        cout << "\nOpcion: ";
        cin >> opcion;
        cin.get();
        system(CLEAR);       
        switch(opcion){
            case ESTABLECE_MES:
                cout << "Elige el mes" << endl;
                cout << "1)  Enero \n2)  Febrero\n3)  Marzo\n4)  Abril\n5)  Mayo\n6)  Junio" << endl;
                cout << "7)  Julio\n8)  Agosto\n9)  Septiembre\n10) Octubre\n11) Noviembre\n12) Diciembre" << endl;
                cout << "\nOpcion: ";
                cin >> opcionMes;
                cin.get();
                if(opcionMes > 0 && opcionMes < 13){
                    mes = --opcionMes;
                    cout << "Se ha elegido el mes: " << meses[mes] << endl;
                    cout << "Presiona ENTER para continuar..." << endl;
                    cin.get();
                    break;
                }else{
                    cout << "Mes invalido" << endl;
                    cout << "Presiona ENTER para volver al menu..." << endl;
                    cin.get();
                    break;
                }
            //Entrada de datos
            case CAPTURA_INGRESOS:
                cout << "Captura de ingresos" << endl;
                cout << "Dame el ingreso del mes de " << meses[mes] << ": ";
                cin >> ingresosMensuales[mes];
                cin.get();
                cout << "Presione ENTER para continuar..." << endl;
                cin.get();
                break;
            case CAPTURA_GASTOS:
                cout << "Captura de gastos" << endl;
                cout << "Dame los gastos del mes de " << meses[mes] << ": ";
                cin >> gastosMensuales[mes];
                cin.get();
                cout << "Presione ENTER para continuar..." << endl;
                cin.get();
                break;
            case MOSTRAR_INGRESOS:
                cout << "Mostrar lista de ingresos anuales" << endl;
                for(i = 0; i < TOTAL_MESES; i++){
                    cout << meses[i] << " = " << ingresosMensuales[i] << endl;;
                }
                cout << "Presiona ENTER para continuar...";
                cin.get();
                break;
            case MOSTRAR_GASTOS:
                cout << "Mostrar lista de gastos anuales" << endl;
                for(i = 0; i < TOTAL_MESES; i++){
                    cout << meses[i] << " = " << gastosMensuales[i] << endl;
                }
                cout << "Presiona ENTER para continuar...";
                cin.get();
                break;
            case CALCULO_IMPUESTO:
                //Calculo de impuestos
                gasto = 0;
                ingreso = 0;
                for(i = 0; i < TOTAL_MESES; i++){
                    ingreso += ingresosMensuales[i];
                    gasto += gastosMensuales[i];
                }
                IVA = (ingreso * PORCENTAJE_IVA) / C_100;
                subtotal = ingreso + IVA;
                retencionISR = (ingreso * ISR_RETENIDO) / C_100;
                retencionIVA = (ingreso * IVA_RETENIDO) / C_100;
                gananciaBruta = ingreso - gasto;
                ISR = (gananciaBruta * PORCENTAJE_ISR) / C_100;
                gastoIVA = (gasto * PORCENTAJE_IVA) / C_100;
                //Salida de resultados
                cout << "Calculo de impuestos anuales" << endl;
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
                cout << "Presiona ENTER para continuar...";
                cin.get();
                break;
            case SALIR:
                continuar = false;
                break;
            default:
                cout << "Opcion no valida" << endl;
                cout << "Presiona ENTER para continuar..." << endl;
                cin.get();
        }
    }while(continuar);
    return 0;
}
