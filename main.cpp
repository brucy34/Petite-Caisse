#include <QApplication>
#include "Entree.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);


    Entree fenetre;


    fenetre.show();

    return app.exec();
}
