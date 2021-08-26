#include "sample.h"

#define COUNT 100

Sample::Sample(QObject *parent) : QObject(parent)
{
	// generate some data:
	QVector<double> x(COUNT), y(COUNT); // initialize with entries 0..100

	// let's plot a quadratic function
	for (qsizetype i = 0; i < COUNT; i++)
		x[i] = i * (2.0 / (COUNT - 1)) - 1.0,
		y[i] = x[i] * x[i];

	mCustomPlot.addGraph();
	mCustomPlot.graph(0)->setData(x, y);
	mCustomPlot.graph(0)->setName("y=x^2");

	// give the axes some labels:
	mCustomPlot.xAxis->setLabel("x");
	mCustomPlot.yAxis->setLabel("y");

	// set axes ranges, so we see all data:
	mCustomPlot.xAxis->rescale();
	mCustomPlot.yAxis->rescale();

	// show legend
	mCustomPlot.legend->setVisible(true);

	// Setup printer
	mPrinter.setPageOrientation(QPageLayout::Landscape);
	mPrinter.setPageMargins(QMarginsF(10.0, 10.0, 10.0, 10.0), QPageLayout::Unit::Millimeter);
	mPrinter.setResolution(600);
}

bool Sample::show() {
	auto *dialog = new QPrintPreviewDialog(&mPrinter, nullptr, Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);
	if (dialog == nullptr) return false;

    connect(dialog, &QPrintPreviewDialog::paintRequested, this, &Sample::draw);
	dialog->open();

	return true;
}

void Sample::draw(QPrinter *printer) {
	if (printer != nullptr) {
		QCPPainter painter;
		painter.begin(printer);
		auto rect = painter.window();
		mCustomPlot.toPainter(&painter, rect.width(), rect.height());
		painter.end();
	}
}

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	Sample sample;
	if (sample.show()) return a.exec();
	return 1;
}
