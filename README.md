
# 📟 El codigo Morse UPV

Mi compañero y yo hicimos un programa que consiste en recibir un mensaje en Morse, para despues, traducirlo al español e imprimirlo en la consola y viceversa, da un mensaje en español y lo convierte a Morse.

## Como ejecutarlo 🎯
Primero se tiene que ejecutar el archivo Bash, ya que lo que hace es imprimir el menu y compilar el archivo C++ y Python
![Logo](https://cdn.discordapp.com/attachments/1074344483824603217/1346148761306660974/Screenshot_from_2025-03-03_09-47-58.png?ex=67c7223a&is=67c5d0ba&hm=a0706260a26f83f88d87d4d0b6ec956fcebab172486372ee01c4360aa3a9825f&)

Figura 1: Codigo fuente del archivo bash.
## El proceso de texto a Morse 🍞
Muy simple, el usario ingresa una frase y el programa procedera a reproducir el mensaje en Morse, para despues, mostrar el mensaje codificado.

![Logo](https://cdn.discordapp.com/attachments/1074344483824603217/1346148761617043519/Screenshot_from_2025-03-03_09-50-46.png?ex=67c7223b&is=67c5d0bb&hm=0a94f4138ddf917784e688c845b8617b56ca1a1ff25800feac5326a3479a16a3&)

Figura 2: En ejecusion el archivo C++.
## Ahora si viene lo chido: De Morse a texto pa ⚡
El codigo se creo en un archivo Python, porque es un lenguaje de programacion que contiene los recursos para el uso del microfono, al igual que los repositorios del codigo Morse .

![Logo](https://cdn.discordapp.com/attachments/1074344483824603217/1346148761935548527/Screenshot_from_2025-03-03_09-53-56.png?ex=67c7223b&is=67c5d0bb&hm=e0a09f5b390e2e86823eca69e3659c0a0bb3274c0d023d51a12d02b3d4ef1f61&)

Figura 3: En ejecusion el archivo Python.


## Comandos

Tuvimos que instalar algunos paquetes para poder utilizar los sonidos de Morse y el microfono:

- Instalar Python3: sudo apt install python3
- pip es el administrador de paquetes para instalar bibliotecas de Python: sudo apt install python3-pip
- Instalar Herramientas de Desarrollo: sudo apt install python3-dev python3-venv build-essential
- Instala Dependencias Necesarias: sudo apt install portaudio19-dev python3-pyaudio
- Instalar PyAudio con pip: pip3 install pyaudio
- Verificar la instalacion: python3 -c "import pyaudio; print('PyAudio instalado correctamente')"
- La biblioteca numpy: sudo apt install python3-numpy
- Instalar el sondio de Morse: sudo apt install sox
- Soporte para formatos como MP3: sudo apt install sox libsox-fmt-all

![Logo](https://media.tenor.com/x8v1oNUOmg4AAAAM/rickroll-roll.gif)
