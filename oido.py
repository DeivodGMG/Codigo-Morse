import pyaudio
import numpy as np
import time

# Diccionario Morse a texto
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
CHUNK = 1024  # Tamaño de cada muestra
RATE = 44100  # Frecuencia de muestreo
THRESHOLD = 1000  # Umbral de sonido

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
                    if silence_duration > 1.5:
                        # Nueva letra
                        print(MORSE_CODE.get(morse_sequence, "?"), end="", flush=True)
                        morse_sequence = ""
                    elif silence_duration > 0.5:
                        # Espacio entre palabras
                        print(" ", end="", flush=True)
                
                start_time = time.time()
                while volume > THRESHOLD:
                    data = np.frombuffer(stream.read(CHUNK, exception_on_overflow=False), dtype=np.int16)
                    volume = np.max(np.abs(data))
                duration = time.time() - start_time
                
                if duration < 0.2:
                    morse_sequence += "."
                else:
                    morse_sequence += "-"
                
                last_sound_time = time.time()
    except KeyboardInterrupt:
        print("\nFinalizando...")
        stream.stop_stream()
        stream.close()
        p.terminate()

if __name__ == "__main__":
    detect_morse()

