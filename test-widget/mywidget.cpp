#include "mywidget.h"

QRectF toQrectF(QRect rect) {
	return QRectF(rect.x(), rect.y(), rect.width() - 1, rect.height() - 1);
}

MyWidget::MyWidget(QWidget *parent)
	: QWidget(parent)
{}

void MyWidget::paintEvent(QPaintEvent *event) {
	QPainter painter(this);
	drawWidget(painter);
	QWidget::paintEvent(event);
}

void MyWidget::drawWidget(QPainter &painter) {
	if (painter.isActive()) {

		QPen pen;
		pen.setWidthF(6.0);
		pen.setColor(QColor(Qt::black));
		pen.setCapStyle(Qt::SquareCap);
		pen.setJoinStyle(Qt::MiterJoin);

		auto rect = QRectF(painter.window());

		painter.save();
		painter.setPen(pen);
		painter.drawRect(rect);
		painter.drawText(rect, Qt::AlignCenter, "Text");
		painter.restore();
	}
}
