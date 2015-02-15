#include "mainwindow.h"
#include "recitewordsform.h"
#include <QApplication>
#include <QDesktopWidget>
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
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint );
    connect(addWordBtn,SIGNAL(clicked()),this,SLOT(addWordFormShow()));
    connect(readWordBtn,SIGNAL(clicked()),this,SLOT(reciteWordFormShow()));
}

void MainWindow::addWordFormShow(){
    AddWordForm *f=new AddWordForm();
    this->setEnabled(false);
    connect(f,SIGNAL(closeForm()),this,SLOT(enableForm()));
    f->show();
    f-> move ((QApplication::desktop()->width() - f-> width())/2,(QApplication::desktop()->height() - f->height())/2);
}
void MainWindow::reciteWordFormShow(){
    ReciteWordsForm *f=new ReciteWordsForm();
    this->setEnabled(false);
    connect(f,SIGNAL(closeForm()),this,SLOT(enableForm()));
    f->show();
    f-> move ((QApplication::desktop()->width() - f->width())/2,(QApplication::desktop()->height() - f->height())/2);
}

void MainWindow::enableForm(){
    setEnabled(true);
}

MainWindow::~MainWindow()
{
}
