#include "trackerinterface.h"
#include "ui_trackerinterface.h"
#include "tasklist.h"
#include <string>
#include <string.h>
#include <iostream>
#include <QStringListModel>
#include <QMessageBox>

using namespace std;

TaskList list1;

//stuff from original main.cpp
void addTask(TaskList &toDoList, string task) {
    toDoList.pushBack(task);
    //cout << task << ", has been added to your to do list! " << endl << endl;
}

void displayTasks(TaskList &toDoList) {
    toDoList.traverseList();
}
//Ending

TrackerInterface::TrackerInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrackerInterface)
{
    ui->setupUi(this);
}

TrackerInterface::~TrackerInterface()
{
    delete ui;
}

void TrackerInterface::on_addTaskButton_clicked()
{
    QString task = ui->textEdit->toPlainText();
    string utf8Task = task.toLocal8Bit().constData();
    addTask(list1, utf8Task);
    ui->textEdit->clear();
    QString addTaskMsg = task + " has been added to your to-do list!";
    QMessageBox::information(this, tr("Task Tracker"), addTaskMsg);
}

void TrackerInterface::on_viewTasksButton_clicked()
{
    //displayTasks(list1);
    QVector<QString> myQVector = QVector<QString>::fromStdVector(list1.returnList());
    ui->listView->setModel(new QStringListModel(QList<QString>::fromVector(myQVector)));
}

void TrackerInterface::on_completeTaskButton_clicked()
{
   // completeTask(list1);
    if (!list1.isEmpty()) { //Making sure at least one task is in the list to complete
        string completedTask = list1.pop();
        QString qCompletedTask = QString::fromStdString(completedTask) + " has been completed!";
        QMessageBox::information(this, tr("Task Tracker"), qCompletedTask);
        list1.addPoints();
    }
    else {
        QMessageBox::warning(this, tr("Task Tracker"), tr("There is nothing on your list to complete!"));
    }
}

void TrackerInterface::on_removeTaskButton_clicked()
{
    string removedTask = list1.pop();
    QString qRemovedTask;
    if (removedTask == "There is nothing currently in the list!") {
        qRemovedTask = QString::fromStdString(removedTask);
    }
    else {
        qRemovedTask = QString::fromStdString(removedTask) + " has been removed from your to-do list!";
    }
    QMessageBox::warning(this, tr("Task Tracker"), qRemovedTask);
}

void TrackerInterface::on_viewScoreButton_clicked()
{
    if (list1.displayScore() == 0) {
        QMessageBox::warning(this, tr("Task Tracker"), "Your current score is 0!");
    }
    else {
        QMessageBox::information(this, tr("Task Tracker"), "Your current score is " +QString::number(list1.displayScore()) + " !");
    }
}
