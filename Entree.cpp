#include "Entree.h"
#include "Sortie.h"


Entree::Entree()
{

    dateCreation=new QDateEdit();
    dateCreation->setDate(QDate::currentDate());
    montantCreation=new QDoubleSpinBox();
    montantCreation->setMaximum(1000000);

    QFormLayout *layout1=new QFormLayout;
    layout1->addRow("&Date de création :",dateCreation);
    layout1->addRow("&Montant de création :",montantCreation);

    QGroupBox *groupe1=new QGroupBox("Création de la petite caisse");
    groupe1->setLayout(layout1);


    calEncaisse=new QPushButton("Calcul de l'encaisse");
    ecart=new QPushButton("Calcul de l'ecart de caisse");
    fraisPoste=new QDoubleSpinBox();
    fraisTransport=new QDoubleSpinBox();
    fraisDeplacement=new QDoubleSpinBox();
    fraisVente=new QDoubleSpinBox();
    fraisDivers=new QDoubleSpinBox();
    montReel=new QDoubleSpinBox();
    valCaisse1=new QDoubleSpinBox();
    valCaisse2=new QDoubleSpinBox();
    dateRenflouement=new QDateEdit();
    encaisse=new QDoubleSpinBox(this);
    fraisDeplacement->setMaximum(1000000);
    fraisDivers->setMaximum(1000000);
    fraisPoste->setMaximum(1000000);
    fraisTransport->setMaximum(1000000);
    fraisVente->setMaximum(1000000);
    valCaisse1->setMaximum(1000000);
    valCaisse2->setMaximum(1000000);
    encaisse->setMaximum(1000000);
    montReel->setMaximum(1000000);


    connect(calEncaisse, SIGNAL(clicked()), this, SLOT(additionner()));
    connect(ecart, SIGNAL(clicked()),this, SLOT(ecartCaisse()));
    connect(ecart, SIGNAL(clicked()),this, SLOT(ecartCaisse()));
    dateRenflouement->setDate(QDate::currentDate());


    QFormLayout *layout2=new QFormLayout;
    layout2->addRow("Frais de &poste :",fraisPoste);
    layout2->addRow("Frais de &transport :",fraisTransport);
    layout2->addRow("Frais de dép&lacement :",fraisDeplacement);
    layout2->addRow("Frais de &vente :",fraisVente);
    layout2->addRow("Frais d&ivers :",fraisDivers);
    layout2->addRow("Montant réel de la &caisse: ",montReel);
    layout2->addRow("Dé&ficit de caisse :",valCaisse1);
    layout2->addRow("Sur&plus de caisse :",valCaisse2);
    layout2->addRow("Date de &renflouement :",dateRenflouement);
    layout2->addRow("Monta&nt sortie de l'encaisse :",encaisse);
    layout2->addWidget(calEncaisse);
    layout2->addWidget(ecart);


    QGroupBox *groupe2=new QGroupBox("Renflouement de la Petite Caisse");
    groupe2->setLayout(layout2);



    montAugmentation=new QDoubleSpinBox();
    dateAugmentation=new QDateEdit();
    dateAugmentation->setDate(QDate::currentDate());
    montAugmentation->setMaximum(1000000);


    QFormLayout *layout3=new QFormLayout();
    layout3->addRow("Montant de l'au&gmentation :",montAugmentation);
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

void Entree::ecartCaisse()
{

    if (montantCreation->value()-fraisDeplacement->value()-fraisDivers->value()-fraisPoste->value()-fraisTransport->value()-fraisVente->value()>montReel->value())
    {valCaisse1->setValue(montantCreation->value()-fraisDeplacement->value()-fraisDivers->value()-fraisPoste->value()-fraisTransport->value()-fraisVente->value()-montReel->value());}
    else
    {valCaisse2->setValue(montReel->value()-montantCreation->value()+fraisDeplacement->value()+fraisDivers->value()+fraisPoste->value()+fraisTransport->value()+fraisVente->value());}

}

void Entree::additionner()
{
     encaisse->setValue(fraisDeplacement->value()+fraisDivers->value()+fraisPoste->value()+fraisTransport->value()+fraisVente->value()+valCaisse1->value()-valCaisse2->value());

}
void Entree::genererCode()
{
    if(montantCreation->text()=="0,00" or encaisse->text()=="0,00")
    {
        QMessageBox::critical(this,"Erreur!!","Veuillez entrez au moins une valeur de Petite Caisse et/ou d'Encaisse ");
        return;
    }

    QString code;

    code +="                                      Journal Général                 \n";
    code +="Date                |Noms et explications des comptes               |DT             |CT\n";


    code +=dateCreation->date().toString();

    code +="       Petite Caisse               ";
    code +="                "+ montantCreation->text()+"\n";
    code +="                         @Encaisse                                                   "+montantCreation->text()+"\n";
    code +="                        Création de la petite caisse\n";
    code +="                    ________________________________________________\n";


    code +=dateRenflouement->date().toString();
    code +="       Frais de poste              ";
    code +="                "+ fraisPoste->text()+"\n";
    if (fraisTransport->text()!="0,00")
    { code +="                         Frais de transport à l'achat                "+fraisTransport->text()+"\n";}
    if (fraisDeplacement->text()!="0,00")
    { code +="                         Frais de déplacement                        "+fraisDeplacement->text()+"\n";}
    if (fraisVente->text()!="0,00")
    { code +="                         Frais de vente                              "+fraisVente->text()+"\n";}
    if (fraisDivers->text()!="0,00")
    { code +="                         Frais divers                                "+fraisDivers->text()+"\n";}
    if (valCaisse1->text()!="0,00")
    { code +="                         Déficit de caisse                           "+valCaisse1->text()+"\n";}
    if (valCaisse2->text()!="0,00")
    { code +="                         @Surplus de Caisse                                          "+valCaisse2->text()+"\n";}
    code +="                         @Encaisse                                                   "+encaisse->text()+"\n";
    code +="                        Pour comptabliser le renflouement de la petite caisse\n";
    code +="                    ________________________________________________\n";


    if(augmentation->isChecked())
    {
    code +=dateAugmentation->date().toString();
    code +="       Petite Caisse               ";
    code +="                "+montAugmentation->text()+"\n";
    code +="                         @Encaisse                                                   "+montAugmentation->text()+"\n";
    code +="                        Pour comptabliser l'augmentation de la Petite Caisse\n";
    code +="                    _______________________________________________\n";
    }


    Sortie *fenetreCode=new Sortie(code,this);
    fenetreCode->exec();
}
