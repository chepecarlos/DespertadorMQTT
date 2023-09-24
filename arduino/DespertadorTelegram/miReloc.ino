#include "RTClib.h"

RTC_DS3231 rtc;
DateTime tiempoActual;


String NombresDia[7] = { "Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };

void configurarRTC() {
  if (!rtc.begin()) {
    Serial.println("No encontrado RTC");
    estado = errorEstado;
  }
  Serial.println("RTC Cargado");
  actualizarRTC();
}


void actualizarRTC() {
  tiempoActual = rtc.now();
}

String fechaActual() {

  int Anno = tiempoActual.year();
  int Mes = tiempoActual.month();
  int Dia = tiempoActual.day();

  String fecha = "";
  if (Dia < 10)
    fecha += "0";
  fecha += Dia;
  fecha += '/';
  if (Mes < 10)
    fecha += "0";
  fecha += Mes;
  fecha += '/';
  fecha += Anno;

  return fecha;
}

String horaActual() {

  int Hora12 = tiempoActual.twelveHour();
  int Minuto = tiempoActual.minute();
  int Segundo = tiempoActual.second();

  String hora = "";
  if (Hora12 < 10)
    hora += "0";
  hora += Hora12;
  hora += ':';
  if (Minuto < 10)
    hora += "0";
  hora += Minuto;
  hora += ':';
  if (Segundo < 10)
    hora += "0";
  hora += Segundo;

  return hora;
}

boolean esTarde() {
  return tiempoActual.isPM();
}

String diaActual() {
  int DiaSemana = tiempoActual.dayOfTheWeek();
  return NombresDia[DiaSemana];
}

int temperaturaActual() {
  return rtc.getTemperature();
}