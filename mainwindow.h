#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "wordsmodel.h"
#include "global.h"

class MainWindow : public QWidget
{
    Q_OBJECT
    QHBoxLayout *layout;
    QPushButton *addWordBtn, *readWordBtn;
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addWordFormShow();

};
#include "addwordform.h"
#endif // MAINWINDOW_H