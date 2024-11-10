#include "tarea.h"

// Constructor
Tarea::Tarea(int id, const QString &nombre, const QString &fecha, const QString &descripcion, Estado estado, const QString color)
    : id(id), nombre(nombre), fecha(fecha), descripcion(descripcion), estado(estado), color(color) {}

// Getters
int Tarea::getId() const { return id; }
QString Tarea::getNombre() const { return nombre; }
QString Tarea::getFecha() const { return fecha; }
QString Tarea::getDescripcion() const { return descripcion; }
Tarea::Estado Tarea::getEstado() const { return estado; }
QString Tarea::getColor()const { return color; }

// Convertir el estado a un QString
QString Tarea::getEstadoString() const {
    switch (estado) {
    case EnEspera: return "En Espera";
    case Realizandose: return "Realizándose";
    case Terminada: return "Terminada";
    case Cancelada: return "Cancelada";
    default: return "Desconocido";
    }
}

// Setters
void Tarea::setId(int newId) { id = newId; }
void Tarea::setNombre(const QString &newNombre) { nombre = newNombre; }
void Tarea::setFecha(const QString &newFecha) { fecha = newFecha; }
void Tarea::setDescripcion(const QString &newDescripcion) { descripcion = newDescripcion; }
void Tarea::setEstado(Estado newEstado) { estado = newEstado; }
void Tarea::setColor(const QString &newColor){  color=newColor; }

QStringList Tarea::obtenerEstados()
{
    return QStringList() << "En Espera" << "Realizándose" << "Terminada" << "Cancelada";
}
