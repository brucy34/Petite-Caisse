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

private slots:
    void genererCode();

 private:
    QGroupBox *augmentation;
    QDateEdit *dateCreation;
    QDoubleSpinBox *montantCreation;
    QDoubleSpinBox *fraisPoste;
    QDoubleSpinBox *fraisTransport;
    QDoubleSpinBox *fraisDeplacement;
    QDoubleSpinBox *fraisVente;
    QDoubleSpinBox *fraisDivers;
    QDoubleSpinBox *valCaisse;
    QDateEdit *dateRenflouement;
    QDoubleSpinBox *montAugmentation;
    QDateEdit *dateAugmentation;
    QPushButton *bouton1;
    QPushButton *bouton2;

};

#endif // ENTREE_H
