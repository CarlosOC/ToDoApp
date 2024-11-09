/*
Este archivo define una clase que hereda de QWidget, lo que permite que la interfaz de usuario sea manejada como un widget de Qt.
Se utiliza la macro Q_OBJECT, necesaria para las señales y slots en Qt.
Se definen dos slots (SlotAddNewTask y SlotDeleteTask), los cuales son métodos que se ejecutan en respuesta a eventos como clics de botones.
La señal SignalAddNewTask es un mecanismo para comunicar la adición de nuevas tareas a otras clases si es necesario.
*/

#ifndef TODOAPPS_H
#define TODOAPPS_H

#include <QWidget>
#include <QDate>
#include <QDir>
#include "QDebug"
#include "task.h"
QT_BEGIN_NAMESPACE
namespace Ui { class ToDoApps; }
QT_END_NAMESPACE

class ToDoApps : public QWidget
{
    Q_OBJECT
public:
    // Constructor: Inicializa el objeto ToDoApps
    ToDoApps(QWidget *parent = nullptr);

    // Destructor: Libera memoria usada por ToDoApps
    ~ToDoApps();

    // Inicializa las hojas de estilo para la aplicación
    void initStylesheet();

    // Crea una nueva tarea
    void createNewTask(QString taskName, QString date);

public slots:
    // Slot para añadir una nueva tarea
    void SlotAddNewTask();

    // Slot para eliminar una tarea
    void SlotDeleteTask();

signals:
    // Señal para notificar cuando se añade una nueva tarea (útil si se desea conectar con otra clase)
    void SignalAddNewTask(QString taskName, QString date);

private:
    Ui::ToDoApps *ui; // Puntero a la interfaz de usuario (ui) generada por Qt Designer
    QList<Task> Tasks;  // Lista de tareas
};

#endif // TODOAPPS_H
