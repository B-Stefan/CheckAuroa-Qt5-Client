#include <QCoreApplication>
#include "libs/client/SWGRatingsAPI.cpp"
using namespace Swagger;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    SWGRatingsApi * api = new SWGRatingsApi();

    api->getRating(60.0,20.9, new QString("2015-10-10"));

    return a.exec();
}

