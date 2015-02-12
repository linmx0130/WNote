#ifndef WORDSMODEL_H
#define WORDSMODEL_H

#include <QObject>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QVector>
#include <QString>
#include <iostream>


class WordNode{
private:
    QString word, explanation;
public:
    WordNode();
    WordNode(const QString &w, const QString &e);
    QString getWord() const;
    QString getExplanation() const;
    void setWordNote(const QString &w, const QString &e){
        word=w;
        explanation=e;
    }
};

class WordsModel : public QObject
{
    Q_OBJECT
    QXmlStreamReader reader;
    bool readWords();
    WordNode *readWord();
    QVector<WordNode *> wordList;
public:
    explicit WordsModel(QObject *parent = 0);
    bool readFile(const QString &filename);
    QVector<WordNode *>& getWordList();

signals:

public slots:

};

#endif // WORDSMODEL_H
