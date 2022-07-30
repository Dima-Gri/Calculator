#ifndef STYLES_H
#define STYLES_H
#include <QApplication>

const static QString style_for_text_edit = "QTextEdit{"
                              "background-color: rgb(240, 240, 240);"
                              "border: 0px; }";

const static QString style_for_nums = "QPushButton{"
                         "border: 1px solid #000000 ;"
                         "background-color: rgb(255,255,255);}"
                         "QPushButton:hover{"
                         "background-color: rgb(192, 192, 192);}";

const static QString style_for_operation = "QPushButton{"
                              "background-color: rgb(225,225,225);}"
                              "QPushButton:hover{"
                              "background-color: rgb(192, 192, 192); } ";

const static QString style_for_advanced_buttons = "QPushButton{"
                                     "background-color: rgb(245,245,245);}"
                                     "QPushButton:hover{"
                                     "background-color: rgb(192, 192, 192); } ";

const static QString style_for_equiv =
        "QPushButton{"
        "background-color: rgb(255,130,00);"
        "border-radius: 4px transparent;"
        "border-bottom: 3px transparent;"
        "border-right: 2px transparent;"
        "border-left: 2px transparent;"
        "border-radius: 10px;"
        "margin: 2px;}"
        "QPushButton:hover{"
        "background-color: rgb(255, 153, 0); } ";

#endif // STYLES_H
