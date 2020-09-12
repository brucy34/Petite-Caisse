#ifndef SORTIE_H
#define SORTIE_H


#include <QApplication>
#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

class Sortie: public QDialog
{
public:
    Sortie(QString &code,QWidget *parent);


private:
    QTextEdit *codeGenere;
    QPushButton *fermer;
};
#endif // SORTIE_H
