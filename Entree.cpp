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


    calEncaisse=new QPushButton("Calcul de l'encaisse");
    fraisPoste=new QDoubleSpinBox();
    fraisTransport=new QDoubleSpinBox();
    fraisDeplacement=new QDoubleSpinBox();
    fraisVente=new QDoubleSpinBox();
    fraisDivers=new QDoubleSpinBox();
    valCaisse1=new QDoubleSpinBox();
    valCaisse2=new QDoubleSpinBox();
    dateRenflouement=new QDateEdit();
    encaisse=new QDoubleSpinBox(this);
    connect(calEncaisse, SIGNAL(clicked()), this, SLOT(additionner()));
    dateRenflouement->setDate(QDate::currentDate());


    QFormLayout *layout2=new QFormLayout;
    layout2->addRow("Frais de &poste :",fraisPoste);
    layout2->addRow("Frais de &transport :",fraisTransport);
    layout2->addRow("Frais de dép&lacement :",fraisDeplacement);
    layout2->addRow("Frais de &vente :",fraisVente);
    layout2->addRow("Frais d&ivers :",fraisDivers);
    layout2->addRow("Dé&ficit de caisse :",valCaisse1);
    layout2->addRow("Sur&plus de caisse :",valCaisse2);
    layout2->addRow("Date de &renflouement :",dateRenflouement);
    layout2->addRow("Monta&nt sortie de l'encaisse :",encaisse);
    layout2->addWidget(calEncaisse);


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

    code +="                             Journal Général                 \n";
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
    code +="                         Frais de transport à l'achat                "+fraisTransport->text()+"\n";
    code +="                         Frais de déplacement                        "+fraisDeplacement->text()+"\n";
    code +="                         Frais de vente                              "+fraisVente->text()+"\n";
    code +="                         Frais divers                                "+fraisDivers->text()+"\n";
    code +="                         Déficit de caisse                           "+valCaisse1->text()+"\n";
    code +="                         @Surplus de Caisse                                          "+valCaisse2->text()+"\n";
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
