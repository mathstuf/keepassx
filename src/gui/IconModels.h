/*
 *  Copyright (C) 2012 Felix Geyer <debfx@fobos.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSX_ICONMODELS_H
#define KEEPASSX_ICONMODELS_H

#include <QtCore/QAbstractListModel>
#include <QtGui/QImage>

#include "core/Global.h"
#include "core/Uuid.h"

class DefaultIconModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit DefaultIconModel(QObject* parent = Q_NULLPTR);

    int rowCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
};

class CustomIconModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CustomIconModel(QObject* parent = Q_NULLPTR);

    virtual int rowCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    void setIcons(const QHash<Uuid, QImage>& icons, const QList<Uuid>& iconsOrder);
    Uuid uuidFromIndex(const QModelIndex& index) const;
    QModelIndex indexFromUuid(const Uuid& uuid) const;

private:
    QHash<Uuid, QImage> m_icons;
    QList<Uuid> m_iconsOrder;
};

#endif // KEEPASSX_ICONMODELS_H
