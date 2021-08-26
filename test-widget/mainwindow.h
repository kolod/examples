#pragma once

#include <QPrinter>
#include <QMainWindow>
#include "mywidget.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	void print();

private slots:
	void draw(QPrinter *printer);

private:
	MyWidget *mMyWidget;
};
