#include <QApplication>
#include <QMainWindow>
#include <QAction>
#include <QTextEdit>
#include <QDockWidget>
#include <QTabWidget>
#include <QShortcut> // Necesario para atajos de teclado

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("DuskIDE");
    mainWindow.setWindowState(mainWindow.windowState() | Qt::WindowMaximized);

    QTextEdit *textEdit = new QTextEdit(&mainWindow);
    mainWindow.setCentralWidget(textEdit);

    QDockWidget *fileExplorer = new QDockWidget("Explorer", &mainWindow);
    QTabWidget *fileTabs = new QTabWidget(&mainWindow);
    fileExplorer->setWidget(fileTabs);

    // Deshabilitar la capacidad de mover libremente el explorador de archivos
    fileExplorer->setFeatures(QDockWidget::NoDockWidgetFeatures);

    // Cambiamos la ubicación del explorador de archivos a la derecha
    mainWindow.addDockWidget(Qt::RightDockWidgetArea, fileExplorer);

    // Crear una acción para mostrar/ocultar el explorador de archivos
    QAction *toggleFileExplorerAction = fileExplorer->toggleViewAction();

    // Asignar una combinación de teclas (Ctrl + Shift + B) para la acción
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_B), &mainWindow);
    QObject::connect(shortcut, &QShortcut::activated, toggleFileExplorerAction, &QAction::trigger);

    mainWindow.addAction(toggleFileExplorerAction);
    mainWindow.show();
    return app.exec();
}
