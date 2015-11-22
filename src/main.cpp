#include <QCoreApplication>
#include "libs/client/SWGRatingsAPI.h"

using namespace Swagger;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    SWGRatingsApi * ratingsApi = new SWGRatingsApi("", "http://check-aurora-api.herokuapp.com");

    ratingsApi->getRating(60.0,20.9, new QString("2015-10-10"));

    return a.exec();
}

