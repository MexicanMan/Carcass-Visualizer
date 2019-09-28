#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = getScene();

    this->setFixedSize(size());
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Scene setup
QGraphicsScene* MainWindow::getScene()
{
    scene = new QGraphicsScene(ui->mainView);
    scene->setSceneRect(-ui->mainView->width()/2, -ui->mainView->height()/2, ui->mainView->width()-5, ui->mainView->height()-5);  //

    ui->mainView->setScene(scene);
    ui->mainView->show();

    return scene;
}

char *MainWindow::QStringToCharArr(QString str)
{
    char* buff = (char*) malloc(sizeof(char)*str.length());
    strcpy(buff, str.toLocal8Bit().data());
    return buff;
}

void MainWindow::draw()
{
    DrawCommand draw_comm(new QTDraw(scene));
    if (f.CallComand(draw_comm, ui->listCams->currentIndex()))
        showError(f.GetError());
    else
        ui->mainView->show();
}

void MainWindow::on_explorerBtn_clicked()
{
    QString dir = QFileDialog::getOpenFileName(0, QObject::tr("Specify model file"),
                                                                QDir::currentPath(), QObject::tr(""));

    ui->path->setText(dir);
}

void MainWindow::on_openBtn_clicked()
{
    const char* dir = QStringToCharArr(ui->path->text());

    LoadMdlCommand load_comm(dir, new FileLoad());
    if (f.CallComand(load_comm, 0))
        showError(f.GetError());
    else
    {
        ui->listModels->addItem(QString("%1 - %2").arg(ui->listModels->count()).arg(dir));
        draw();
    }
}

void MainWindow::showError(const char *error)
{
    QString str_error(error);
    QMessageBox::critical(this, "Error!", str_error);
}

void MainWindow::on_MoveBtn_clicked()
{
    double dx = ui->DX->value();
    double dy = ui->DY->value();
    double dz = ui->DZ->value();
    MoveMdlCommand move_comm(dx, dy, dz);

    if (f.CallComand(move_comm, ui->listModels->currentIndex()-1))
        showError(f.GetError());
    else
        draw();
}

void MainWindow::on_ClearMdlBtn_clicked()
{
    DelMdlCommand del_comm;
    if (ui->listModels->currentIndex() == 0)
        return ;

    if (f.CallComand(del_comm, ui->listModels->currentIndex()-1))
        showError(f.GetError());
    else
    {
        ui->listModels->removeItem(ui->listModels->currentIndex());
        draw();
    }
}

void MainWindow::on_RotateBtn_clicked()
{
    double deg_x = ui->degX->value();
    double deg_y = ui->degY->value();
    double deg_z = ui->degZ->value();
    RotateMdlCommand rotate_comm(deg_x, deg_y, deg_z);

    if (f.CallComand(rotate_comm, ui->listModels->currentIndex()-1))
        showError(f.GetError());
    else
        draw();
}

void MainWindow::on_ScaleBtn_clicked()
{
    ScaleMdlCommand scale_comm(ui->koef->value());

    if (f.CallComand(scale_comm, ui->listModels->currentIndex()-1))
        showError(f.GetError());
    else
        draw();
}

void MainWindow::on_createCamBtn_clicked()
{
    double x = ui->X_cam->value();
    double y = ui->Y_cam->value();
    double z = ui->Z_cam->value();
    AddCamCommand addcam_comm(x, y, z);

    if (f.CallComand(addcam_comm, ui->listCams->currentIndex()))
        showError(f.GetError());
    else
        ui->listCams->addItem(QString("%1 camera (%2; %3; %4)").arg(ui->listCams->count()).arg(x).arg(y).arg(z));
}

void MainWindow::on_RotateCamBtn_clicked()
{
    double deg_x = ui->degX->value();
    double deg_y = ui->degY->value();
    double deg_z = ui->degZ->value();
    RotateCamCommand rotate_comm(deg_x, deg_y, deg_z);

    if (f.CallComand(rotate_comm, ui->listCams->currentIndex()))
        showError(f.GetError());
    else
        draw();
}

void MainWindow::on_ClearCamBtn_clicked()
{
    DelCamCommand delcam_comm;

    if (ui->listCams->currentIndex() == 0)
        return ;

    if (f.CallComand(delcam_comm, ui->listCams->currentIndex()))
        showError(f.GetError());
    else
        ui->listCams->removeItem(ui->listCams->currentIndex());
}

void MainWindow::on_MoveCamBtn_clicked()
{
    double dx = ui->DX->value();
    double dy = ui->DY->value();
    double dz = ui->DZ->value();
    MoveCamCommand movecam_comm(dx, dy, dz);

    if (f.CallComand(movecam_comm, ui->listCams->currentIndex()))
        showError(f.GetError());
    else
        draw();
}

void MainWindow::on_listCams_currentIndexChanged(int index)
{
    draw();
}
