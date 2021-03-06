#ifndef ADDWORDFORM_H
#define ADDWORDFORM_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCloseEvent>

class AddWordForm : public QWidget
{
    Q_OBJECT
    QLineEdit *wordTE, *explanationTE;
    QLabel *wordLabel, *explanationLabel;
    QHBoxLayout *inputLayout, *buttonLayout;
    QVBoxLayout *leftLayout, *rightLayout, *mainLayout;
    QPushButton *okBtn, *cancelBtn;
public:
    explicit AddWordForm(QWidget *parent = 0);
protected:
    void closeEvent(QCloseEvent *);
signals:
    void closeForm();
public slots:
    void saveWord();
};

#endif // ADDWORDFORM_H
