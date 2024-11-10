# ToDo Application

**ToDo Application** es una aplicación de gestión de tareas desarrollada en C++ utilizando el framework Qt. La aplicación permite a los usuarios organizar y administrar tareas de manera visual y sencilla, proporcionando un entorno con una interfaz de usuario atractiva. Este repositorio contiene dos versiones de la aplicación, cada una con características y mejoras específicas.

## Descripción General
La aplicación permite la gestión de tareas mediante tarjetas visuales, con una interfaz que facilita la creación, actualización y eliminación de tareas. El diseño de la interfaz se basa en un sistema de tarjetas que organiza las tareas en diferentes estados. La personalización de estilos se realiza a través de archivos CSS, permitiendo modificar los colores y la apariencia general de la aplicación.

## Características Principales

- **Gestión de tareas**: Crear, actualizar, y eliminar tareas.
- **Estados de tareas (disponible en la versión 2.0)**:
  - En Espera
  - En Proceso
  - Finalizada
  - Cancelada
- **Interfaz de usuario personalizada**: Tarjetas estilizadas para mejorar la experiencia visual.
- **Estilización CSS**: Colores y diseño personalizables mediante archivos CSS.

### [Versión 1.0](./src/V1.0/README.md)
La **Versión 1.0** es la primera iteración de la aplicación ToDo. Incluye funcionalidades básicas de gestión de tareas:
- **Añadir y eliminar tareas**: Los usuarios pueden crear nuevas tareas y eliminarlas de la lista.
- **Tarjetas básicas**: Cada tarea se muestra en una tarjeta que incluye el título, descripción y un botón para eliminarla.
- **Estilización básica**: Se utiliza un archivo CSS (style_Generic.css) para definir los colores y el diseño de las tarjetas de tareas.
#### Capturas de Pantalla de la Versión 1.0
| **Aplicacion** | **Nueva Tarea** | **Tarea** |
|---|---|---|
| ![Aplicacion](https://github.com/CarlosOC/ToDoApp/blob/main/imagenes/V1.0/Aplicacion.png) | ![Nueva_Tarea](https://github.com/CarlosOC/ToDoApp/blob/main/imagenes/V1.0/NuevaTarea.png) | ![Tarea](https://github.com/CarlosOC/ToDoApp/blob/main/imagenes/V1.0/Tarea.png) |

### [Versión 2.0](./src/V2.0/README.md)

La **Versión 2.0** introduce nuevas características, entre ellas la capacidad de clasificar tareas en diferentes estados y una interfaz de usuario más estilizada:
- **Gestión avanzada de tareas**: Los usuarios pueden actualizar el estado de cada tarea (En Espera, En Proceso, Finalizada, Cancelada).
- **Tarjetas con estados**: Las tarjetas de tareas incluyen botones para cambiar su estado.
- **Personalización de estilos**: Las tarjetas se pueden personalizar en cuanto a colores y diseño mediante un archivo CSS más completo.
- **Organización de tareas**: Las tareas se agrupan automáticamente por estado y el diseño de las tarjetas se adapta a cada uno de ellos.

#### Capturas de Pantalla de la Versión 2.0
| **Tareas Realizandose** | **Tareas en Espera** | **Tareas Finalizadas** | **Tareas Canceladas** |
|---|---|---|---|
| ![Tareas_Realizandose](https://github.com/CarlosOC/ToDoApp/blob/main/imagenes/V2.0/Aplicacion_Realizandose.png) | ![Tareas_EnEspera](https://github.com/CarlosOC/ToDoApp/blob/main/imagenes/V2.0/Aplicacion_EnEspera.png) | ![Tareas_Finalizadas](https://github.com/CarlosOC/ToDoApp/blob/main/imagenes/V2.0/Aplicacion_Finalizada.png) | ![Tareas_Canceladas](https://github.com/CarlosOC/ToDoApp/blob/main/imagenes/V2.0/Aplicacion_Cancelada.png) |
## Requisitos

- **Qt Framework**: Versión 5.15 o superior.
- **C++ Compiler**: Compatible con el proyecto Qt.
- **Sistema Operativo**: Windows, macOS o Linux.

## Instalación

1. **Clonar el repositorio**:
   ```bash
   git clone https://github.com/tu-usuario/ToDoListApp.git
   cd ToDoListApp
2. **Abrir el proyecto en Qt Creator**:
- Abre Qt Creator.
- Selecciona "Abrir proyecto" y navega hasta el archivo .pro en el directorio del proyecto clonado.
3. **Compilar y Ejecutar**:
- Compila y ejecuta el proyecto desde Qt Creator.

## Personalización de Estilos
Ambas versiones utilizan archivos CSS para personalizar los estilos de la aplicación. Puedes editar los archivos style_Generic.css y style.css (en la versión 2.0) para ajustar los colores y el diseño de los elementos visuales de las tarjetas.

## Contribuciones
Las contribuciones son bienvenidas. Si deseas mejorar la funcionalidad o añadir nuevas características, sigue estos pasos:
- Haz un fork del repositorio.
- Crea una nueva rama (git checkout -b feature/NuevaCaracteristica).
- Haz commit de tus cambios (git commit -am 'Agrega nueva característica').
- Haz push a la rama (git push origin feature/NuevaCaracteristica).
- Abre un Pull Request.

## Estructura del Proyecto

ToDoListApp/
├── src/                     
│   ├── V1.0/                # Versión 1.0 del proyecto
│   │     ├── README.md      # Descripción de la versión 1.0
│   │     ├── ToDoApps.pro   # Archivo de proyecto para Qt Creator (versión 1.0)
│   │     ├── main.cpp       # Archivo principal de la aplicación (versión 1.0)
│   │     ├── recursos.qrc   # Recursos Qt (imágenes, iconos, etc.)
│   │     ├── style_Generic.css # Estilos CSS generales para la interfaz
│   │     ├── task.cpp       # Implementación de la clase Task (versión 1.0)
│   │     ├── task.h         # Definición de la clase Task
│   │     ├── todoapps.cpp   # Implementación de la clase ToDoApp (versión 1.0)
│   │     ├── todoapps.h     # Definición de la clase ToDoApp
│   │     └── todoapps.ui    # Archivo de interfaz gráfica de usuario (versión 1.0)
│   └── V2.0/                # Versión 2.0 del proyecto
│         ├── README.md      # Descripción de la versión 2.0
│         ├── ToDoList.pro   # Archivo de proyecto para Qt Creator (versión 2.0)
│         ├── listatarea.cpp # Implementación de la clase ListaTarea (versión 2.0)
│         ├── listatarea.h   # Definición de la clase ListaTarea
│         ├── main.cpp       # Archivo principal de la aplicación (versión 2.0)
│         ├── resource.qrc   # Recursos Qt (imágenes, iconos, etc.) para la versión 2.0
│         ├── tarea.cpp      # Implementación de la clase Tarea (versión 2.0)
│         ├── tarea.h        # Definición de la clase Tarea
│         ├── todolist.cpp   # Implementación de la clase ToDoList (versión 2.0)
│         ├── todolist.h     # Definición de la clase ToDoList
│         └── todolist.ui    # Archivo de interfaz gráfica de usuario (versión 2.0)
└── README.md               # Descripción general del proyecto   
#### Descripción de las versiones:
  - **V1.0**: *Esta versión contiene la implementación inicial de la aplicación ToDo. Usa una estructura más simple y un diseño básico, con una interfaz gráfica que muestra las tareas con botones para gestionarlas.*
  - **V2.0**: *Esta versión incluye mejoras en la estructura del código, la interfaz y la funcionalidad. Se introducen nuevas clases como ListaTarea, que gestionan la colección de tareas y sus estados, y una interfaz más estilizada con un sistema de tarjetas.*
## Licencia
Este proyecto está licenciado bajo la Licencia MIT. Consulta el archivo LICENSE para más detalles.

## Contacto
Si tienes alguna pregunta o sugerencia, no dudes en ponerte en contacto conmigo:
- Correo electrónico: carlosoviedolr@gmail.com
- Linkedin: [https://www.linkedin.com/in/carlosnicolasoviedocodigoni/]
¡Espero que disfrutes trabajando en estos ejercicios tanto como yo disfruto enseñándolos!

Happy coding! 🚀
