#include <iostream>
using namespace std;

void Texto_a_Morse(){
system("clear");
char EL_Mensaje[500] = {}; //AQUI SE GUARDARA EL MENSAJE (max 500 caracteres)
cout << "Ingrese una frase: " << endl;
cin >> EL_Mensaje; 

for (int i = 0 ; i < 500; i++)
{
    if (EL_Mensaje[i] == 'H' or EL_Mensaje[i] == 'a')
    {
        cout << "Funciono";
        break;
    }
    
} //For
}
void Morse_a_Texto(){
    system("clear");
   
    
}

int main(){
    char select = '0'; //Creamos la variable para seleccionar
while (true)
{
    cin >> select;
    if (select == '1') //SI EL USUARIO INGRESO 1
    {
       Texto_a_Morse();
        break; // ROMPE EL CICLO
    }
    if (select == '2') //SI EL USUARIO INGRESO 2
    {
        Morse_a_Texto();
        break; // ROMPE EL CICLO
    }
} // FIN DEL WHILE
    return 0;
}