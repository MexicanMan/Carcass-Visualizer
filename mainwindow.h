#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QGraphicsScene>
#include <cstring>
#include "facade/facade.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    char* QStringToCharArr(QString str);
    QGraphicsScene* getScene();
    void draw();
    void on_explorerBtn_clicked();
    void showError(const char *error);
    void on_MoveBtn_clicked();
    void on_ClearMdlBtn_clicked();
    void on_RotateBtn_clicked();
    void on_ScaleBtn_clicked();
    void on_createCamBtn_clicked();
    void on_RotateCamBtn_clicked();
    void on_ClearCamBtn_clicked();
    void on_MoveCamBtn_clicked();
    void on_openBtn_clicked();
    void on_listCams_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    Facade f;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
