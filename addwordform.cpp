#include "addwordform.h"
#include "global.h"

AddWordForm::AddWordForm(QWidget *parent) :
    QWidget(parent)
{
    wordTE = new QLineEdit();
    explanationTE = new QLineEdit();
    wordLabel = new QLabel("Word:");
    explanationLabel = new QLabel("Explanation:");
    okBtn = new QPushButton("Save");
    cancelBtn = new QPushButton("Cancel");

    leftLayout=new QVBoxLayout();
    leftLayout->addWidget(wordLabel);
    leftLayout->addWidget(explanationLabel);
    rightLayout=new QVBoxLayout();
    rightLayout->addWidget(wordTE);
    rightLayout->addWidget(explanationTE);

    inputLayout=new QHBoxLayout();
    inputLayout->addLayout(leftLayout);
    inputLayout->addLayout(rightLayout);

    buttonLayout=new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(okBtn);
    buttonLayout->addWidget(cancelBtn);

    mainLayout=new QVBoxLayout();
    mainLayout->addLayout(inputLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    connect(cancelBtn,SIGNAL(clicked()),this,SLOT(close()));
    connect(okBtn,SIGNAL(clicked()),this,SLOT(saveWord()));

    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    setLayout(mainLayout);
}

void AddWordForm::saveWord(){
    QString w=this->wordTE->text();
    QString e=this->explanationTE->text();
    WordNode *t=new WordNode(w,e);
    wnote::wm.getWordList().append(t);
    wnote::wm.writeFile("words.xml");
    this->close();
}
extern WordsModel wm;
