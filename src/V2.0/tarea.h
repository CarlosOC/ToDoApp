#ifndef TAREA_H
#define TAREA_H

#include <QString>
#include <QDate>

class Tarea {
public:
    enum Estado {
        EnEspera = 0,
        Realizandose,
        Terminada,
        Cancelada
    };

private:
    int id;
    QString nombre;
    QString fecha;
    QString descripcion;
    Estado estado; //  es un enum
    QString color;

public:
    // Constructor
    Tarea(int id, const QString &nombre, const QString &fecha, const QString &descripcion, Estado estado, const QString color);

    // Getters
    int     getId() const;
    QString getNombre() const;
    QString getFecha() const;
    QString getDescripcion() const;
    Estado  getEstado() const;
    QString getEstadoString() const;
    QString getColor()const;
    static QStringList obtenerEstados();
    // Setters
    void setId(int newId);
    void setNombre(const QString &newNombre);
    void setFecha(const QString &newFecha);
    void setDescripcion(const QString &newDescripcion);
    void setEstado(Estado newEstado);
    void setColor(const QString &newColor);
};

#endif // TAREA_H
