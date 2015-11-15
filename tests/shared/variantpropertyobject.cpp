/*
  variantinspector.cpp

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2013-2015 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Stephen Kelly <stephen.kelly@kdab.com>

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "variantpropertyobject.h"

#include <QHash>
#include <QVariant>

#if QT_VERSION < QT_VERSION_CHECK(5, 2, 0)
typedef QHash<QString, int> StringIntHash;
Q_DECLARE_METATYPE(StringIntHash)
#endif

VariantPropertyObject::VariantPropertyObject(QObject *parent):
    QObject(parent),
    m_object(new QObject)
{
    QHash<QString, int> mapping;
    mapping.insert(QStringLiteral("One"), 1);
    mapping.insert(QStringLiteral("Two"), 2);

    setProperty("dynamicProperty", QVariant::fromValue(mapping));
}

VariantPropertyObject::~VariantPropertyObject()
{
}

QSharedPointer<QObject> VariantPropertyObject::sharedObject() const
{
  return m_object;
}

QPointer<QObject> VariantPropertyObject::trackingObject() const
{
  return m_object.data();
}

QVector<int> VariantPropertyObject::widgetVector() const
{
  QVector<int> vec;
  vec << 5;
  vec << 6;
  vec << 7;
  vec << 8;
  return vec;
}
