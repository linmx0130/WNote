#ifndef RECITEWORDSFORM_H
#define RECITEWORDSFORM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QCloseEvent>

class ReciteWordsForm : public QWidget
{
    Q_OBJECT
    QVBoxLayout *mainLayout;
    QHBoxLayout *btnLayout;
    QLabel *wordLabel, *explanLabel;
    QPushButton *nextBtn,*previousBtn, *removeBtn;
    int wordListCur;
    void loadWord();
public:
    explicit ReciteWordsForm(QWidget *parent = 0);
protected:
    void closeEvent(QCloseEvent *);
signals:
    void closeForm();
public slots:
    void nextWord();
    void previousWord();
    void removeWord();
};

#endif // RECITEWORDSFORM_H
