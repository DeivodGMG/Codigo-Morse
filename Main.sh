#! /bin/bash

clear
g++ Code.cpp -o Ejecutable
echo "** El Menu Interactivo UPV **"
    echo "1) De texto a Morse"
    echo "2) De Morse a texto"
    echo "Elija una opcion:"
while true; do
    read select
    if [ "$select" -eq 1 ]; then
        ./Ejecutable
        break
    elif [ "$select" -eq 2 ]; then
        python3 oido.py
        break
    else
        echo "Opción no válida, por favor intente de nuevo."
    fi
done
