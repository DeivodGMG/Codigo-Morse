import pyaudio
import numpy as np
import time

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

def detect_morse():
    p = pyaudio.PyAudio()
    stream = p.open(format=pyaudio.paInt16, channels=1, rate=RATE, input=True, frames_per_buffer=CHUNK)
    
    print("Escuchando... Usa sonidos cortos para puntos y largos para rayas")
    morse_sequence = ""
    last_sound_time = None
    
    try:
        while True:
            data = np.frombuffer(stream.read(CHUNK, exception_on_overflow=False), dtype=np.int16)
            volume = np.max(np.abs(data))
            
            if volume > THRESHOLD:
                if last_sound_time is not None:
                    silence_duration = time.time() - last_sound_time
                    if silence_duration > 0.5:  # Reducido para detección más rápida
                        # Nueva letra
                        print(MORSE_CODE.get(morse_sequence, "?"), end="", flush=True)
                        morse_sequence = ""
                    elif silence_duration > 0.2:  # Reducido para detección más rápida
                        # Espacio entre palabras
                        print(" ", end="", flush=True)
                
                start_time = time.time()
                while volume > THRESHOLD:
                    data = np.frombuffer(stream.read(CHUNK, exception_on_overflow=False), dtype=np.int16)
                    volume = np.max(np.abs(data))
                duration = time.time() - start_time
                
                if duration < 0.1:  # Reducido para detección más rápida
                    morse_sequence += "."
                else:
                    morse_sequence += "-"
                
                last_sound_time = time.time()
            else:
                if last_sound_time is not None and (time.time() - last_sound_time) > 0.5:  # Reducido para detección más rápida
                    # Nueva letra
                    print(MORSE_CODE.get(morse_sequence, "?"), end="", flush=True)
                    morse_sequence = ""
                    last_sound_time = None
    except KeyboardInterrupt:
        print("\nFinalizando...")
    finally:
        stream.stop_stream()
        stream.close()
        p.terminate()

if __name__ == "__main__":
    detect_morse()
