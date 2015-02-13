#include "recitewordsform.h"
#include "global.h"
ReciteWordsForm::ReciteWordsForm(QWidget *parent) :
    QWidget(parent)
{
    if (wnote::wm.getWordList().size() == 0){
        wordListCur=-1;
    }else {
        wordListCur= 0;
    }
    wordLabel=new QLabel();
    wordLabel->setAlignment(Qt::AlignCenter);
    explanLabel=new QLabel();
    mainLayout=new QVBoxLayout();

    btnLayout=new QHBoxLayout();
    previousBtn = new QPushButton("<-");
    nextBtn= new QPushButton("->");
    removeBtn = new QPushButton("X");
    btnLayout->addWidget(previousBtn);
    btnLayout->addWidget(removeBtn);
    btnLayout->addWidget(nextBtn);

    mainLayout->addWidget(wordLabel);
    mainLayout->addWidget(explanLabel);
    mainLayout->addLayout(btnLayout);

    connect(previousBtn,SIGNAL(clicked()),this,SLOT(previousWord()));
    connect(nextBtn,SIGNAL(clicked()),this,SLOT(nextWord()));
    connect(removeBtn,SIGNAL(clicked()),this,SLOT(removeWord()));
    setLayout(mainLayout);
    loadWord();
}

void ReciteWordsForm::loadWord(){
    if (wordListCur== -1){
        this->wordLabel->setText("404: No words found! QaQ");
        this->explanLabel->setText("");
        return;
    }
    QVector<WordNode *> &wordList=wnote::wm.getWordList();
    this->wordLabel->setText(wordList[wordListCur]->getWord());
    this->explanLabel->setText(wordList[wordListCur]->getExplanation());
}

void ReciteWordsForm::nextWord(){
    if (wnote::wm.getWordList().size() == 0){
        wordListCur=-1;
    }else{
        wordListCur++;
        if (wordListCur >= wnote::wm.getWordList().size()) wordListCur=0;
    }
    loadWord();
}

void ReciteWordsForm::previousWord(){
    if (wnote::wm.getWordList().size() == 0){
        wordListCur=-1;
    }else{
        wordListCur--;
        if (wordListCur == -1) wordListCur = wnote::wm.getWordList().size() - 1;
    }
    loadWord();
}

void ReciteWordsForm::removeWord(){
    if (wordListCur== -1) return ;
    if (wnote::wm.getWordList().size()==0){
        wnote::wm.getWordList().remove(wordListCur);
        wordListCur=-1;
    }else{
        wnote::wm.getWordList().remove(wordListCur);
        if (wordListCur>= wnote::wm.getWordList().size()){
            wordListCur = 0;
        }
    }
    wnote::wm.writeFile("words.xml");
    loadWord();
}
