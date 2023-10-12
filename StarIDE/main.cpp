#include <QApplication>   // Incluimos la biblioteca para la aplicación Qt
#include <QMainWindow>    // Incluimos la biblioteca para la ventana principal
#include <QShortcut>      // Necesario para atajos de teclado
#include <QDesktopWidget> // Necesario para obtener la información del tamaño de la pantalla

// Función principal
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("StarIDE");
    int minWidth = 800;
    int minHeight = 600;
    mainWindow.setMinimumSize(minWidth, minHeight);
    mainWindow.showMaximized();
    mainWindow.show();
    return app.exec();
}


