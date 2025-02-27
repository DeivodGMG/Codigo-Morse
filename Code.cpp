#include <iostream>
using namespace std;
void Texto_a_Morse() {
    system("clear");
    char EL_Mensaje[500] = {};

    cout << "Ingrese una frase: " << endl;
    cin.ignore();
    cin.getline(EL_Mensaje, 500);

    for (int i = 0; i < 500 && EL_Mensaje[i] != '\0'; i++) {
        if (EL_Mensaje[i] == ' ') {
            cout << "  ";
        } else if (EL_Mensaje[i] == 'A' || EL_Mensaje[i] == 'a') {
            cout << ".-";
        } else if (EL_Mensaje[i] == 'B' || EL_Mensaje[i] == 'b') {
            cout << "-...";
        } else if (EL_Mensaje[i] == 'C' || EL_Mensaje[i] == 'c') {
            cout << "-.-.";
        } else if (EL_Mensaje[i] == 'D' || EL_Mensaje[i] == 'd') {
            cout << "-..";
        } else if (EL_Mensaje[i] == 'E' || EL_Mensaje[i] == 'e') {
            cout << ".";
        } else if (EL_Mensaje[i] == 'F' || EL_Mensaje[i] == 'f') {
            cout << "..-.";
        } else if (EL_Mensaje[i] == 'G' || EL_Mensaje[i] == 'g') {
            cout << "--.";
        } else if (EL_Mensaje[i] == 'H' || EL_Mensaje[i] == 'h') {
            cout << "....";
        } else if (EL_Mensaje[i] == 'I' || EL_Mensaje[i] == 'i') {
            cout << "..";
        } else if (EL_Mensaje[i] == 'J' || EL_Mensaje[i] == 'j') {
            cout << ".---";
        } else if (EL_Mensaje[i] == 'K' || EL_Mensaje[i] == 'k') {
            cout << "-.-";
        } else if (EL_Mensaje[i] == 'L' || EL_Mensaje[i] == 'l') {
            cout << ".-..";
        } else if (EL_Mensaje[i] == 'M' || EL_Mensaje[i] == 'm') {
            cout << "--";
        } else if (EL_Mensaje[i] == 'N' || EL_Mensaje[i] == 'n') {
            cout << "-.";
        } else if (EL_Mensaje[i] == 'O' || EL_Mensaje[i] == 'o') {
            cout << "---";
        } else if (EL_Mensaje[i] == 'P' || EL_Mensaje[i] == 'p') {
            cout << ".--.";
        } else if (EL_Mensaje[i] == 'Q' || EL_Mensaje[i] == 'q') {
            cout << "--.-";
        } else if (EL_Mensaje[i] == 'R' || EL_Mensaje[i] == 'r') {
            cout << ".-.";
        } else if (EL_Mensaje[i] == 'S' || EL_Mensaje[i] == 's') {
            cout << "...";
        } else if (EL_Mensaje[i] == 'T' || EL_Mensaje[i] == 't') {
            cout << "-";
        } else if (EL_Mensaje[i] == 'U' || EL_Mensaje[i] == 'u') {
            cout << "..-";
        } else if (EL_Mensaje[i] == 'V' || EL_Mensaje[i] == 'v') {
            cout << "...-";
        } else if (EL_Mensaje[i] == 'W' || EL_Mensaje[i] == 'w') {
            cout << ".--";
        } else if (EL_Mensaje[i] == 'X' || EL_Mensaje[i] == 'x') {
            cout << "-..-";
        } else if (EL_Mensaje[i] == 'Y' || EL_Mensaje[i] == 'y') {
            cout << "-.--";
        } else if (EL_Mensaje[i] == 'Z' || EL_Mensaje[i] == 'z') {
            cout << "--..";
        }
        cout << " "; // Separar cada letra con un espacio
    }
    cout << endl;
}

void Morse_a_Texto() {
    system("clear");
    // Implementación pendiente
}

int main() {
    char select = '0';

    while (true) {
        cin >> select;
        if (select == '1') {
            Texto_a_Morse();
            break;
        } else if (select == '2') {
            Morse_a_Texto();
            break;
        }
    }

    return 0;
}
