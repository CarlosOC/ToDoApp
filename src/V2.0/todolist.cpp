#include "todolist.h"
#include "ui_todolist.h"

ToDoList::ToDoList(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToDoList)
{
    ui->setupUi(this);
    fechaActual = QDateTime::currentDateTime();
    ui->label_time->setText(fechaActual.toString());
    connect(ui->pushButton_AgregarTarea, &QPushButton::clicked, this, &ToDoList::AgregarNuevaTarea);
    connect(ui->pushButton_Cancelar, &QPushButton::clicked, this, &ToDoList::LimpiarEntradas);
    ui->comboBox_estado->addItems( TareaEstados);
    LimpiarEntradas();
    initStylesheet(":/resource/style/style.css");

}
ToDoList::~ToDoList()
{
    delete ui;
}

void ToDoList::AgregarNuevaTarea()
{
  int id;
  int randomVal;
  QVector<QString> colors = { "rgba(66, 165, 245,1.0)",
                              "rgba(41, 182, 246,1.0)",
                              "rgba(38, 198, 218,1.0)",
                              "rgba(38, 166, 154,1.0)",
                              "rgba(102, 187, 106,1.0)",
                              "rgba(156, 204, 101,1.0)",
                              "rgba(212, 225, 87,1.0)",
                              "rgba(255, 238, 88,1.0)",
                              "rgba(255, 202, 40,1.0)",
                              "rgba(255, 167, 38,1.0)"};
  randomVal = (((rand() % 50) % 100) % (colors.size() - 1));
  id = TareasListadas.getNumeroTareas();
  Tarea NuevaTarea(id+1, ui->lineEdit_nombreTarea->text(), fechaActual.toString(), ui->plainTextEdit_descripcion->toPlainText(), Tarea::EnEspera,colors[randomVal]);
  switch (ui->comboBox_estado->currentIndex())
  {
  case 0:
       NuevaTarea.setEstado(Tarea::EnEspera);
      break;
  case 1:
      NuevaTarea.setEstado(Tarea::Realizandose);
       break;
  case 2:
       NuevaTarea.setEstado(Tarea::Terminada);
        break;
  case 3:
        NuevaTarea.setEstado(Tarea::Cancelada);
        break;
  default:

       break;
  }

   // Agregar Tareas a la Lista
  TareasListadas.agregarTarea(NuevaTarea);
  LimpiarEntradas();
  ActualizarListados();
}
void ToDoList::LimpiarEntradas()
{
  ui->label_time->setText(fechaActual.toString());
  ui->lineEdit_nombreTarea->setText("Introduzca el nombre");
  ui->plainTextEdit_descripcion->setPlainText("Escriba la Descripcion de la Tarea");
}

void ToDoList::ActualizarListados()
{
  ListaTarea  TareasEnEspera        = TareasListadas.obtenerTareasPorEstado(Tarea::EnEspera);
  ListaTarea  TareasRealizandose    = TareasListadas.obtenerTareasPorEstado(Tarea::Realizandose);
  ListaTarea  TareasFinalizadas     = TareasListadas.obtenerTareasPorEstado(Tarea::Terminada);
  ListaTarea  TareasCanceladas      = TareasListadas.obtenerTareasPorEstado(Tarea::Cancelada);

  QVBoxLayout* layoutEnEspera       = qobject_cast<QVBoxLayout*>(ui->AllNewTareasEnEspera->layout());
  QVBoxLayout* layoutEnProceso      = qobject_cast<QVBoxLayout*>(ui->AllNewTareasEnProceso->layout());
  QVBoxLayout* layoutCanceladas     = qobject_cast<QVBoxLayout*>(ui->AllNewTareasCanceladas->layout());
  QVBoxLayout* layoutFinalizadas    = qobject_cast<QVBoxLayout*>(ui->AllNewTareasFinalizadas->layout());

  // TAREAS EN ESPERA
  limpiarLayout(layoutEnEspera);
  for (int i = 0; i < TareasEnEspera.obtenerCantidadTareas(); ++i)
  {
      Tarea tarea = TareasEnEspera.obtenerTarea(i);
      AgregarTareaCard(layoutEnEspera, tarea,"TareasEnEspera");
  }
  // TAREAS REALIZANDOCE (EN PROCESO)
  limpiarLayout(layoutEnProceso);
  for (int i = 0; i < TareasRealizandose.obtenerCantidadTareas(); ++i)
  {
      Tarea tarea = TareasRealizandose.obtenerTarea(i);
      AgregarTareaCard(layoutEnProceso, tarea,"TareasRealizandose");
  }
    // TAREAS CANCELADAS
  limpiarLayout(layoutCanceladas);
  for (int i = 0; i < TareasCanceladas.obtenerCantidadTareas(); ++i)
  {
      Tarea tarea = TareasCanceladas.obtenerTarea(i);
      AgregarTareaCard(layoutCanceladas, tarea,"TareasCanceladas");

  }
  // TAREAS FINALIZADAS
  limpiarLayout(layoutFinalizadas);
  for (int i = 0; i < TareasFinalizadas.obtenerCantidadTareas(); ++i)
  {
      Tarea tarea = TareasFinalizadas.obtenerTarea(i);
      AgregarTareaCard(layoutFinalizadas, tarea,"TareasFinalizadas");

  }

}

