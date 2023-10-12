#include <QApplication>   // Incluimos la biblioteca para la aplicación Qt
#include <QMainWindow>    // Incluimos la biblioteca para la ventana principal
#include <QAction>        // Incluimos la biblioteca para acciones
#include <QTextEdit>      // Incluimos la biblioteca para el editor de texto
#include <QDockWidget>    // Incluimos la biblioteca para el área de widgets flotantes
#include <QTabWidget>     // Incluimos la biblioteca para pestañas
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

    QTextEdit *textEdit = new QTextEdit(&mainWindow);
    mainWindow.setCentralWidget(textEdit);

    QDockWidget *fileExplorer = new QDockWidget("Explorer", &mainWindow);
    QTabWidget *fileTabs = new QTabWidget(&mainWindow);
    fileExplorer->setWidget(fileTabs);
    fileExplorer->setFeatures(QDockWidget::NoDockWidgetFeatures);
    mainWindow.addDockWidget(Qt::RightDockWidgetArea, fileExplorer);

    QAction *toggleFileExplorerAction = fileExplorer->toggleViewAction();
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_B), &mainWindow);
    QObject::connect(shortcut, &QShortcut::activated, toggleFileExplorerAction, &QAction::trigger);

    mainWindow.addAction(toggleFileExplorerAction);
    mainWindow.show();

    return app.exec();
}

