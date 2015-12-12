#ifndef WINDOW_FOR_MORE_H
#define WINDOW_FOR_MORE_H

#include <QtWidgets/QMainWindow>
#include "ui_window_for_more.h"

class window_for_more : public QMainWindow
{
	Q_OBJECT

public:
    window_for_more(QWidget *parent = 0);
    ~window_for_more();

    void building_table_frequency      (QHash<char, int> &pairs_symbol_and_frequency);
    void building_table_with_prefixCode(QHash<char, QVector<bool> > &prefixCodes);
private:
    Ui::window_for_more *ui;
    enum {
        first_column,
        second_column
    };
};

#endif // WINDOW_FOR_MORE_H