void ToDoList::limpiarLayout(QLayout* layout)
{
  if (layout == nullptr) return;

  while (QLayoutItem* item = layout->takeAt(0))
  {

    if (QWidget* widget = item->widget() )
    {
        qDebug() <<"widget: "<< widget;
        widget->deleteLater();  // Elimina el widget de la interfaz
        delete item;  // Elimina el item del layout
    }
  }
   layout->addItem(new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding));
}


void ToDoList::AgregarTareaCard(QVBoxLayout* layoutEnEspera, Tarea tarea, QString TipoTarea)
{
   // Crea el contenedor principal (Frame) para la tarjeta
   QFrame* Hframe = new QFrame();
   Hframe->setFrameStyle(QFrame::StyledPanel);
   QHBoxLayout* newTaskLayout = new QHBoxLayout(Hframe);
   Hframe->setLayout(newTaskLayout);

   // Crea otro Frame vertical para los detalles de la tarea
   QFrame* Vframe = new QFrame();
   QVBoxLayout* taskDetails = new QVBoxLayout(Vframe);
   Vframe->setLayout(taskDetails);

   // Añade los widgets de detalles de la tarea (título, nombre, fecha, descripción)
   QLabel* titlelabel = new QLabel(tr("#%1").arg(tarea.getId()));
   taskDetails->addWidget(titlelabel);
   QLabel* tasklabel = new QLabel(tarea.getNombre());
   taskDetails->addWidget(tasklabel);
   QLabel* datelabel = new QLabel(tarea.getFecha());
   taskDetails->addWidget(datelabel);

   // Inserta el Frame de detalles en el layout horizontal
   newTaskLayout->insertWidget(0, Vframe);

   // Añade un espaciador para separar los elementos en el layout horizontal de la tarjeta
   QSpacerItem* spacer = new QSpacerItem(100, 100, QSizePolicy::Expanding, QSizePolicy::Minimum);
   newTaskLayout->insertSpacerItem(1, spacer);

   // Establece estilos personalizados
   Hframe->setObjectName("NewTaskHf");
   Vframe->setObjectName("NewTaskVf");
   Hframe->setStyleSheet("#NewTaskHf { border-radius: 10px; border: 1px solid black; background-color: " + tarea.getColor() + "; }");
   Vframe->setStyleSheet("#NewTaskVf { border-radius: 10px; background-color: " + tarea.getColor() + "; }");
   tasklabel->setObjectName("TaskName");
   tasklabel->setStyleSheet("#TaskName { font: bold 11pt black 'Verdana'; background-color: " + tarea.getColor() + "; }");
   titlelabel->setObjectName("TitleLabel");
   titlelabel->setStyleSheet("#TitleLabel { font: bold 11pt black 'Verdana'; background-color: " + tarea.getColor() + "; }");
   datelabel->setObjectName("DateLabel");
   datelabel->setStyleSheet("#DateLabel { font: bold 11pt black 'Verdana'; background-color: " + tarea.getColor() + "; }");

   // Crear botones específicos según el tipo de tarea
   QFrame* botonesFrame = crearBotonesCard(Hframe, tarea, TipoTarea);
   botonesFrame->setObjectName("BotonesFrame");
   botonesFrame->setStyleSheet("#BotonesFrame { background-color: " + tarea.getColor() + "; }");
   newTaskLayout->insertWidget(2, botonesFrame);

   // Verificar si hay un spacer en el layout
   QSpacerItem* verticalSpacer = nullptr;
   for (int i = 0; i < layoutEnEspera->count(); ++i) {
    if (QSpacerItem* item = dynamic_cast<QSpacerItem*>(layoutEnEspera->itemAt(i))) {
        verticalSpacer = item;
        break;
    }
   }

   // Si existe el spacer, insertar la tarjeta antes del spacer
   if (verticalSpacer) {
    int index = layoutEnEspera->indexOf(verticalSpacer);
    layoutEnEspera->insertWidget(index, Hframe);
   } else {
    // Si no hay spacer, insertar la tarjeta y luego añadir el spacer al final
    layoutEnEspera->addWidget(Hframe);
    layoutEnEspera->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum));
   }

   initStylesheet(":/resource/style/style.css");
}

