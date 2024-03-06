
#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>
#include <vtkPlaneSource.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPropPicker.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkRendererCollection.h>
#include <vtkSphereSource.h>
#include <vtkSTLReader.h>

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkPoints.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkUnsignedCharArray.h>
#include <vtkPointData.h>

#include <vtkGlyph3D.h>
#include <vtkSphereSource.h>

#include <vtkActor.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNamedColors.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSTLReader.h>
#include <vtkClipPolyData.h>
#include <vtkSelectPolyData.h>
#include <Eigen/Dense>
#include <vtkPlane.h>
#include <vtkLookupTable.h>
#include <vtkBooleanOperationPolyDataFilter.h>
#include <vtkDelaunay2D.h>
#include <vtkLinearExtrusionFilter.h>
#include <vtkPolygon.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QObject::connect(ui->actionOpen_File_3, &QAction::triggered, this, &MainWindow::on_actionPickPoint_triggered);
    QObject::connect(ui->actionStart, &QAction::triggered, this, &MainWindow::actionPickPointStart);

    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->SetBackground(0.1, 0.2, 0.4);
    ui->widget->GetRenderWindow()->AddRenderer(renderer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actionPickPointStart()
{
    pickingModeActive = !pickingModeActive;
}

void MainWindow::actionPickPointClose()
{
    pickingModeActive = !pickingModeActive;
}

void MainWindow::actionPickPoint()
{
	vtkNew<vtkNamedColors> colors;
 
	vtkNew<vtkSphereSource> sphereSource;
	sphereSource->SetRadius(5);
	sphereSource->Update();
 
	vtkNew<vtkPolyDataMapper> mapper;
	mapper->SetInputConnection(sphereSource->GetOutputPort());
 
	vtkNew<vtkActor> actor;
	actor->SetMapper(mapper);
	actor->GetProperty()->SetColor(colors->GetColor3d("MistyRose").GetData());
 
	// Create the RenderWindow, Renderer
	vtkNew<vtkRenderer> renderer;
	vtkNew<vtkRenderWindow> renderWindow;
	renderWindow->AddRenderer(renderer);
	renderWindow->SetWindowName("PolygonalSurfacePointPlacer");
 
	vtkNew<vtkRenderWindowInteractor> interactor;
	interactor->SetRenderWindow(renderWindow);
 
	renderer->AddActor(actor);
	renderer->SetBackground(colors-

}

