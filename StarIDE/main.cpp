#include <QApplication> // Include the library for Qt application
#include <QMainWindow>  // Include the library for the main window
#include <QAction>      // Include the library for actions
#include <QTextEdit>    // Include the library for the text editor
#include <QDockWidget>  // Include the library for the floating widgets area
#include <QTabWidget>   // Include the library for tabs
#include <QShortcut>    // Necessary for keyboard shortcuts

int main(int argc, char *argv[])
{
    // Initialize the Qt application
    QApplication app(argc, argv);
    // Create the main window
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("DuskIDE");                                      // Set the window title
    mainWindow.setWindowState(mainWindow.windowState() | Qt::WindowMaximized); // Maximize the window
    // Create a text editor
    QTextEdit *textEdit = new QTextEdit(&mainWindow);
    mainWindow.setCentralWidget(textEdit); // Set the text editor as the central content of the window
    // Create a floating widgets area (file explorer)
    QDockWidget *fileExplorer = new QDockWidget("Explorer", &mainWindow);
    QTabWidget *fileTabs = new QTabWidget(&mainWindow);
    fileExplorer->setWidget(fileTabs);
    // Disable the ability to freely move the file explorer
    fileExplorer->setFeatures(QDockWidget::NoDockWidgetFeatures);
    // Change the location of the file explorer to the right
    mainWindow.addDockWidget(Qt::RightDockWidgetArea, fileExplorer);
    // Create an action to show/hide the file explorer
    QAction *toggleFileExplorerAction = fileExplorer->toggleViewAction();
    // Assign a keyboard shortcut (Ctrl + Alt + B) to the action
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_B), &mainWindow);
    QObject::connect(shortcut, &QShortcut::activated, toggleFileExplorerAction, &QAction::trigger);
    // Add the action to the main window
    mainWindow.addAction(toggleFileExplorerAction);
    // Show the main window
    mainWindow.show();
    // Execute the Qt application
    return app.exec();
}