QFrame* ToDoList::crearBotonesCard(QFrame* Hframe, const Tarea& tarea, QString Tipo)
{
  // Crea un contenedor vertical para los dos botones
  QFrame* VframeBotones = new QFrame();
  QVBoxLayout* layoutBotones = new QVBoxLayout(VframeBotones);
  VframeBotones->setLayout(layoutBotones);

  // Si la tarea está en proceso, creamos los botones "Finalizar" y "Cancelar"
 if (Tipo=="TareasEnEspera")
  {
      // Botón "Finalizar"
      QPushButton* enProcesoBtn = crearBotonTarea(Hframe, tarea, "TareaenProceso");
      // Botón "Cancelar"
      QPushButton* cancelarBtn = crearBotonTarea(Hframe, tarea, "TareaCancelada");
      // Añadir los botones al layout vertical
      layoutBotones->addWidget(enProcesoBtn);
      layoutBotones->addWidget(cancelarBtn);

 } else if(Tipo=="TareasRealizandose")
 {
      // Botón "Finalizar"
      QPushButton* enProcesoBtn = crearBotonTarea(Hframe, tarea, "TareaTerminada");
      // Botón "Cancelar"
      QPushButton* cancelarBtn = crearBotonTarea(Hframe, tarea, "TareaCancelada");
      // Añadir los botones al layout vertical
      layoutBotones->addWidget(enProcesoBtn);
      layoutBotones->addWidget(cancelarBtn);
 }

 else if (Tipo=="TareasCanceladas")
      {
      // Si la tarea no está en proceso, solo creamos el botón "En Proceso"
      QPushButton* enProcesoBtn = crearBotonTarea(Hframe, tarea, "EliminarTarea");  // Botón "Eliminar"

      // Añadir el botón al layout vertical
      layoutBotones->addWidget(enProcesoBtn);
  } else if (Tipo=="TareasFinalizadas")
 {
      // Si la tarea no está en proceso, solo creamos el botón "En Proceso"
      QPushButton* enProcesoBtn = crearBotonTarea(Hframe, tarea, "EliminarTarea");  // Botón "Eliminar"

      // Añadir el botón al layout vertical
      layoutBotones->addWidget(enProcesoBtn);
 }

  return VframeBotones;
}

