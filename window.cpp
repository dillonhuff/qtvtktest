#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>

#include <QtWidgets>

#include "window.h"

void Window::setup_window() {

}

Window::Window() {
  shapeLabel = new QLabel(tr("Shape"));
  addToolButton = new QPushButton("Add tool", this);
  addViceButton = new QPushButton("Add vice", this);
  addBasePlateButton = new QPushButton("Add base plate", this);
  loadModelButton = new QPushButton("Load model", this);
  vtk_window = new QVTKWidget(); //(this, Qt::Widget);

  setup_window();

  QVBoxLayout* layout = new QVBoxLayout();
  layout->addWidget(shapeLabel);
  layout->addWidget(addToolButton);
  layout->addWidget(addViceButton);
  layout->addWidget(addBasePlateButton);
  layout->addWidget(loadModelButton);
  layout->addWidget(vtk_window);
  layout->update();

  setLayout(layout);

  setWindowTitle(tr("Labeled Window"));

  vtkSmartPointer<vtkSphereSource> sphereSource = 
    vtkSmartPointer<vtkSphereSource>::New();
  sphereSource->SetCenter(0.0, 0.0, 0.0);
  sphereSource->SetRadius(5.0);
 
  vtkSmartPointer<vtkPolyDataMapper> mapper = 
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(sphereSource->GetOutputPort());
 
  vtkSmartPointer<vtkActor> actor = 
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
 
  vtkSmartPointer<vtkRenderer> renderer = 
    vtkSmartPointer<vtkRenderer>::New();

  renderer->SetBackground(1, 1, 1);
  renderer->AddActor(actor);
  
  vtk_window->GetRenderWindow()->AddRenderer(renderer);

  vtk_window->show();

  //  renderer->Render();
  
  
}
