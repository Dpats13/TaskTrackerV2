#include <string>
#include <string.h>
#include <iostream>
#include <QMainWindow>

#ifndef TRACKERINTERFACE_H
#define TRACKERINTERFACE_H

namespace Ui {
class TrackerInterface;
}

class TrackerInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrackerInterface(QWidget *parent = 0);
    ~TrackerInterface();

private slots:
    void on_addTaskButton_clicked();

    void on_viewTasksButton_clicked();

    void on_completeTaskButton_clicked();

    void on_removeTaskButton_clicked();

    void on_viewScoreButton_clicked();

private:
    Ui::TrackerInterface *ui;
};

#endif // TRACKERINTERFACE_H
