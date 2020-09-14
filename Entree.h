#ifndef ENTREE_H
#define ENTREE_H


#include <QApplication>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QTextEdit>
#include <QMessageBox>
#include <QFormLayout>


class Entree: public QWidget
{
    Q_OBJECT
 public:
    Entree();
    QDoubleSpinBox *encaisse;


private slots:
    void genererCode();
    void additionner();

 private:
    QGroupBox *augmentation;
    QDateEdit *dateCreation;
    QDoubleSpinBox *montantCreation;
    QDoubleSpinBox *fraisPoste;
    QDoubleSpinBox *fraisTransport;
    QDoubleSpinBox *fraisDeplacement;
    QDoubleSpinBox *fraisVente;
    QDoubleSpinBox *fraisDivers;
    QDoubleSpinBox *valCaisse1;
    QDoubleSpinBox *valCaisse2;
    QDateEdit *dateRenflouement;
    QDoubleSpinBox *montAugmentation;
    QDateEdit *dateAugmentation;
    QPushButton *bouton1;
    QPushButton *bouton2;
    QPushButton *calEncaisse;

};

#endif // ENTREE_H
