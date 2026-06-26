# Raspberry Pi Pico 2 WH 

Bienvenido a la documentación de la **Raspberry Pi Pico 2 WH**. Este documento hecho por mí habla sobre todo lo que tiene esta placa, con especificaciones de todo, y está dividido como corresponde.

---

## 1. Chip RP2350 - Arquitectura

El chip **RP2350** es un microcontrolador de 32 bits con una arquitectura única : **Hazard3**.

*   **Procesador:** Doble núcleo (Dual-core) ARM Cortex-M35P / Hazard3 RISC-V a **150 MHz**. El chip puede conmutar dinámicamente entre núcleos Arm o RISC-V según lo que quieras
*   **Memoria RAM:** **520 KB de SRAM** interna organizada en bancos accesibles en paralelo. Esto elimina los cuellos de botella cuando ambos núcleos procesan información al mismo tiempo.
*   **Seguridad Física (Secure Boot):** Introduce parches de hardware críticos contra fallos de inyección de código (glitching) que afectaban a generaciones anteriores.

---

## 2. Wifi y Bluetooth - CYW43439 

La letra **W** en el modelo indica la presencia del chip coprocesador **Infineon CYW43439**, encargado de la conectividad inalámbrica.

### Conectividad del LED Integrado
En las placas estándar, el LED de depuración está conectado directamente a una pista de cobre hacia un pin del procesador (GPIO 25). En la **Pico 2 WH**:
1. El LED verde está soldado **dentro del circuito del chip Wi-Fi**.
2. Para encender el LED, el RP2350 debe enviar una orden de datos empaquetada a través del bus SPI interno hacia el chip CYW43439.
3. El chip Wi-Fi actúa como un expansor de pines y entrega corriente al LED.

---

## 3. Gestión de Energía y Tolerancia Eléctrica

El diseño eléctrico de la Pico 2 WH es de tipo **LDO (Low Drop-Out)** regulado para garantizar un ruido mínimo en lecturas analógicas.

*   **Voltaje de Operación (VCC):** **3.3V estrictos** en todos los pines GPIO.
*   **Tolerancia de Entrada:** **NO TOLERA 5V.** Introducir una señal de 5V por un pin GPIO destruirá las puertas lógicas del chip por sobretensión.
*   **Alimentación (VSYS):** Permite alimentación flexible entre 1.8V y 5.5V a través del pin VSYS, regulándo automáticamente a los 3.3V limpios.

---

## 4. Mapa de Pines

La Pico 2 WH expone **26 pines GPIO** multifunción. Mediante un multiplexor interno (Hardware Muxing), casi cualquier pin puede configurarse para cualquier tarea.  

En la Raspberry Pi Pico 2 W, tú puedes cambiar la función de la mayoría de los pines desde tu código según el proyecto que vayas a construir. Esto es lo que significa cada tipo de nombre:

*   **Power :** Pines de alimentación. Sirven para meter energía a la placa
*   **Ground :** Pines de Tierra (GND). Son el polo negativo
*   **GP / GPIO :** Significa *General Purpose Input Output*, Entrada/Salida de Propósito General.
*   **ADC:** *Analog to Digital Converter*. Pines analógicos que miden voltajes variables.
*   **UART :** Pines de comunicación serie. Sirven para enviar y recibir datos de texto directamente hacia otros componentes o chips.
*   **I2C / SPI :** Protocolos de comunicación avanzados. Se usan para conectar pantallas OLED, lectores de tarjetas o sensores complejos usando pocos cables.
*   **System Control :** Pines especiales del sistema (como `RUN`), que sirven para reiniciar la placa de forma física.

---

---
### Imagen Mapa de Pines

