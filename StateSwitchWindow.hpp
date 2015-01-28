﻿/* Copyright 2015 Wojciech Matusiak
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STATESWITCHWINDOW_HPP
#define STATESWITCHWINDOW_HPP

#include <QtGui>
#include <QDockWidget>
#include <QListView>
#include <QLayout>
#include <QListView>
#include <QAbstractListModel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>

class CellularAutomaton;
class GridViewer;



class StateInfoWidget : public QWidget
{
    Q_OBJECT

    CellularAutomaton *_automaton;
    QFormLayout *_layout;
    QLabel *_numberDisplay;
    QLabel *_numberLabel;
    QLabel *_nameDisplay;
    QLabel *_nameLabel;
    QLabel *_colorDisplay;
    QLabel *_colorLabel;

public:
    StateInfoWidget(CellularAutomaton *automaton, QWidget *parent);

    void updateDisplays(quint16 state);
};




class StatesTableModel :
        public QAbstractListModel
{
    Q_OBJECT

    CellularAutomaton *_automaton;

public:
    StatesTableModel(CellularAutomaton *automaton, QObject *parent);

    int rowCount(const QModelIndex &) const override;

    QVariant data(const QModelIndex &index, int role) const override;

private slots:
    void statesModified(quint16 state);
};


class StateSwitchWidget : public QWidget
{
    Q_OBJECT

    QListView *_palette;
    QAbstractListModel *_statesModel;
    GridViewer *_viewer;
    QVBoxLayout *_layout;
    StateInfoWidget *_infoWidget;

public:
    StateSwitchWidget(CellularAutomaton *automaton, GridViewer *viewer, QWidget *parent);

public slots:
    void selectedBrushChange(const QItemSelection &, const QItemSelection &);

};


class StateSwitchDock : public QDockWidget
{
    Q_OBJECT

    QWidget *_widget;

public:
    StateSwitchDock(CellularAutomaton *automaton, GridViewer *viewer, QWidget *parent);

};


#endif // STATESWITCHWINDOW_HPP
