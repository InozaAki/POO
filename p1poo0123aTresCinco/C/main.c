//TresCinco  p1  Tiempo=00:30
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado"
#endif

#include <stdio.h>
#include <stdlib.h>
// Declaracion y definicion de constantes
#define PORCENTAJE_IVA 16
#define PORCENTAJE_ISR 11
#define ISR_RETENIDO 10
#define IVA_RETENIDO 10
#define CIEN 100
//Prototipo
void pausar();

int main(){
    //Declaracion de variables
    float ingreso, gasto, IVA, retencionISR, subtotal;
    float retencionIVA, gananciaBruta,  ISR, gastoIVA;
    //Entrada de datos
    printf("CALCULO DE IMPUESTOS\n");
    printf("Dame el ingreso: ");
    scanf("%f", &ingreso);
    printf("Dame el gasto: ");
    scanf("%f", &gasto);
    system(CLEAR);
    getchar(); 
    //Calculo de impuestos
    IVA = (ingreso * PORCENTAJE_IVA) / CIEN;
    subtotal = ingreso + IVA;
    retencionISR = (ingreso * ISR_RETENIDO) / CIEN;
    retencionIVA = (ingreso * IVA_RETENIDO) / CIEN;
    gananciaBruta = ingreso - gasto;
    ISR = (gananciaBruta * PORCENTAJE_ISR) / CIEN;
    gastoIVA = (gasto * PORCENTAJE_IVA) / CIEN;
    //Salida de datos
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
    pausar();
    return 0;
}
void pausar(){
    printf("Presiona ENTER para continuar...\n");
    scanf(".");
}
