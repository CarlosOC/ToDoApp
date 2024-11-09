#ifndef TASK_H
#define TASK_H
#include "QString"

class Task
{

private:
    QString Nombre;
    QString Date;
    QString Descripcion;
    int id;

public:
    Task(); // Constructor por defecto
    Task(QString nombre, QString date, QString descripcion, int id); // Constructor con parámetros

    // Getters
    QString getNombre() const;
    QString getDate() const;
    QString getDescripcion() const;
    int getId() const;

    // Setters
    void setNombre(const QString& nombre);
    void setDate(const QString& date);
    void setDescripcion(const QString& descripcion);
    void setId(int id);
};

#endif // TASK_H
