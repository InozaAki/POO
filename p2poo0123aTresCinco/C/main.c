#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix) || defined(__unix__) || defined (__unix) || defined(__APPLE__) || defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO NO SOPORTADO"
#endif

#include <stdio.h>
#include <stdlib.h>
//Declaracion y definicion de constantes simbolicas
typedef enum{ESTABLECE_MES = 1, CAPTURA_INGRESOS, CAPTURA_GASTOS, MOSTRAR_INGRESOS, MOSTRAR_GASTOS,
    CALCULO_IMPUESTO, SALIR} opcionesMenu;
typedef enum{FALSO = 0, VERDADERO} booleano;
#define PORCENTAJE_IVA 16
#define PORCENTAJE_ISR 11
#define ISR_RETENIDO 10
#define IVA_RETENIDO 10
#define C_100 100
#define TOTAL_MESES 12

int main(){
    //Declaracion de variables para entrada de datos
    float ingreso = 0, gasto = 0;
    int opcion, opcionMes;
    int mes = 0;
    //Declaracion de variables para computo
    float IVA, retencionISR, subtotal, retencionIVA;
    float gananciaBruta, ISR, gastoIVA;
    booleano continuar = VERDADERO;
    int i;
    //
    char* meses[TOTAL_MESES] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", 
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    float ingresosMensuales[TOTAL_MESES] = {0};
    float gastosMensuales[TOTAL_MESES]  = {0};
    do{
        system(CLEAR);
        printf("CALCULO DE IMPUESTOS ANUAL\n\n");
        printf("Menu principal:  \n");
        printf("1. Establecer mes para captura (el mes actual es %s)\n", meses[mes]);
        printf("2. Captura de ingresos\n");
        printf("3. Captura de gastos\n");
        printf("4. Mostrar lista de ingresos anual\n");
        printf("5. Mostrar lista de gastos anual\n");
        printf("6. Calculo de impuesto anual\n");
        printf("7. Salir\n");
        printf("\nOpcion: ");
        scanf("%d", &opcion);
        system(CLEAR);
        getchar();
        switch(opcion){
            case ESTABLECE_MES:
                printf("Elige el mes\n");
                printf("1)  Enero \n2)  Febrero\n3)  Marzo\n4)  Abril\n5)  Mayo\n6)  Junio\n");
                printf("7)  Julio\n8)  Agosto\n9)  Septiembre\n10) Octubre\n11) Noviembre\n12) Diciembre\n");
                printf("\n Opcion: ");
                scanf("%d", &opcionMes);
                getchar();
                if(opcionMes > 0 && opcionMes < 13){
                    mes = --opcionMes;
                    printf("Se ha elegido el mes: %s\n", meses[mes]);
                    printf("Presiona ENTER para continuar...\n");
                    scanf(".");
                    break;
                }else{
                    printf("Mes invalido\n");
                    printf("Presiona ENTER para volver al menu....\n");
                    scanf(".");
                    break;
                }
            //Entrada de datos
            case CAPTURA_INGRESOS:
                printf("Captura de ingresos\n");
                printf("Dame el ingreso del mes de %s: ", meses[mes]);
                scanf("%f", &ingresosMensuales[mes]);
                printf("Presione ENTER para continuar...\n");
                getchar();
                scanf(".");
                break;
            case CAPTURA_GASTOS:
                printf("Captura de gastos\n");
                printf("Dame los gastos del mes de %s: ", meses[mes]);
                scanf("%f", &gastosMensuales[mes]);
                printf("Presione ENTER para continuar...\n");
                getchar();
                scanf(".");
                break;
            case MOSTRAR_INGRESOS:
                printf("Mostrar lista de ingresos anuales\n");
                for(i = 0; i < TOTAL_MESES; i++){
                    printf("%s =  %.2f\n", meses[i], ingresosMensuales[i]);
                }
                printf("Presiona ENTER para continuar...\n");
                scanf(".");
                break;
            case MOSTRAR_GASTOS:
                printf("Mostrar lista de gastos anuales\n");
                for(i = 0; i < TOTAL_MESES; i++){
                    printf("%s =  %.2f\n", meses[i], gastosMensuales[i]);
                }
                printf("Presiona ENTER para continuar...");
                scanf(".");
                break;
            case CALCULO_IMPUESTO:
                //Calculo de impuestos
                ingreso = 0;
                gasto = 0;
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
                printf("CALCULO DE IMPUESTOS\n");
                printf("**** Tabla Recibo de Honoriarios ****\n");
                printf("Ingresos                    %.2f\n", ingreso);
                printf("(+) IVA                     %.2f\n", IVA);
                printf("(=) Subtotal                %.2f\n", subtotal);
                printf("(-) Retencion ISR           %.2f\n", retencionISR);
                printf("(-) Retencion IVA           %.2f\n", retencionIVA);
                printf("(=) Total                   %.2f\n", (subtotal-retencionISR) - retencionIVA);
                printf("**** Tabla Ganancias ****\n");
                printf("Ingresos                    %.2f\n", ingreso);
                printf("(-) Gastos                  %.2f\n", gasto);
                printf("(=) Ganancia Bruta          %.2f\n", gananciaBruta);
                printf("(-) ISR                     %.2f\n", ISR);
                printf("(=) Ganancia Neta           %.2f\n", gananciaBruta-ISR);
                printf("**** Tabla ISR ****\n");
                printf("ISR                         %.2f\n", ISR);
                printf("(-) ISR Retenido            %.2f\n", retencionISR);
                printf("(=) ISR a Pagar             %.2f\n", ISR - retencionISR);
                printf("**** Tabla IVA ****\n");
                printf("IVA                         %.2f\n", IVA);
                printf("(-) Gastos IVA              %.2f\n", gastoIVA);
                printf("(-) Retencion IVA           %.2f\n", retencionIVA);
                printf("(=) IVA a Pagar             %.2f\n", (IVA-retencionIVA) - gastoIVA);
                printf("Presiona ENTER para continuar...\n");
                scanf(".");
                break;
            case SALIR:
                continuar = FALSO;
                break;
            default:
                printf("Opcion no valida\n");
                printf("Presiona ENTER para continuar....\n");
                scanf(".");
        }
    }while(continuar);
    return 0;
}