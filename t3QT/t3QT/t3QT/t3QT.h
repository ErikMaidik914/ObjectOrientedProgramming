#pragma once
#include "Controller.h"

#include <QtWidgets/QMainWindow>
#include "ui_t3QT.h"

class t3QT : public QMainWindow
{
    Q_OBJECT

public:
    t3QT(Controller& controller, QWidget *parent = nullptr);
    ~t3QT();

private:
    Controller controller;
    Ui::t3QTClass ui;

    void populateList();

};
