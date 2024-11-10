#include "listatarea.h"

// Constructor
ListaTarea::ListaTarea() {}

// Agregar tarea a la lista
void ListaTarea::agregarTarea(const Tarea &tarea) {
    listaTareas.append(tarea);
    NumeroTareas=NumeroTareas+1;
}

// Modificar el estado de una tarea dada su ID
void ListaTarea::modificarEstado(int id, Tarea::Estado nuevoEstado) {
    for (int i = 0; i < listaTareas.size(); ++i) {
        if (listaTareas[i].getId() == id) {
            listaTareas[i].setEstado(nuevoEstado);
            break;
        }
    }
}

// Modificar la posición de una tarea dentro de la lista
bool ListaTarea::modificarPosicion(int id, int nuevaPosicion) {
    for (int i = 0; i < listaTareas.size(); ++i) {
        if (listaTareas[i].getId() == id) {
            // Asegurarse de que la nueva posición esté dentro del rango
            if (nuevaPosicion >= 0 && nuevaPosicion < listaTareas.size()) {
                Tarea tareaTemp = listaTareas[i];
                listaTareas.removeAt(i);
                listaTareas.insert(nuevaPosicion, tareaTemp);
                return true; // Éxito
            }
            return false; // Posición fuera de rango
        }
    }
    return false; // ID no encontrado
}
// Eliminar Tarea
bool ListaTarea::eliminarTarea(int id)
{
    int i;
    for (i = 0; i <= listaTareas.size(); i++)
    {
        if (listaTareas[i].getId() == id)
        {
            listaTareas.removeAt(i);
            return true; // Éxito
        }
    }
    return false; // ID no encontrado
}


// Obtener tarea por índice
Tarea ListaTarea::obtenerTarea(int index) const {
    if (index >= 0 && index < listaTareas.size()) {
        return listaTareas[index];
    }
    return Tarea(0, "", "", "", Tarea::EnEspera,""); // Retorna una tarea vacía si el índice no es válido
}

// Obtener la cantidad de tareas en la lista
int ListaTarea::obtenerCantidadTareas() const {
    return listaTareas.size();
}

// Obtener una representación de la lista de tareas como un QString
QString ListaTarea::obtenerListaTareas() const {
    QString lista;
    for (const Tarea &tarea : listaTareas) {
        lista += QString("ID: %1, Nombre: %2, Estado: %3, Descripcion: %4\n")
                     .arg(tarea.getId())
                     .arg(tarea.getNombre())
                     .arg(tarea.getEstadoString())
                     .arg(tarea.getDescripcion());
    }
    return lista;
}

ListaTarea ListaTarea::obtenerTareasPorEstado(Tarea::Estado estado) const
{
    ListaTarea listaFiltrada;
    for (const Tarea &tarea : listaTareas)
    {
        if (tarea.getEstado() == estado) {
            listaFiltrada.agregarTarea(tarea);
        }
    }
    return listaFiltrada;
}

int ListaTarea::getNumeroTareas()
{
    return NumeroTareas;
}
