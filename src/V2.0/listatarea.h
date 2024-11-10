#ifndef LISTATAREA_H
#define LISTATAREA_H

#include "Tarea.h"
#include <QList>
#include <QString>
#include "QDebug"

class ListaTarea {
private:
    QList<Tarea> listaTareas;
    int NumeroTareas=0;
public:
    // Constructor
    ListaTarea();
public slots:
    // Métodos
    void agregarTarea(const Tarea &tarea);
    void modificarEstado(int id, Tarea::Estado nuevoEstado);
    bool modificarPosicion(int id, int nuevaPosicion);
    bool eliminarTarea(int id);
    Tarea obtenerTarea(int index) const;
    int obtenerCantidadTareas() const;
    QString obtenerListaTareas() const;
    ListaTarea  obtenerTareasPorEstado(Tarea::Estado estado) const;
    int getNumeroTareas();


};

#endif // LISTATAREA_H
