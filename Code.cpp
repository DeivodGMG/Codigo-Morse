#include <iostream>
#include <map>
#include <unistd.h>
using namespace std;

void beepMorse(char signal) {
    if (signal == '.') {
        system("play -nq -t alsa synth 0.15 sine 1000");
    } else if (signal == '-') {
        system("play -nq -t alsa synth 0.45 sine 1000");
    }
    usleep(150000);
}

void Texto_a_Morse() {
    system("clear");
    char EL_Mensaje[500] = {};
    cout << "Ingrese una frase: " << endl;
    cin.ignore();
    cin.getline(EL_Mensaje, 500);

    map<char, string> morseCode = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {' ', "  "}
    };

    string mensaje_morse = "";
    for (int i = 0; i < 500 && EL_Mensaje[i] != '\0'; i++) {
        char c = toupper(EL_Mensaje[i]);
        if (morseCode.find(c) != morseCode.end()) {
            string morse = morseCode[c];
            mensaje_morse += morse + " ";
            for (char signal : morse) {
                beepMorse(signal);
            }
            cout << " "; // Separar letras con espacio
            usleep(300000); // Pausa entre letras (300ms)
        }
    }
    cout << endl;
    cout << "Mensaje en Morse: " << mensaje_morse << endl;
}

void Morse_a_Texto() {
    system("clear");
    // Implementación pendiente
}

int main() {
    system("clear");
    char select;
    cout << "** El Menu Interactivo UPV **\n1) De texto a Morse\n2) De Morse a texto\nElija una opcion:\n";
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
