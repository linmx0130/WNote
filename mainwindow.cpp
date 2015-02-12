#include "mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout();
    addWordBtn = new QPushButton(tr("New Word"));
    readWordBtn = new QPushButton(tr("Recite Words"));
    layout->addWidget(addWordBtn);
    layout->addWidget(readWordBtn);
    setLayout(layout);
    setWindowTitle("WNote");
    wnote::wm.readFile("words.xml");
    connect(addWordBtn,SIGNAL(clicked()),this,SLOT(addWordFormShow()));
}

void MainWindow::addWordFormShow(){
    AddWordForm *f=new AddWordForm();
    f->show();
}

MainWindow::~MainWindow()
{
}
