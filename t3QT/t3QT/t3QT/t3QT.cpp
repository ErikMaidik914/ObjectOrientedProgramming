#include "t3QT.h"

t3QT::t3QT(Controller& controller, QWidget *parent)
    : QMainWindow(parent), controller{ controller }
{
    ui.setupUi(this);
    this->populateList();
}

t3QT::~t3QT()
{}

void t3QT::populateList()
{
	this->ui.listWidget->clear();
	for (auto vegetable : this->controller.getAllVegetablesWithUniqueFamilies())

	{
		this->ui.listWidget->addItem(QString::fromStdString(vegetable.toString()));
	}
}





