#include <iostream>
using namespace std;

void Texto_a_Morse(){
system("clear");
char EL_Mensaje[500] = {}; //AQUI SE GUARDARA EL MENSAJE (max 500 caracteres)
cout << "Ingrese una frase: " << endl;
cin >> EL_Mensaje; 

for (int i = 0 ; i < 500; i++)
{
    if (EL_Mensaje[i] == 'A' or EL_Mensaje[i] == 'a')
    {
        cout << ".-";
      
    }
    else if (EL_Mensaje[i] == 'B' or EL_Mensaje[i] == 'b')
    {
        cout << "-...";
        
    }
     else if (EL_Mensaje[i] == 'C' or EL_Mensaje[i] == 'c')
    {
        cout << "-.-.";
        
    }
     else if (EL_Mensaje[i] == 'D' or EL_Mensaje[i] == 'd')
    {
        cout << "-..";
       
    }
     else if (EL_Mensaje[i] == 'E' or EL_Mensaje[i] == 'e')
    {
        cout << ".";
    
    }
     else if (EL_Mensaje[i] == 'F' or EL_Mensaje[i] == 'f')
    {
        cout << "..-.";
       
    }
     else if (EL_Mensaje[i] == 'G' or EL_Mensaje[i] == 'g')
    {
        cout << "--.";
      
    }
     else if (EL_Mensaje[i] == 'H' or EL_Mensaje[i] == 'h')
    {
        cout << "....";
      
    }
     else if (EL_Mensaje[i] == 'I' or EL_Mensaje[i] == 'i')
    {
        cout << "..";
       
    }
     else if (EL_Mensaje[i] == 'j' or EL_Mensaje[i] == 'j')
    {
        cout << ".---";
       
    }
     else if (EL_Mensaje[i] == 'K' or EL_Mensaje[i] == 'k')
    {
        cout << "-.-";
       
    }
     else if (EL_Mensaje[i] == 'L' or EL_Mensaje[i] == 'l')
    {
        cout << ".-..";
       
    }
     else if (EL_Mensaje[i] == 'M' or EL_Mensaje[i] == 'm')
    {
        cout << "--";
        
    }
     else if (EL_Mensaje[i] == 'N' or EL_Mensaje[i] == 'n')
    {
        cout << "-.";
       
    }
     else if (EL_Mensaje[i] == 'O' or EL_Mensaje[i] == 'o')
    {
        cout << "---";
        
    }
     else if (EL_Mensaje[i] == 'P' or EL_Mensaje[i] == 'p')
    {
        cout << ".--.";
       
    }
     else if (EL_Mensaje[i] == 'Q' or EL_Mensaje[i] == 'q')
    {
        cout << "--.-";
     
    }
     else if (EL_Mensaje[i] == 'R' or EL_Mensaje[i] == 'r')
    {
        cout << ".-.";
       
    }
     else if (EL_Mensaje[i] == 'S' or EL_Mensaje[i] == 's')
    {
        cout << "...";
    }
     else if (EL_Mensaje[i] == 'T' or EL_Mensaje[i] == 't')
    {
        cout << "-";
    }
     else if (EL_Mensaje[i] == 'U' or EL_Mensaje[i] == 'u')
    {
        cout << "..-";
    }
     else if (EL_Mensaje[i] == 'V' or EL_Mensaje[i] == 'v')
    {
        cout << "...-";
    }
     else if (EL_Mensaje[i] == 'W' or EL_Mensaje[i] == 'w')
    {
        cout << ".--";
    }
     else if (EL_Mensaje[i] == 'X' or EL_Mensaje[i] == 'x')
    {
        cout << "-..-";
    }
     else if (EL_Mensaje[i] == 'Y' or EL_Mensaje[i] == 'y')
    {
        cout << "-.--";
    }
     else if (EL_Mensaje[i] == 'Z' or EL_Mensaje[i] == 'z')
    {
        cout << "--..";
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
