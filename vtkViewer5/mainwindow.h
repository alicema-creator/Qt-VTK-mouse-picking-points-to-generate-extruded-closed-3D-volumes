#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkRenderer.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;

   vtkSmartPointer<vtkPolyData> TheStlPoly; // 添加这行代码
   vtkSmartPointer<vtkRenderer> renderer; // 添加这行代码


private slots:

     void actionPickPointStart();
     void actionPickPointClose();
     void on_actionPickPoint_triggered(); //新加的
     void ClipModelWithPolygon();
     void ClipModelWithPolygonPreview();

};
#endif // MAINWINDOW_H
