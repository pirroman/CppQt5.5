#include "huffman_window.h"
#include "ui_huffman_window.h"

Huffman_window::Huffman_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Huffman_window)
{
    ui->setupUi(this);
    more_window = nullptr;
    ui->button_for_more->setVisible(false);
    connect(ui->textBrowser, SIGNAL(textChanged()),
            this, SLOT  (setEnabled_moreButton()) );
}

Huffman_window::~Huffman_window()
{
    delete more_window;
    delete ui;
}

void Huffman_window::setEnabled_moreButton()
{
    ui->button_for_more->setVisible(ui->textBrowser->toPlainText().size());
}

void Huffman_window::on_button_for_coding_clicked()
{
    QString nameFile_for_compressing = QFileDialog::getOpenFileName(this,tr("Select file"), "", \
                                                                    tr("Text file (*.txt);;All Files (*)"));

    if (nameFile_for_compressing.isEmpty())
    {
        QMessageBox::critical(NULL, tr("ERROR"), tr("select file"));
        return;
    }
    QFile file(nameFile_for_compressing);

    if (!file.open(QIODevice::ReadOnly))
    {
            QMessageBox::information(NULL, tr("File don't reading!"), file.errorString());
            return;
    }
    ui->textBrowser->clear();
    ui->textBrowser->setDocumentTitle(nameFile_for_compressing);
    printText_in_textBrowser(file);

    coding(file);

    file.close();
}

void Huffman_window::on_button_for_decoding_clicked()
{
    QString nameFile_of_compressedFile = QFileDialog::getOpenFileName(this, tr("Select file for decoding"), "", \
                                                                            tr("huffman file (*.huf);;All Files (*)"));
    if (nameFile_of_compressedFile.isEmpty())
    {
        QMessageBox::critical(NULL, tr("ERROR"), tr("select file"));
        return;
    }
    QFile compressedFile(nameFile_of_compressedFile);

    if (!compressedFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(NULL, tr("File don't reading!"), compressedFile.errorString());
        return;
    }

    QString name_for_newDecompessFile = QFileDialog::getSaveFileName(this, tr("Save decoding file"), "", \
                                                                tr("Address Book (*.txt);;All Files (*)"));
    if (name_for_newDecompessFile.isEmpty())
    {
        QMessageBox::critical(NULL, tr("ERROR"), tr("Input name!"));
        return;
    }
    QFile newFile(name_for_newDecompessFile);
    if (!newFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("Unable to open file"), newFile.errorString());
        return;
    }

    decoding(compressedFile, newFile);

    newFile.close();
    if (!newFile.open(QIODevice::ReadOnly))//open new file for input on textBrowser
    {
        QMessageBox::information(this, tr("Unable to open file"), newFile.errorString());
        return;
    }

    ui->textBrowser->clear();
    ui->textBrowser->setDocumentTitle(name_for_newDecompessFile);
    printText_in_textBrowser(newFile);

    compressedFile.close();
    newFile.close();
}


void Huffman_window::printText_in_textBrowser(QFile &file)
{
    QTextStream input_fstream(&file);
    int fourtyStrings = amountStrings_for_view << 2;
    for (int i(0); !(ui->textBrowser->toPlainText().size() == file.size()) && i < fourtyStrings; ++i)
        ui->textBrowser->append(input_fstream.readLine());

    ui->textBrowser->verticalScrollBar()->setValue(0);
    connect((QScrollBar *) ui->textBrowser->verticalScrollBar(), SIGNAL(valueChanged(int)), \
                                                    this, SLOT(loadText_in_textBrowser(int)));
}

void Huffman_window::loadText_in_textBrowser(int change_position_verticalScrollBar)
{
    QString nameFile = ui->textBrowser->documentTitle();
    if (nameFile.isEmpty())
    {
        QMessageBox::critical(NULL, tr("ERROR"), tr("File not found"));
        return;
    }
    QFile file(nameFile);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(NULL, tr("File don't reading!"), file.errorString());
        return;
    }

    QTextStream stream_for_input_on_textBrowser(&file);
    file.seek(ui->textBrowser->toPlainText().size());

    int maximum_position_verticalScrollBar = ui->textBrowser->verticalScrollBar()->maximum() - 2;
    if (change_position_verticalScrollBar > maximum_position_verticalScrollBar)
    {
        ui->textBrowser->verticalScrollBar()->setValue(maximum_position_verticalScrollBar >> 1);
    }

    for (int i(0); !file.atEnd() && i < amountStrings_for_view; ++i)
        ui->textBrowser->append(stream_for_input_on_textBrowser.readLine());

    if (ui->textBrowser->toPlainText().size()==file.size())
    {
            disconnect((QScrollBar *) ui->textBrowser->verticalScrollBar(), SIGNAL(valueChanged(int)), \
                                                                 this, SLOT(loadText_in_textBrowser(int)));
    }

    file.close();
}

void Huffman_window::on_button_for_more_clicked()
{
    more_window = new window_for_more;

    QString nameFile_for_analysis = ui->textBrowser->documentTitle();
    if (nameFile_for_analysis.isEmpty())
    {
        QMessageBox::critical(NULL, tr("ERROR"), tr("File not found"));
        return;
    }
    QFile file(nameFile_for_analysis);

    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(NULL, tr("File don't reading!"), file.errorString());
        return;
    }

    file.seek(0);
    QHash<char, int> pairs_symbol_and_frequency;
    setFrequency_for_symbols(pairs_symbol_and_frequency, file);
    more_window->building_table_frequency(pairs_symbol_and_frequency);

    QList<node_ptr> list_nodes_of_tree;
    create_binaryTree(pairs_symbol_and_frequency, list_nodes_of_tree);
    node_ptr root = list_nodes_of_tree.front();

    QVector<bool> prefixCode;
    QHash<char, QVector<bool> > pairs_symbol_and_prefixCode;
    create_prefixCode(root, prefixCode, pairs_symbol_and_prefixCode, pairs_symbol_and_frequency);
    more_window->building_table_with_prefixCode(pairs_symbol_and_prefixCode);

    more_window->show();
    file.close();
}
