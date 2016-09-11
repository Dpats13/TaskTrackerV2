#include "trackerinterface.h"
#include <QApplication>
#include "iostream"
//#include "tasklist.h"

using namespace std;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    TrackerInterface w;
    w.setWindowTitle("Task Tracker V2");
    w.show();

    return a.exec();
}

