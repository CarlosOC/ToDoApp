/*
El constructor ToDoApps inicializa la interfaz de usuario y conecta el botón de añadir tareas con su correspondiente slot.
El método initStylesheet() carga un archivo de estilo CSS para personalizar la apariencia de los widgets.
SlotAddNewTask() captura el texto del campo de entrada y llama a createNewTask() para añadir una nueva tarea a la lista.
El método createNewTask() crea una estructura de widgets para representar la tarea, incluyendo un botón de eliminación, un espaciador y las etiquetas de tarea y fecha.
SlotDeleteTask() elimina la tarea de la lista cuando el botón de borrar es pulsado.
 */
#include "todoapps.h"
#include "ui_todoapps.h"

ToDoApps::ToDoApps(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ToDoApps)
{
    // Inicializa la interfaz de usuario
    ui->setupUi(this);

    // Inicializa las hojas de estilo
    initStylesheet();

    // Conecta el botón "Añadir nueva tarea" con el slot que la añade
    connect(ui->AddNewBtn, SIGNAL(clicked()), this, SLOT(SlotAddNewTask()));
    // Eliminamos la referencia realizada en el front (todoapps.ui)
    ui->NewTask->deleteLater();

    // Configura un texto inicial en el campo de entrada de tarea y fecha
    ui->NewTaskLineEdit->setText("Introduzca la Tarea ");
    ui->NewDateText->setText(QDate::currentDate().toString("d-M-yyyy"));
}

ToDoApps::~ToDoApps()
{
     // Libera la memoria de la interfaz de usuario
    delete ui;
}

void ToDoApps::initStylesheet() {

    // Carga y aplica un archivo CSS de estilo para personalizar la apariencia de la aplicación
    QFile style(":/style/style_Generic.css");
    bool ok = style.open(QFile::ReadOnly);
    qDebug()<<ok; // Verifica si el archivo CSS se abrió correctamente
    QString s = QString::fromLatin1(style.readAll());
    setStyleSheet(s); // Aplica el estilo a la aplicación
}


void ToDoApps::SlotAddNewTask() {

    // Obtiene el texto introducido en el campo de tarea
    QString taskName = ui->NewTaskLineEdit->text();
    // Obtiene la fecha actual
    QString date = QDate::currentDate().toString("d-M-yyyy");

    // Crea una nueva tarea con el nombre y la fecha actuales
    createNewTask(taskName, date);

    // This is how to trigger signal
    //emit SignalAddNewTask(taskName, date);

    // Then in other class/widget connect it like
    //ToDoApps* obj;
    //connect(obj, SIGNAL(SignalAddNewTask(QString, QString)), this, SLOT(SlotToSomethingInThatClass()));

}


// This is the part where widget created using code / the reference is in .ui file
void ToDoApps::createNewTask(QString taskName, QString date) {

    {
        // The hierarchy of this widget will be like this
        /*
            + Hframe (Frame)
                + Vframe (Frame)
                    + titlelabel (Label)
                    + tasklabel (Label)
                    + datelabel (Label)
                + spacer (Horizontal spacer)
                + deleteBtn (PushButton)
        */
    }
    Task nuevaTarea;


    QVBoxLayout* vMainLayout = qobject_cast<QVBoxLayout*>(ui->AllNewTasksContents->layout());

    // Crea el contenedor principal (Frame)
    QFrame* Hframe = new QFrame();
    Hframe->setFrameStyle(QFrame::StyledPanel);
    QHBoxLayout* newTask = new QHBoxLayout(Hframe);
    Hframe->setLayout(newTask);

    // Crea otro Frame vertical para los detalles de la tarea
    QFrame* Vframe = new QFrame();
    QVBoxLayout* taskDetails = new QVBoxLayout(Vframe);
    Vframe->setLayout(taskDetails);

    // Añade los widgets de detalles de la tarea (título, nombre, fecha)
    QLabel* titlelabel = new QLabel(tr("Tarea: Nº: %1").arg(vMainLayout->count()));
    taskDetails->addWidget(titlelabel);
    QLabel* tasklabel = new QLabel(taskName);
    taskDetails->addWidget(tasklabel);
    QLabel* datelabel = new QLabel(date);
    taskDetails->addWidget(datelabel);

    // Inserta el Frame de detalles en el layout horizontal
    newTask->insertWidget(0, Vframe);

    // Añade un espaciador para separar los elementos
    QSpacerItem* spacer = new QSpacerItem(100, 100, QSizePolicy::Expanding, QSizePolicy::Minimum);
    newTask->insertSpacerItem(1, spacer);

    // Crea un botón para eliminar la tarea
    QPushButton* deleteBtn = new QPushButton("Borrar");
    newTask->insertWidget(2, deleteBtn);


    // Almacena el widget actual en la propiedad del botón de borrar
    deleteBtn->setProperty("CurrentTask", QVariant(QVariant::fromValue<QFrame*>(Hframe)));
    qDebug()<<"id"<<QVariant(QVariant::fromValue<QFrame*>(Hframe));

    // Añade el widget a la interfaz de usuario
    vMainLayout->insertWidget(vMainLayout->count()-1, Hframe);

    // Conecta el botón de borrar con el slot que elimina la tarea
    connect(deleteBtn, SIGNAL(clicked()), this, SLOT(SlotDeleteTask()));

    // Aplica estilos personalizados a los widgets mediante CSS
    QVector<QString> colors = { "rgba(66, 165, 245,1.0)", "rgba(41, 182, 246,1.0)", "rgba(38, 198, 218,1.0)", "rgba(38, 166, 154,1.0)", "rgba(102, 187, 106,1.0)", "rgba(156, 204, 101,1.0)", "rgba(212, 225, 87,1.0)", "rgba(255, 238, 88,1.0)", "rgba(255, 202, 40,1.0)", "rgba(255, 167, 38,1.0)"};
    int randomVal = (((rand() % 50) % 100) % (colors.size() - 1));

    Hframe->setObjectName("NewTask");
    Hframe->setStyleSheet("#NewTask { border-radius: 10px; border: 1px solid black; background-color: " + colors[randomVal] + "; }");

    tasklabel->setObjectName("TaskName");
   tasklabel->setStyleSheet("#TaskName { font: bold 11pt black 'Verdana'; }");

    deleteBtn->setObjectName("DeleteBtn");
   deleteBtn->setStyleSheet("#DeleteBtn { color: white; background-color: #ff2264; border-color: #b91043; }  #DeleteBtn:hover{ background-color: #b91043; border-color: #ff2264; }");

   // Cargamos la Tarea en la Llista
    nuevaTarea.setNombre(taskName);
    nuevaTarea.setDate(date);
    nuevaTarea.setDescripcion("Descripción por defecto");  // Puedes modificar esto según necesites
    nuevaTarea.setId(vMainLayout->count());  // Asignar un ID basado en el tamaño de la lista

    Tasks.append(nuevaTarea);  // Añadir la tarea a la lista
    qDebug()<<"Tasks "<<Tasks.size();
}


void ToDoApps::SlotDeleteTask() {

    // Obtiene el botón que activó la señal
    QPushButton* fromButton = (QPushButton*)sender();

    // Obtiene el widget asociado a ese botón
    QFrame* taskHBox = qvariant_cast<QFrame*>(fromButton->property("CurrentTask"));

    // Elimina el widget de la interfaz
    taskHBox->deleteLater();
    delete taskHBox;

}