QPushButton* ToDoList::crearBotonTarea(QFrame* Hframe, const Tarea& tarea, QString Tipo)
{

  QPushButton* botonTarea = new QPushButton();
  // Conectar al slot correspondiente basado en el estado de la tarea
  if (Tipo=="TareaTerminada")
  {
      botonTarea->setText("Terminar Tarea");
      botonTarea->setObjectName("TerminarBtn");
      connect(botonTarea, SIGNAL(clicked()), this, SLOT(TerminarTarea()));
      botonTarea->setStyleSheet(
          QString("#TerminarBtn {   color: white; border-radius: 4px; padding: 5px 10px;background-color: #2A9D8F; border: 1px solid #207567; } "
                  "#TerminarBtn:hover {background-color: #207567; }")
                );


   }
  else if (Tipo=="TareaenProceso")
  {
    botonTarea->setText("Realizandose");
    botonTarea->setObjectName("EnProcesoBtn");
    connect(botonTarea, SIGNAL(clicked()), this,SLOT(TareaRealizandose())  );
    botonTarea->setStyleSheet(
        QString("#EnProcesoBtn {   color: white; border-radius: 4px; padding: 5px 10px;    background-color: #e76f51;  border: 1px solid #b04532; } "
                "#EnProcesoBtn:hover {background-color: #b04532; }")
        );
  } else if (Tipo=="TareaEnEspera")
  {
    botonTarea->setText("EnEspera");
    botonTarea->setObjectName("EnEsperaBtn");
    connect(botonTarea, SIGNAL(clicked()), this,SLOT(TareaenEspera()) );
    botonTarea->setStyleSheet(
        QString("#EnEsperaBtn {   color: white; border-radius: 4px; padding: 5px 10px;background-color: #2A9D8F; border: 1px solid #207567; } "
                "#EnEsperaBtn:hover {background-color: #207567; }")
        );
  }else if (Tipo=="TareaCancelada")
  {
    botonTarea->setText("Cancelar");
    botonTarea->setObjectName("CancelarBtn");
    connect(botonTarea, SIGNAL(clicked()), this,SLOT(CancelarTarea()));
    botonTarea->setStyleSheet(
        QString("#CancelarBtn {   color: white; border-radius: 4px; padding: 5px 10px;background-color: #2A9D8F; border: 1px solid #207567; } "
                "#CancelarBtn:hover {background-color: #207567; }")
        );
  }else if (Tipo=="EliminarTarea")
  {
    botonTarea->setText("Eliminar");
    botonTarea->setObjectName("EliminarBtn");
    connect(botonTarea, SIGNAL(clicked()), this, SLOT(BorrarTarea()));
    botonTarea->setStyleSheet(
        QString("#EliminarBtn {   color: white; border-radius: 4px; padding: 5px 10px;background-color: #f4a261; border: 1px solid #c97d4e; } "
                "#EliminarBtn:hover {background-color: #c97d4e; }")
        );
  }

  // Almacena el widget actual y el ID de la tarea en las propiedades del botón
  botonTarea->setProperty("CurrentTask", QVariant(QVariant::fromValue<QFrame*>(Hframe)));
  botonTarea->setProperty("TareaID", tarea.getId());

  // Establece el nombre y los estilos personalizados del botón

  /*botonTarea->setStyleSheet(
  QString("#%1 { color: white; background-color: #ff2264; border-color: #b91043; } "
              "#%1:hover { background-color: #b91043; border-color: #ff2264; }")
          .arg(botonTarea->objectName()));
*/
  return botonTarea;
}

void ToDoList::TareaenEspera()
{
  ModificarEstadoTarea(0);

}

void ToDoList::TareaRealizandose()
{
  ModificarEstadoTarea(1);

}

void ToDoList::TerminarTarea()
{
  ModificarEstadoTarea(2);

}

void ToDoList::CancelarTarea()
{
  ModificarEstadoTarea(3);

}

void ToDoList::ModificarEstadoTarea(int nuevoEstado)
{
  int TareaID;
  // Obtiene el botón que activó la señal
  QPushButton* fromButton = (QPushButton*)sender();
  // Obtiene el widget asociado a ese botón
  QFrame* taskHBox = qvariant_cast<QFrame*>(fromButton->property("CurrentTask"));
  TareaID = fromButton->property("TareaID").toInt();
  switch (nuevoEstado)
  {
  case 0:
    TareasListadas.modificarEstado(TareaID,Tarea::EnEspera);
    break;
  case 1:
    TareasListadas.modificarEstado(TareaID,Tarea::Realizandose);
    break;
  case 2:
    TareasListadas.modificarEstado(TareaID,Tarea::Terminada);
    break;
  case 3:
    TareasListadas.modificarEstado(TareaID,Tarea::Cancelada);
    break;
  }

  // Elimina el widget de la interfaz
  taskHBox->deleteLater();
  delete taskHBox;
ActualizarListados();
}

void ToDoList::BorrarTarea()
{
  int TareaID;
  // Obtiene el botón que activó la señal
  QPushButton* fromButton = (QPushButton*)sender();
  // Obtiene el widget asociado a ese botón
  QFrame* taskHBox = qvariant_cast<QFrame*>(fromButton->property("CurrentTask"));
  TareaID = fromButton->property("TareaID").toInt();
  TareasListadas.eliminarTarea(TareaID);
  // Elimina el widget de la interfaz
  taskHBox->deleteLater();
  delete taskHBox;

}

void ToDoList::initStylesheet(QString ruta)
{
   // Carga y aplica un archivo CSS de estilo para personalizar la apariencia de la aplicación
    QFile style(ruta);
    bool ok = style.open(QFile::ReadOnly);
    qDebug()<<ok; // Verifica si el archivo CSS se abrió correctamente
    QString s = QString::fromLatin1(style.readAll());
    setStyleSheet(s); // Aplica el estilo a la aplicación
}
