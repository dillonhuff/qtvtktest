#include <QtWidgets>

#include "window.h"

Window::Window() {
  shapeLabel = new QLabel(tr("Shape"));
  addToolButton = new QPushButton("Add tool", this);
  addViceButton = new QPushButton("Add vice", this);
  addBasePlateButton = new QPushButton("Add base plate", this);
  loadModelButton = new QPushButton("Load model", this);


  QVBoxLayout* layout = new QVBoxLayout();
  layout->addWidget(shapeLabel);
  layout->addWidget(addToolButton);
  layout->addWidget(addViceButton);
  layout->addWidget(addBasePlateButton);
  layout->addWidget(loadModelButton);

  setLayout(layout);

  setWindowTitle(tr("Labeled Window"));
}
