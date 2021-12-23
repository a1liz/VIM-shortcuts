#include "mainwindow.h"

#include <QFile>
#include <QPoint>
#include <QRect>
#include <QSignalMapper>
#include <QSize>

#include "ui_mainwindow.h"

#define BASE_X 100
#define BASE_Y 100

int key_width[] = {0, 100, 125, 150, 175, 200, 225, 275, 600, 625, 700};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
//, ui(new Ui::MainWindow)
{
  QSignalMapper signalMapper;
  uKeymap ukeymap("/Users/liz/VIM-shortcuts/config/keymap.json");
  int x = BASE_X;
  int y = BASE_Y;
  for (int i = 0; i < ukeymap.length(); i++) {
    buttonlist.append(new QPushButton(ukeymap.getValue(i, 0)));
    int keywidth = key_width[ukeymap.getWidth(i)];
    if (ukeymap.getColID(i) == 0) {
      x = BASE_X;
      y += 75;
    } else {
      x += keywidth;
    }

    buttonlist[i]->setGeometry(
        QRect(QPoint(x - keywidth, y), QSize(keywidth, 50)));
    connect(buttonlist[i], SIGNAL(released()), &signalMapper, SLOT(map()));
    signalMapper.setMapping(buttonlist[i], i);
  }
  // connect(&signalMapper, SIGNAL(mapped(int)), this, SLOT(handleButton(int)));

  // ui->setupUi(this);
}

MainWindow::~MainWindow() {
  // delete ui;
}

void MainWindow::handleButton(int id) { printf("button %d is released", id); }
