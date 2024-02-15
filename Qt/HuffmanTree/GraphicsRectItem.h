#pragma once

#include <QGraphicsSimpleTextItem>
#include "HuffmanTree.h"

class GraphicsRectItem : public QGraphicsSimpleTextItem
{
public:
    GraphicsRectItem(const QString &text, QGraphicsItem *parent = nullptr);
    ~GraphicsRectItem() override = default;

    QRectF boundingRect() const override;

    QMargins margins() const;
    void setMargins(const QMargins &margins);

    int borderWidth();
    void setBorderWidth(int width);

    QColor textColor() const;
    QColor borderColor() const;
    QColor backgroundColor() const;

    void setTextColor(const QColor &color);
    void setBorderColor(const QColor &color);
    void setBackgroundColor(const QColor &color);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QMargins m_margins;
    int m_borderWidth = 1;
    QColor m_textColor = Qt::black;
    QColor m_borderColor = Qt::black;
    QColor m_backgroundColor = Qt::white;
};

class CircleItem : public QGraphicsEllipseItem {
public:
    CircleItem(const QString& text, QGraphicsItem* parent = nullptr)
        : QGraphicsEllipseItem(parent)
    {
        setRect(0, 0, 50, 50); // Устанавливаем форму круга
        setText(text); // Устанавливаем текст в круге
    }

    void setText(const QString& text)
    {
        QGraphicsTextItem* textItem = new QGraphicsTextItem(text, this);
        textItem->setTextWidth(rect().width()); // Устанавливаем ширину текста по ширине круга
        textItem->setPos(rect().center() - textItem->boundingRect().center()); // Устанавливаем позицию текста в центре круга
    }
};

