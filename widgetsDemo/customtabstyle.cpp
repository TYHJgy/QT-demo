﻿#include "customtabstyle.h"


CustomTabStyle::CustomTabStyle()
{

}
QSize CustomTabStyle::sizeFromContents(ContentsType type, const QStyleOption *option,
    const QSize &size, const QWidget *widget) const
{
    QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
    if (type == QStyle::CT_TabBarTab) {
        s.transpose();
        s.rwidth() = 90; // 设置每个tabBar中item的大小
        s.rheight() = 90;
    }
    return s;
}

void CustomTabStyle::drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    if (element == CE_TabBarTabLabel) {
        if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option)) {
            QRect allRect = tab->rect;

            if (tab->state & QStyle::State_Selected) {
                painter->save();
                painter->setPen(0x89cfff);
                painter->setBrush(QBrush(0x89cfff));
                painter->drawRect(allRect.adjusted(6, 6, -6, -6));
                //带有弧线矩形
//                painter->drawRoundedRect(tab->rect, 8, 8);
                painter->restore();
            }
            QTextOption option;
            option.setAlignment(Qt::AlignCenter);
            if (tab->state & QStyle::State_Selected) {
                painter->setPen(0xf8fcff);
            }
            else {
                painter->setPen(0x5d5d5d);
            }
            painter->drawText(allRect, tab->text+"\n哈哈哈", option);
            return;
        }
    }

    if (element == CE_TabBarTab) {
        QProxyStyle::drawControl(element, option, painter, widget);
    }
}
