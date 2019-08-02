
#include <QApplication>
#include <QDir>
#include <QFileDialog>
#include <QPushButton>
#include <iostream>

#include "window.h"

void read_vtu_file(std::string file_name);

Window::Window(QWidget *parent) : QWidget(parent)
{
  // Set size of the window
  setFixedSize(500, 500);

  // Create and position the button
  m_button = new QPushButton("Load Mesh", this);
  m_button->setGeometry(10, 10, 160, 60);
  m_button->setCheckable(true);
  m_counter = 0;

  connect(m_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));

  connect(this, SIGNAL(counterReached()), QApplication::instance(), SLOT(quit()));
}

void Window::slotButtonClicked(bool checked)
{
  QDir project_dir("/Users/parkerda/software/qt/examples/file-explorer");

  if (!project_dir.exists()) {
      qWarning("Cannot find directory");
  }

  QString dir = QFileDialog::getOpenFileName(NULL, tr("Choose .vtu file"), project_dir.absolutePath(),
    tr("Mesh file (*.vtu)"));

  dir = dir.trimmed();

  if (dir.isEmpty()) {
      std::cout << "No file selected." << std::endl;
      return;
  }

  auto file_name = dir.toStdString(); 
  std::cout << "[file-explorer] File selected '" << file_name << "'" << std::endl;

  read_vtu_file(file_name);



  /*
  if (checked) { 
      m_button->setText("Checked");
  } else {
      m_button->setText("Hello World"); 
  }

  m_counter += 1;
  std::cout << "[slotButtonClicked] m_counter " << m_counter << std::endl;

  if (m_counter == 2) { 
      emit counterReached(); 
      std::cout << "[slotButtonClicked] emit counterReached signal " << std::endl;
  }
*/

}

