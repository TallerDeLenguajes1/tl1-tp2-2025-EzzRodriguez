#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct compu{
    int velocidad; //entre 1 y 3
    int anio; //entre 2015 y 2025
    int cantidad_nucleos;// entre 1 y 8
    char *tipo_cpu; //puntero a cadena de caracteres
}typedef compu;


void listarPCs(compu pcs[], int cantidad);
void mostrarMasVieja(compu pcs[], int cantidad);
void mostrarMasVeloz(compu pcs[], int cantidad);


int main(){
    srand(time(NULL));
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core","Pentium"};
    char *tipo_cpu1 = &tipos[rand() % 6][0];
    char *tipo_cpu2 = &tipos[rand() % 6][0];
    char *tipo_cpu3 = &tipos[rand() % 6][0];
    char *tipo_cpu4 = &tipos[rand() % 6][0];
    char *tipo_cpu5 = &tipos[rand() % 6][0];

    compu compu1 = {(1 + rand() % 3),(2015 + rand() % 11),(1 + rand() % 8), tipo_cpu1};
    compu compu2 = {(1 + rand() % 3),(2015 + rand() % 11),(1 + rand() % 8), tipo_cpu2};
    compu compu3 = {(1 + rand() % 3),(2015 + rand() % 11),(1 + rand() % 8), tipo_cpu3};
    compu compu4 = {(1 + rand() % 3),(2015 + rand() % 11),(1 + rand() % 8), tipo_cpu4};
    compu compu5 = {(1 + rand() % 3),(2015 + rand() % 11),(1 + rand() % 8), tipo_cpu5};

    compu compus[5] = {compu1,compu2,compu3,compu4,compu5};
    listarPCs(compus,5);
    mostrarMasVieja(compus,5);
    mostrarMasVeloz(compus,5);

}

void listarPCs(compu pcs[], int cantidad)
{
    printf("\nDatos de computadoras registradas:\n\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Computadora %i:\nVelocidad: %i, Anio:%i, Nucleos:%i, Tipo de cpu:",i+1,pcs[i].velocidad,pcs[i].anio,pcs[i].cantidad_nucleos);
        puts(pcs[i].tipo_cpu);
        printf("\n");
    }
    
}

void mostrarMasVieja(compu pcs[], int cantidad)
{
    int anio = 2026,masVieja;
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio < anio)
        {
            anio = pcs[i].anio;
            masVieja = i;
        }
    }
    printf("\nLa computadora mas vieja es la nro %i:\nVelocidad: %i, Anio:%i, Nucleos:%i, Tipo de cpu:",masVieja+1,pcs[masVieja].velocidad,pcs[masVieja].anio,pcs[masVieja].cantidad_nucleos);
    puts(pcs[masVieja].tipo_cpu);
    printf("\n");
}

void mostrarMasVeloz(compu pcs[], int cantidad)
{
    int velocidad = 0,masVeloz;
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].velocidad > velocidad)
        {
            velocidad = pcs[i].velocidad;
            masVeloz = i;
        }
    }
    printf("\nLa computadora mas veloz es la nro %i:\nVelocidad: %i, Anio:%i, Nucleos:%i, Tipo de cpu:",masVeloz+1,pcs[masVeloz].velocidad,pcs[masVeloz].anio,pcs[masVeloz].cantidad_nucleos);
    puts(pcs[masVeloz].tipo_cpu);
    printf("\n");
}
