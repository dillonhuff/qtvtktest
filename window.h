#ifndef HELLO_WINDOW_H
#define HELLO_WINDOW_H

#include <QtWidgets>
#include <QVTKWidget.h>

class Window : public QWidget {
  Q_OBJECT;

public:
  Window();

private:
  QLabel* shapeLabel;

  QPushButton* addToolButton;
  QPushButton* addViceButton;
  QPushButton* addBasePlateButton;
  QPushButton* loadModelButton;

  QVTKWidget* vtk_window;

  void setup_window();
  
};

#endif
