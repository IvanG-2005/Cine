#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>//Ivan
using namespace std;
//lineas 8-30 creadas por Melvyn
int preciorand()
{
srand(time(0));
return rand() % 5;
}

void guardarRecibo(string w, string x, string y, string z, string p[])
{
ofstream resultado("Recibo.txt");

resultado << "=============== Recibo de Usuario ===============" << endl;
resultado << left << setw(12)<< "Pelicula: " << w << endl;
resultado << left << setw(12)<< "Horario: " << x << endl;
resultado << left << setw(12)<< "Comida: " << y << endl;
resultado << left << setw(12)<< "Silla: " << z << endl;
resultado << "=================================================" << endl;
resultado << left << setw(12)<< "Precio: " << p[preciorand()] << endl;
resultado << "=================================================" << endl;
resultado << "Presente este recibo a su cine mas cercano." << endl;
resultado << "=================================================" << endl;

resultado.close();
}
//lineas 34-40 fueron completadas con asistencia de Copilot, Melvyn
void imprimirRecibo()
{
ifstream resultado("Recibo.txt");

string linea;
while (getline(resultado, linea))
{
cout << linea << endl;
}

resultado.close();
}
//Ivan
void seleccionPelicula()
{
string peliculas[] = { "Snow White", "A working man", "Sinners", "Minecraft", "The Amateur" };

string horarios[] = { "10:40 AM", "1:00 PM", "4:15 PM", "7:30 PM" };

string comida[] = { "Pop-corn", "Nachos", "Refrescos", "Hot Dog", "Nada" };
//melvyn
string precio[] = { "$7.99", "$9.99", "$11.99", "$12.99", "$14.99" };

string silla1 = "[ 01 ][ 02 ] [ 03 ][ 04 ][ 05 ][ 06 ] [ 07 ][ 08 ]\n";
string silla2 = "[ 09 ][ 10 ] [ 11 ][ 12 ][ 13 ][ 14 ] [ 15 ][ 16 ]\n";
string silla3 = "[ 17 ][ 18 ] [ 19 ][ 20 ][ 21 ][ 22 ] [ 23 ][ 24 ]\n";
string silla4 = "[ 25 ][ 26 ] [ 27 ][ 28 ][ 29 ][ 30 ] [ 31 ][ 32 ]\n";
string silla5 = "[ 33 ][ 34 ] [ 35 ][ 36 ][ 37 ][ 38 ] [ 39 ][ 40 ]\n";
string silla6 = "[ 41 ][ 42 ] [ 43 ][ 44 ][ 45 ][ 46 ] [ 47 ][ 48 ]\n";

string salaDeCine = silla1 + silla2 + silla3 + silla4 + silla5 + silla6;
//Ivan
string sillaOpcion;

char confirmacion;

int peliculaOpcion, horariOpcion, comidaOpcion;

for (int i = 0; i < 5; i++){
   
    cout << left << setw(3) << (i + 1) << peliculas[i] << endl;
}

cout << "\nSeleccione el numero de la pelicula que quiere ver: ";
cin >> peliculaOpcion;

if (peliculaOpcion < 1 || peliculaOpcion>5){
    
cout << "Seleccion invalida. \n";
return;
}

cout << "\nHorarios disponibles para " << peliculas[peliculaOpcion - 1] << ": \n";

for (int i = 0; i < 4; i++){
    
cout << left << setw(3) << (i + 1) << horarios[i] << endl;
}

cout << "\nSeleccione el numero del horario: ";
cin >> horariOpcion;

if (horariOpcion < 1 || horariOpcion>4)
{
cout << "Horario invalido.\n";
return;
}

cout << "\nHas seleccionado: " << peliculas[peliculaOpcion - 1] << " a las " << horarios[horariOpcion - 1] << endl;

cout << "\n Menu de comida:\n";
for (int i = 0; i < 5; i++)
{
cout << left << setw(2) << (i + 1) << comida[i] << endl;
}
//melvyn
cout << "\nSeleccione la comida que desee pedir: ";
cin >> comidaOpcion;

if (comidaOpcion < 1 || comidaOpcion>5)
{
cout << "Opcion no disponible. \n";
return;
}
do
{
cout << "\nSeleccione la silla que desee: " << endl;

cout << salaDeCine << endl;
cin >> sillaOpcion;
cout << "\nEsta de acuerdo con esta seleccion? (Y/N)" << endl;
cin >> confirmacion;
} while (confirmacion != 'Y');

string inputP = peliculas[peliculaOpcion - 1];
string inputH = horarios[horariOpcion - 1];
string inputC = comida[comidaOpcion - 1];

guardarRecibo(inputP, inputH, inputC, sillaOpcion, precio);
imprimirRecibo();
}

int main(){
    
cout << "Bienvenido a la pagina del cine, aqui puede pedir las taquillas para la pelicula que desee: " << endl;
seleccionPelicula();

return 0;
}
