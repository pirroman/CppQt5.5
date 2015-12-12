#include "window_for_more.h"
#include "ui_window_for_more.h"

namespace {
    QString convert_quint8_in_QString(char char_element)
    {
        return QString(QChar(char_element));
    }
}

window_for_more::window_for_more(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::window_for_more)
{
	ui->setupUi(this);
    connect(ui->button_for_close, SIGNAL(clicked()), this, SLOT(close()));
}

window_for_more::~window_for_more()
{
	delete ui;
}

void window_for_more::building_table_frequency(QHash<char, int> &pairs_symbol_and_frequency)
{
    //Headers for columns of frequency table.
    QStringList horisontalHeader;
    ui->table_for_viewFrequencyChars->setRowCount(pairs_symbol_and_frequency.size());
    ui->table_for_viewFrequencyChars->setColumnCount(2);
    horisontalHeader.append("Symbol");
    horisontalHeader.append("Frequency");

    //Headers for rows of frequency table
    QStringList verticalHeader;
    for (int countRow = 0; countRow < pairs_symbol_and_frequency.size();)
    {
        verticalHeader.append(QString::number(++countRow, 10));
    }
    ui->table_for_viewFrequencyChars->setHorizontalHeaderLabels(horisontalHeader);
    ui->table_for_viewFrequencyChars->setVerticalHeaderLabels  (verticalHeader);

    int countElement = 0;
    for(auto iterator = pairs_symbol_and_frequency.begin(); iterator != pairs_symbol_and_frequency.end(); ++iterator, ++countElement)
    {
        QTableWidgetItem *symbolItem    = new QTableWidgetItem(convert_quint8_in_QString(iterator.key()));
        ui->table_for_viewFrequencyChars->setItem(countElement, first_column, symbolItem);

        QTableWidgetItem *frequencyItem = new QTableWidgetItem(QString::number(iterator.value(), 10));
        ui->table_for_viewFrequencyChars->setItem(countElement, second_column, frequencyItem);
    }

    ui->table_for_viewFrequencyChars->resizeRowsToContents();
    ui->table_for_viewFrequencyChars->resizeColumnsToContents();
}

void window_for_more::building_table_with_prefixCode(QHash<char, QVector<bool> > &prefixCodes)
{
    //Headers for columns of prefix codes table
    QStringList horizontalHeader;
    ui->table_for_viewPrefixCode->setRowCount(prefixCodes.size());
    ui->table_for_viewPrefixCode->setColumnCount(2);
    horizontalHeader.append("Symbol");
    horizontalHeader.append("Prefix code");

    QStringList verticalHeader;
    for (int countRow = 0; countRow < prefixCodes.size();)
    {
        verticalHeader.append(QString::number(++countRow, 10));
    }
    ui->table_for_viewPrefixCode->setHorizontalHeaderLabels(horizontalHeader);
    ui->table_for_viewPrefixCode->setVerticalHeaderLabels(verticalHeader);

    int countElement = 0;
    for (auto iterator = prefixCodes.begin(); iterator != prefixCodes.end(); ++iterator, ++countElement)
    {
        QTableWidgetItem *symbolItem = new QTableWidgetItem(convert_quint8_in_QString(iterator.key()));
        ui->table_for_viewPrefixCode->setItem(countElement, first_column, symbolItem);

        QString string_for_prefixCode = "";
        for (int i(0); i < iterator.value().size(); ++i)
        {
            string_for_prefixCode += iterator.value().at(i) ? '1':'0';
        }
        QTableWidgetItem *prefixCode = new QTableWidgetItem(string_for_prefixCode);
        ui->table_for_viewPrefixCode->setItem(countElement, second_column, prefixCode);
    }

    ui->table_for_viewPrefixCode->resizeRowsToContents();
    ui->table_for_viewPrefixCode->resizeColumnsToContents();
}
