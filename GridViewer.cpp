﻿/* Copyright 2014, 2015 Wojciech Matusiak
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

#include "GridViewer.hpp"
#include <iostream>
#include "CellularAutomaton.hpp"

GridViewer::GridViewer(QWidget *parent) :
    QWidget(parent)
{
    _automaton = nullptr;
    _activeCellX = 0;
    _activeCellY = 0;
    _painter = new QPainter();
    _stateBrush = 1;

    setMouseTracking(true);

    setMinimumSize(300, 300);
}

GridViewer::~GridViewer()
{
    delete _painter;
}

void GridViewer::paintEvent(QPaintEvent *event)
{
    if (_automaton == nullptr)
        return;
    if (_automaton->statesNumber() == 0)
        return;

    const int cellSize = getCellSize();
    const int topMargin = getTopMargin();
    const int leftMargin = getLeftMargin();

    _painter->begin(this);
    for (QRect area : event->region().rects()) {
        int firstX = std::max(0, (area.x() - leftMargin) / cellSize);
        int lastX = std::min(static_cast<int>(_automaton->gridWidth() - 1), (area.x() + area.width() - leftMargin) / cellSize);
        int firstY = std::max(0, (area.y() - topMargin) / cellSize);
        int lastY = std::min(static_cast<int>(_automaton->gridHeight() - 1), (area.y() + area.height() - topMargin) / cellSize);
        for (int x = firstX; x <= lastX; ++x) {
            for (int y = firstY; y <= lastY; ++y) {
                _painter->setBrush(_automaton->stateColor(_automaton->cellState(x, y)));
                _painter->drawRect(cellSize * x + leftMargin, cellSize * y + topMargin, cellSize, cellSize);
            }
        }
    }

    //FIXME: segfault after changing automaton
    QPen activeCellPen(Qt::black, 3);
    QColor activeCellColor = QColor(_automaton->stateColor(_stateBrush));
    _painter->setPen(activeCellPen);
    _painter->setBrush(QBrush(activeCellColor, Qt::Dense5Pattern));
    _painter->drawRect(cellSize * _activeCellX + leftMargin, cellSize * _activeCellY + topMargin, cellSize, cellSize);

    _painter->end();
}


void GridViewer::setDisplayedAutomaton(Scripting::CellularAutomaton *automaton)
{
    qDebug() << "Changing displayed automaton to" << static_cast<void*>(automaton);
    _automaton = automaton;
    _stateBrush = 0;
    repaint();
}


inline int GridViewer::getCellSize() const
{
    if (_automaton == nullptr)
        return 0;
    return std::min(width() / _automaton->gridWidth(), height() / _automaton->gridHeight());
}


inline int GridViewer::getLeftMargin() const
{
    if (_automaton == nullptr)
        return 0;
    return (width() - getCellSize() * _automaton->gridWidth()) / 2;
}


inline int GridViewer::getTopMargin() const
{
    if (_automaton == nullptr)
        return 0;
    return (height() - getCellSize() * _automaton->gridHeight()) / 2;
}


void GridViewer::mouseMoveEvent(QMouseEvent *event)
{
    if (_automaton == nullptr)
        return;

    const int cellSize = getCellSize();
    const int leftMargin = getLeftMargin();
    const int topMargin = getTopMargin();

    int prevX = _activeCellX;
    int prevY = _activeCellY;
     _activeCellX = (event->x() - leftMargin) / cellSize;
     if (_activeCellX < 0)
         _activeCellX = 0;
     if (static_cast<unsigned int>(_activeCellX) > _automaton->gridWidth() - 1)
         _activeCellX = _automaton->gridWidth() - 1;
     _activeCellY = (event->y() - topMargin) / cellSize;
     if (_activeCellY < 0)
         _activeCellY = 0;
     if (static_cast<unsigned int>(_activeCellY) > _automaton->gridHeight() - 1)
         _activeCellY = _automaton->gridHeight() - 1;

     if (prevX == _activeCellX && prevY == _activeCellY)
         return;

     if (event->buttons() == Qt::LeftButton)
         _automaton->setCellState(_activeCellX, _activeCellY, _stateBrush);

     update(QRegion(leftMargin + prevX * cellSize - 5, topMargin + prevY * cellSize - 5, cellSize + 10, cellSize + 10)
            + QRegion(leftMargin + _activeCellX * cellSize - 5, topMargin + _activeCellY * cellSize - 5, cellSize + 10, cellSize + 10));
}


void GridViewer::mousePressEvent(QMouseEvent *event)
{
    if (_automaton == nullptr)
        return;

    if (event->buttons() == Qt::LeftButton)
        _automaton->setCellState(_activeCellX, _activeCellY, _stateBrush);

    const int cellSize = getCellSize();
    const int leftMargin = getLeftMargin();
    const int topMargin = getTopMargin();
    update(QRegion(leftMargin + _activeCellX * cellSize, topMargin + _activeCellY * cellSize, cellSize, cellSize));
}


quint16 GridViewer::getStateBrush() const
{
    return _stateBrush;
}


void GridViewer::setStateBrush(quint16 brush)
{
    if (_automaton == nullptr)
        return;

    if (brush >= _automaton->statesNumber())
        throw Exceptions::IllegalArgumentException();

    _stateBrush = brush;

    const int cellSize = getCellSize();
    const int leftMargin = getLeftMargin();
    const int topMargin = getTopMargin();
    update(QRegion(leftMargin + _activeCellX * cellSize - 5, topMargin + _activeCellY * cellSize - 5, cellSize + 10, cellSize + 10));
}
