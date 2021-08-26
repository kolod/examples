#include <QPrintPreviewDialog>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, mMyWidget(new MyWidget(this))
{
	setCentralWidget(mMyWidget);
}

void MainWindow::print() {
	auto *printer = new QPrinter();
	printer->setResolution(1200);
	printer->setPageLayout(QPageLayout(
		QPageSize(QPageSize::A4),
		QPageLayout::Landscape,
		QMarginsF()
	));

	auto *dialog = new QPrintPreviewDialog(this);
	connect(dialog, &QPrintPreviewDialog::paintRequested, this, &MainWindow::draw);
	connect(dialog, &QPrintPreviewDialog::finished, this, &MainWindow::close);
	dialog->open();
}

void MainWindow::draw(QPrinter *printer) {
	QPainter painter;
	painter.begin(printer);
	mMyWidget->drawWidget(painter);
	painter.end();
}
