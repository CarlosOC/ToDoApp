#include "task.h"

// Constructor por defecto
Task::Task() : Nombre(""), Date(""), Descripcion(""), id(0)
{}

// Constructor con parámetros
Task::Task(QString nombre, QString date, QString descripcion, int id)
    : Nombre(nombre), Date(date), Descripcion(descripcion), id(id)
{}

// Getters
QString Task::getNombre() const
{
    return Nombre;
}
QString Task::getDate() const
{
    return Date;
}
QString Task::getDescripcion() const
{
    return Descripcion;
}
int Task::getId() const
{
    return id;
}

// Setters
void Task::setNombre(const QString& nombre)
{
    Nombre = nombre;
}
void Task::setDate(const QString& date)
{
    Date = date;
}
void Task::setDescripcion(const QString& descripcion)
{
    Descripcion = descripcion;
}
void Task::setId(int id)
{
    this->id = id;
}
