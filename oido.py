import pyaudio
import numpy as np
import time
from os import system

# El Diccionario UPV
MORSE_CODE = {
    ".-": "A", "-...": "B", "-.-.": "C", "-..": "D", ".": "E",
    "..-.": "F", "--.": "G", "....": "H", "..": "I", ".---": "J",
    "-.-": "K", ".-..": "L", "--": "M", "-.": "N", "---": "O",
    ".--.": "P", "--.-": "Q", ".-.": "R", "...": "S", "-": "T",
    "..-": "U", "...-": "V", ".--": "W", "-..-": "X", "-.--": "Y",
    "--..": "Z", "-----": "0", ".----": "1", "..---": "2", "...--": "3",
    "....-": "4", ".....": "5", "-....": "6", "--...": "7", "---..": "8", "----.": "9"
}

# Configuración de audio
CHUNK = 256  # Tamaño de cada muestra (reducido para menor latencia)
RATE = 44100  # Frecuencia de muestreo
THRESHOLD = 800  # Umbral de sonido (ajustado para mayor sensibilidad)
INACTIVITY_TIMEOUT = 5  # Tiempo de inactividad para finalizar el programa (en segundos)

def detect_morse():
    p = pyaudio.PyAudio()
    stream = p.open(format=pyaudio.paInt16, channels=1, rate=RATE, input=True, frames_per_buffer=CHUNK)
    system("clear")
    print("Escuchando el mensaje: (segun)")
    morse_sequence = ""
    last_sound_time = None
    message = ""
    start_time = time.time()
    
    try:
        while True:
            data = np.frombuffer(stream.read(CHUNK, exception_on_overflow=False), dtype=np.int16)
            volume = np.max(np.abs(data))
            
            if volume > THRESHOLD:
                start_time = time.time()  # Resetear el tiempo de inicio en cada detección de sonido
                if last_sound_time is not None:
                    silence_duration = time.time() - last_sound_time
                    if silence_duration > 0.3:  # Pausa entre letras (300ms)
                        # Nueva letra
                        message += MORSE_CODE.get(morse_sequence, "?")
                        morse_sequence = ""
                    elif silence_duration > 0.15:  # Pausa entre señales (150ms)
                        # Espacio entre palabras
                        message += " "
                
                signal_start_time = time.time()
                while volume > THRESHOLD:
                    data = np.frombuffer(stream.read(CHUNK, exception_on_overflow=False), dtype=np.int16)
                    volume = np.max(np.abs(data))
                duration = time.time() - signal_start_time
                
                if duration < 0.2:  # Punto (150ms)
                    morse_sequence += "."
                else:
                    morse_sequence += "-"
                
                last_sound_time = time.time()
            else:
                if last_sound_time is not None and (time.time() - last_sound_time) > 0.3:  # Pausa entre letras (300ms)
                    message += MORSE_CODE.get(morse_sequence, "?")
                    morse_sequence = ""
                    last_sound_time = None
            
            # Verificar si ha pasado el tiempo de inactividad
            if time.time() - start_time > INACTIVITY_TIMEOUT:
                break
    except KeyboardInterrupt:
        print("\nFinalizando...")
    finally:
        stream.stop_stream()
        stream.close()
        p.terminate()
        print("\nMensaje traducido: " + message)

if __name__ == "__main__":
    detect_morse()
