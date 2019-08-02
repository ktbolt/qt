
#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;

class Window : public QWidget {

  Q_OBJECT

  public:
      explicit Window(QWidget *parent = 0); private:

  signals:
    void counterReached();

  private slots:
      void slotButtonClicked(bool checked);

  private:
      QPushButton* m_button;
      int m_counter;

};

#endif // WINDOW_H