![Imagen de Pines](https://www.raspberrypi.com/documentation/microcontrollers/images/pico2w-pinout.svg)

| Pin (Izq) | Nombre | Tipo / Color Principal | | Tipo / Color Principal | Nombre | Pin (Der) |
| :---: | :--- | :--- | :---: | :--- | :--- | :---: |
| **1** | GP0 | GPIO / UART0 TX / I2C0 SDA | | Power (Salida 5V del USB) | VBUS | **40** |
| **2** | GP1 | GPIO / UART0 RX / I2C0 SCL | | Power (Entrada de Batería) | VSYS | **39** |
| **3** | GND | Ground (Tierra) | | Ground (Tierra) | GND | **38** |
| **4** | GP2 | GPIO / I2C1 SDA | | Power (Encendido regulador) | 3V3_EN | **37** |
| **5** | GP3 | GPIO / I2C1 SCL | | Power (Salida 3.3V Regulada)| 3V3(OUT) | **36** |
| **6** | GP4 | GPIO / UART1 TX / I2C0 SDA | | ADC (Voltaje Referencia) | ADC_VREF | **35** |
| **7** | GP5 | GPIO / UART1 RX / I2C0 SCL | | ADC (Entrada Analógica) | GP28 / ADC2| **34** |
| **8** | GND | Ground (Tierra) | | AGND (Tierra Analógica) | GND | **33** |
| **9** | GP6 | GPIO / I2C1 SDA | | ADC (Entrada Analógica) | GP27 / ADC1| **32** |
| **10** | GP7 | GPIO / I2C1 SCL | | ADC (Entrada Analógica) | GP26 / ADC0| **31** |
| **11** | GP8 | GPIO / UART1 TX / I2C0 SDA | | System Control (Reset) | RUN | **30** |
| **12** | GP9 | GPIO / UART1 RX / I2C0 SCL | | GPIO | GP22 | **29** |
| **13** | GND | Ground (Tierra) | | Ground (Tierra) | GND | **28** |
| **14** | GP10 | GPIO / I2C1 SDA | | GPIO / I2C0 SCL | GP21 | **27** |
| **15** | GP11 | GPIO / I2C1 SCL | | GPIO / I2C0 SDA | GP20 | **26** |
| **16** | GP12 | GPIO / UART0 TX / I2C0 SDA | | GPIO / SPI0 TX / I2C1 SCL | GP19 | **25** |
| **17** | GP13 | GPIO / UART0 RX / I2C0 SCL | | GPIO / SPI0 SCK / I2C1 SDA| GP18 | **24** |
| **18** | GND | Ground (Tierra) | | Ground (Tierra) | GND | **23** |
| **19** | GP14 | GPIO / I2C1 SDA | | GPIO / SPI0 CSn / I2C0 SCL | GP17 | **22** |
| **20** | GP15 | GPIO / I2C1 SCL | | GPIO / SPI0 RX / I2C0 SDA | GP16 | **21** |

---

## 5. Lenguajes de Programaccion 

Lo especial de esta placa es que está diseñada para dos lenguajes:
- **MicroPython** con Thonny
- **C/C++** con Visual Studio (Extensión Raspberry Pi)

El más rápido obviamente es C/C++ pero si no quieres olvidar Python quédate con MicroPython.

## 6. Comparativa

Para entender la potencia de esta placa quiero que veas esta tabla con la comparación de las versiones:

| Característica Técnica | Raspberry Pi Pico 1 | Raspberry Pi Pico 1 W | Raspberry Pi Pico 2 W |
| :--- | :---: | :---: | :---: |
| **Año de Lanzamiento** | 2021 | 2022 | **2024** |
| **Chip Principal** | RP2040 | RP2040 | **RP2350** |
| **Arquitectura de Núcleos** | 2x Arm Cortex-M0+ | 2x Arm Cortex-M0+ | **2x Arm Cortex-M35P + 2x RISC-V (Hazard3)** |
| **Velocidad del Reloj** | 133 MHz | 133 MHz | **150 MHz** |
| **Memoria RAM Interna** | 264 KB SRAM | 264 KB SRAM | **520 KB SRAM** |
| **Memoria Flash** | 2 MB | 2 MB | **4 MB** |
| **Chip Inalámbrico** | No tiene | Infineon CYW43439 | **Infineon CYW43439** |
| **Seguridad por Hardware** | No tiene | No tiene | **Secure Boot y protección contra fallos eléctricos** |
| **Voltaje de Trabajo** | 3.3V | 3.3V | **3.3V** |

![Imagen de placas](https://www.raspberrypi.com/documentation/microcontrollers/images/pico-1s.png?hash=8881db65b212b342000997d49ec1eb15)
