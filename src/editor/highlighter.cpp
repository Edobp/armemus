/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
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
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
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
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "highlighter.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QResource>

Highlighter::Highlighter(int BoardIndex, QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{

    switch (BoardIndex) {    
    case ArduinoDue:
    case ArduinoZero:
    case Feather:
        ArduinoHighlighter();
        break;
    case Tiva:
        TivaHighlighter();
        break;
    case RaspberryPi:
        ArduinoHighlighter();
        break;
    default:
        break;
    }
    //ArduinoHighlighter();
}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

    while (startIndex >= 0) {
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}

//----------------------------------TIVA----------------------------------//

void Highlighter::TivaHighlighter()

{
    HighlightingRule rule, rule2;

    keywordFormat.setForeground(Qt::darkMagenta);
    keywordFormat.setFontWeight(QFont::Bold);

    QStringList keywordPatterns;
    QFile file(":/files/Tiva/keyWords.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Error al leer archivo";

    QTextStream textStream(&file);

    while (!textStream.atEnd())
        keywordPatterns << textStream.readLine();
    file.close();

    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule.format = classFormat;
    highlightingRules.append(rule);

    singleLineCommentFormat.setForeground(Qt::darkRed);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::darkRed);

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::darkCyan);
    rule.pattern = QRegExp("\\b[A-Za-z0-9_.]+(?=\\()");
    rule.format = functionFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");

    keywordFormat.setForeground(Qt::darkYellow);
    keywordFormat.setFontWeight(QFont::Helvetica);
    QStringList keywordPatterns2;
    //QString fileName2 = ;
    QFile file2(":/files/Tiva/keyWords2.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Error al leer archivo";
    QTextStream textStream2(&file2);
    while (!textStream2.atEnd())
        keywordPatterns2 << textStream2.readLine();
    file2.close();

    foreach (const QString &pattern2, keywordPatterns2) {
        rule2.pattern = QRegExp(pattern2);
        rule2.format = keywordFormat;
        highlightingRules.append(rule2);
    }
    /*functionFormat2.setFontItalic(true);
    functionFormat2.setForeground(Qt::cyan);
    rule2.pattern = QRegExp("\\w[A-Za-z]+\\w");
    rule2.format = functionFormat2;
    highlightingRules.append(rule);*/
}

//----------------------------------ARDUINO----------------------------------//

void Highlighter::ArduinoHighlighter()

{
    HighlightingRule rule1, rule2, rule3;


    keywordFormat.setForeground(QColor("#D35400"));    

    QStringList keywordPatterns;
    QFile file(":/files/Arduino/Ard_Key_1_2.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Error al leer archivo";

    QTextStream textStream(&file);

    while (!textStream.atEnd())
        keywordPatterns << textStream.readLine();
    file.close();

    foreach (const QString &pattern, keywordPatterns) {
        rule1.pattern = QRegExp(pattern);
        rule1.format = keywordFormat;
        highlightingRules.append(rule1);
    }

    classFormat.setForeground(Qt::black);
    rule1.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
    rule1.format = classFormat;
    highlightingRules.append(rule1);

    singleLineCommentFormat.setForeground(Qt::darkGray);    

    rule1.pattern = QRegExp("//[^\n]*");
    rule1.format = singleLineCommentFormat;
    highlightingRules.append(rule1);

    multiLineCommentFormat.setForeground(Qt::darkGray);    

    quotationFormat.setForeground(Qt::darkGray);

    rule1.pattern = QRegExp("\".*\"");
    rule1.format = quotationFormat;
    highlightingRules.append(rule1);

    functionFormat.setForeground(QColor("#D35400"));
    rule1.pattern = QRegExp("\\b[A-Za-z0-9_.]+(?=\\()");
    rule1.format = functionFormat;    

    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");

    //--------------------------------------------------------------------

    keywordFormat.setForeground(QColor("#728E00"));    

    QStringList keywordPatterns2;
    QFile file2(":/files/Arduino/Ard_Key_3.txt");

    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Error al leer archivo";

    QTextStream textStream2(&file2);

    while (!textStream2.atEnd())
        keywordPatterns2 << textStream2.readLine();
    file2.close();

    foreach (const QString &pattern2, keywordPatterns2) {
        rule2.pattern = QRegExp(pattern2);
        rule2.format = keywordFormat;
        highlightingRules.append(rule2);
    }

    rule2.pattern = QRegExp("//[^\n]*");
    rule2.format = singleLineCommentFormat;
    highlightingRules.append(rule2);

    functionFormat.setForeground(QColor("#728E00"));
    rule2.pattern = QRegExp("\\b[A-Za-z0-9_.]+(?=\\()");
    rule2.format = functionFormat;    

    //--------------------------------------------------------------------

    keywordFormat.setForeground(QColor("#00979C"));
    keywordFormat.setFontWeight(QFont::Normal);

    QStringList keywordPatterns3;
    QFile file3(":/files/Arduino/Ard_Lit.txt");

    if (!file3.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Error al leer archivo";

    QTextStream textStream3(&file3);

    while (!textStream3.atEnd())
        keywordPatterns3 << textStream3.readLine();
    file3.close();

    foreach (const QString &pattern3, keywordPatterns3) {
        rule3.pattern = QRegExp(pattern3);
        rule3.format = keywordFormat;
        highlightingRules.append(rule3);
    }

    rule3.pattern = QRegExp("//[^\n]*");
    rule3.format = singleLineCommentFormat;
    highlightingRules.append(rule3);

    functionFormat.setForeground(QColor("#00979C"));
    rule3.pattern = QRegExp("\\b[A-Za-z0-9_.]+(?=\\()");
    rule3.format = functionFormat;    
}
