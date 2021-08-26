#pragma once

#include <QWidget>
#include <QPainter>

class MyWidget : public QWidget
{
	Q_OBJECT

public:
	explicit MyWidget(QWidget *parent = nullptr);
	void drawWidget(QPainter &painter);

protected:
	void paintEvent(QPaintEvent *event) override;
};
