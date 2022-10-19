/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <QDialog>
#include <QQueue>
#include "ctrlcomposite.h"
#include "frmgenerators.h"
#include "frmenveloppes.h"
#include "frmmatrix.h"
#include "frmfxs.h"
#include "arpeggio.h"

#include "uiwavetablemgrvue.h"

#include "ctrlparamleaf.h"

class Parametre;

class BlofeldEditorVue
        :public QWidget
{
    Q_OBJECT

    QTabWidget * _editorParams;
    QLayout * mainLayout;
    QVector<CtrlParamLeaf *> _controles;

    frmGenerators *lyOscillators;
    frmEnveloppes *lyEnveloppes;
    frmMatrix *lyMatrix;
    frmFXs *lyFiltersFXs;
    Arpeggio *lyArpeggio;

    Instrument * _dump;
public:
    BlofeldEditorVue(QWidget *parent,const BlofeldReplica *synth, Instrument *dump);
    ~BlofeldEditorVue();
    CtrlParamLeaf * GetCtrl(int id);

    void updatethis(const Parametre *param);
    void initControls();
    static bool sortControls(const CtrlParamLeaf * v1,const CtrlParamLeaf * v2)
    {
        return v1->getParamId() < v2->getParamId();
    }

    friend class BlofeldViews;

 };

#endif
