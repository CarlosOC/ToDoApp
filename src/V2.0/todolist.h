#ifndef TODOLIST_H
#define TODOLIST_H
#include "listatarea.h"
#include <QWidget>
#include <QDebug>
#include <QDateTimeEdit>
#include <QDir>
#include <QDateTime>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFrame>


QT_BEGIN_NAMESPACE
namespace Ui { class ToDoList; }
QT_END_NAMESPACE

class ToDoList : public QWidget
{
    Q_OBJECT

public:
    ToDoList(QWidget *parent = nullptr);
    ~ToDoList();
private slots:
    QPushButton* crearBotonTarea(QFrame* Hframe, const Tarea& tarea, QString Tipo);
    QFrame* crearBotonesCard(QFrame* Hframe, const Tarea& tarea, QString Tipo);
    void AgregarTareaCard(QVBoxLayout *layoutEnEspera, Tarea tarea, QString TipoTarea);
    void limpiarLayout(QLayout* layout);

public slots:

    void initStylesheet(QString ruta);
    void AgregarNuevaTarea();
    void LimpiarEntradas();
    void ActualizarListados();
    void BorrarTarea();
    void CancelarTarea();
    void ModificarEstadoTarea(int nuevoEstado);
    void TareaenEspera();
    void TareaRealizandose();
    void TerminarTarea();

private:
    Ui::ToDoList *ui;
    QStringList TareaEstados = Tarea::obtenerEstados();
    QDateTime fechaActual;
    ListaTarea TareasListadas;

};
#endif // TODOLIST_H
