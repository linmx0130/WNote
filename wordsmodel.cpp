#include "wordsmodel.h"
QString WordNode::getWord() const{
    return this->word;
}

QString WordNode::getExplanation() const{
    return this->explanation;
}

WordsModel::WordsModel(QObject *parent) :
    QObject(parent)
{

}

bool WordsModel::readFile(const QString &filename){
    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        std::cerr << "Error: can't open file " << qPrintable(filename) <<"!" <<std::endl;
        return false;
    }
    this->reader.setDevice(&file);
    reader.readNext();
    while (!reader.atEnd()){
        if (reader.isStartElement()){
            if (reader.name() == "wnote"){
                if (!readWords()) return false;
            }else{
                std::cerr << "Error1: error file " << qPrintable(filename) <<"!" <<std::endl;
                file.close();
                return false;
            }
        }else{
            reader.readNext();
        }
    }
    if (reader.hasError()){
        std::cerr << "Error2: error file " << qPrintable(filename) <<"!" <<std::endl;
        file.close();
        return false;
    }
    for (int i=0;i!=wordList.size();++i){
        std::cout << qPrintable(wordList[i]->getWord()) << ":" << qPrintable(wordList[i]->getExplanation()) << "!\n";
    }
    file.close();
    return true;
}

bool WordsModel::readWords(){
    while (!reader.atEnd()){
        reader.readNext();
        if (reader.isEndElement()){
            if (reader.name()=="wnote"){
                break;
            }
        }
        if (reader.isStartElement()){
            if (reader.name() == "node"){
                WordNode *t=readWord();
                wordList.append(t);
            }
        }
    }
    return true;
}

WordNode* WordsModel::readWord(){
    QString w,e;
    WordNode *ret;
    while (!reader.atEnd()){
        reader.readNext();
        if (reader.isStartElement()){
            if (reader.name() == "word"){
                reader.readNext();
                if (reader.isCharacters()){
                    w=reader.text().toString();
                }
            }
            if (reader.name() == "explanation"){
               reader.readNext();
               if (reader.isCharacters()){
                   e=reader.text().toString();
               }
            }
        }
        if (reader.isEndElement()){
            if (reader.name()=="node"){
                break;
            }
        }
    }
    ret=new WordNode(w,e);
    return ret;
}

WordNode::WordNode(const QString &w, const QString &e):word(w),explanation(e){};
WordNode::WordNode(){
    WordNode("","");
}

QVector<WordNode *> & WordsModel::getWordList(){
    return this->wordList;
}
