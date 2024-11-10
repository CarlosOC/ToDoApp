# ToDo Application V2.0
ToDo Application V2.0 es una aplicación de gestión de tareas desarrollada en C++ utilizando el framework Qt. La aplicación permite a los usuarios organizar sus tareas en diferentes estados de progreso y realizar acciones de administración de tareas como crear, actualizar el estado, y eliminar. Este proyecto está diseñado para proporcionar una experiencia visual agradable con tarjetas de tareas estilizadas, utilizando CSS para personalizar los colores y apariencia.

## Características
- **Gestión de tareas**: Crear y eliminar tareas con un solo clic.
- **Estados de tareas**: Cada tarea puede tener uno de los siguientes estados:
-- En Espera
-- En Proceso
-- Finalizada
-- Cancelada
- **Interfaz visual de tarjetas**: Cada tarea se muestra en una "tarjeta" con un diseño estilizado que incluye:
-- Título y Descripción de la tarea
-- Fecha de la tarea
-- Botones de acción para cambiar el estado de la tarea
- **Personalización de colores**: Las tarjetas tienen colores personalizados que mejoran la experiencia visual y permiten diferenciar entre los estados de las tareas.

## Capturas de Pantalla
| **Tareas Realizandose** | **Tareas en Espera** | **Tareas Finalizadas** | **Tareas Canceladas** |
|---|---|---|---|
| ![Tareas_Realizandose](https://github.com/CarlosOC/ToDoApp/blob/main/imagenes/V2.0/Aplicacion_Realizandose.png) | ![Tareas_EnEspera](https://github.com/CarlosOC/ToDoApp/blob/main/imagenes/V2.0/Aplicacion_EnEspera.png) | ![Tareas_Finalizadas](https://github.com/CarlosOC/ToDoApp/blob/main/imagenes/V2.0/Aplicacion_Finalizada.png) | ![Tareas_Canceladas](https://github.com/CarlosOC/ToDoApp/blob/main/imagenes/V2.0/Aplicacion_Cancelada.png) |


## Requisitos
Qt Framework: Versión 5.15 o superior.
Compilador C++ compatible con Qt.
Sistema Operativo: Compatible con Windows, macOS y Linux.
Instalación

## Clonar el repositorio:

git clone https://github.com/tu-usuario/ToDoListApp.git
cd ToDoListApp
Abrir el proyecto en Qt Creator:

Abre Qt Creator.
Selecciona "Abrir proyecto" y navega hasta el archivo .pro en el directorio del proyecto clonado.
Compilar y Ejecutar:

Compila y ejecuta el proyecto desde Qt Creator.

## Uso
Crear una nueva tarea:

Ingresa el nombre, la fecha y selecciona un estado inicial.
La tarea se mostrará en la lista de tareas en el estado correspondiente.

**Actualizar el estado de la tarea**:
Usa los botones En Proceso, Finalizar, o Cancelar para mover la tarea a otro estado.

**Eliminar tarea**:
Cada tarea tiene un botón de eliminación para removerla de la lista.

**Interfaz visual**:
Las tareas se muestran en tarjetas con un diseño estilizado.
Las tarjetas se ordenan automáticamente para que cada tarea se muestre primero, seguida de un espaciador para mantener la estructura del layout.

## Personalización de Estilos
Para modificar los estilos de las tarjetas de tareas y otros elementos de la interfaz, edita el archivo style.css que incluye las siguientes configuraciones de colores:

- **#264653**: Color de fondo general de las tarjetas.
- **#2A9D8F**: Color principal para botones y acciones.
- **#E9C46A**: Color para el estado Hover en los botones.
- **#F4A261**: Color para el botón Eliminar.
- **#E76F51**: Color para el estado Cancelado.

## Contribuciones
Las contribuciones son bienvenidas. Si deseas mejorar la funcionalidad o añadir nuevas características, sigue estos pasos:

Haz un fork del repositorio.
Crea una nueva rama (git checkout -b feature/NuevaCaracteristica).
Haz commit de tus cambios (git commit -am 'Agrega nueva característica').
Haz push a la rama (git push origin feature/NuevaCaracteristica).
Abre un Pull Request.

## Licencia
Este proyecto está licenciado bajo la Licencia MIT. Consulta el archivo LICENSE para más detalles.

## Contacto

Si tienes alguna pregunta o sugerencia, no dudes en ponerte en contacto conmigo:

- Correo electrónico: carlosoviedolr@gmail.com
- Linkedin: [https://www.linkedin.com/in/carlosnicolasoviedocodigoni/]

¡Espero que disfrutes trabajando en estos ejercicios tanto como yo disfruto enseñándolos!

Happy coding! 🚀
