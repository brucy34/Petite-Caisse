#include "Entree.h"
#include "Sortie.h"


Entree::Entree()
{
    dateCreation=new QDateEdit();
    dateCreation->setDate(QDate::currentDate());
    montantCreation=new QDoubleSpinBox();

    QFormLayout *layout1=new QFormLayout;
    layout1->addRow("&Date de création :",dateCreation);
    layout1->addRow("&Montant de création :",montantCreation);

    QGroupBox *groupe1=new QGroupBox("Création de la petite caisse");
    groupe1->setLayout(layout1);



    fraisPoste=new QDoubleSpinBox();
    fraisTransport=new QDoubleSpinBox();
    fraisDeplacement=new QDoubleSpinBox();
    fraisVente=new QDoubleSpinBox();
    fraisDivers=new QDoubleSpinBox();
    valCaisse=new QDoubleSpinBox();
    dateRenflouement=new QDateEdit();
    dateRenflouement->setDate(QDate::currentDate());

    QFormLayout *layout2=new QFormLayout;
    layout2->addRow("Frais de &poste :",fraisPoste);
    layout2->addRow("Frais de &transport :",fraisTransport);
    layout2->addRow("Frais de dép&lacement :",fraisDeplacement);
    layout2->addRow("Frais de &vente :",fraisVente);
    layout2->addRow("Frais d&ivers :",fraisDivers);
    layout2->addRow("M&ontant réel de la Petite Caisse :",valCaisse);
    layout2->addRow("Date de &renflouement :",dateRenflouement);

    QGroupBox *groupe2=new QGroupBox("Renflouement de la Petite Caisse");
    groupe2->setLayout(layout2);



    montAugmentation=new QDoubleSpinBox();
    dateAugmentation=new QDateEdit();
    dateAugmentation->setDate(QDate::currentDate());

    QFormLayout *layout3=new QFormLayout();
    layout3->addRow("Mon&tant de l'augmentation :",montAugmentation);
    layout3->addRow("Date de l'a&ugmentation :",dateAugmentation);

    augmentation=new QGroupBox("Augmentation de la Petite Caisse");
    augmentation->setCheckable(true);
    augmentation->setChecked(false);
    augmentation->setLayout(layout3);




    bouton1=new QPushButton("Quitter");
    bouton2=new QPushButton("Générer le journal général");

    QHBoxLayout *hbx=new QHBoxLayout();
    hbx->addWidget(bouton1);
    hbx->addWidget(bouton2);
    hbx->setAlignment(Qt::AlignRight);


    QVBoxLayout *vbx=new QVBoxLayout();
    vbx->addWidget(groupe1);
    vbx->addWidget(groupe2);
    vbx->addWidget(augmentation);
    vbx->addLayout(hbx);


    setLayout(vbx);
    setWindowTitle("Petite Caisse");


    connect(bouton1, SIGNAL(clicked()),qApp, SLOT(quit()));
    connect(bouton2, SIGNAL(clicked()),this, SLOT(genererCode()));

}
