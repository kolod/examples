#pragma once

#include <QApplication>
#include <QPrintPreviewDialog>
#include <QPageLayout>

//#include "qcustomplot.h"
#include "qcp.h"

class Sample : public QObject
{
	Q_OBJECT

public:
	explicit Sample(QObject *parent = nullptr);
	bool show();

public slots:
    void draw(QPrinter *printer);

private:
	QCustomPlot mCustomPlot;
	QPrinter mPrinter;
	QPrintPreviewDialog mDialog;
};
