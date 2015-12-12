#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QScrollBar>
#include <QTextStream>
#include <QHash>
#include <memory>
#include "window_for_more.h"

namespace node_struct {
    class node_for_binaryTree
    {
    public:
        int frequncy_symbol;
        char symbol;
        std::shared_ptr<node_for_binaryTree> left;
        std::shared_ptr<node_for_binaryTree> right;

        node_for_binaryTree()
        {
            left = right    = nullptr;
            frequncy_symbol = 0;
            symbol          = 0;
        }

        node_for_binaryTree(std::shared_ptr<node_for_binaryTree> leftChild, std::shared_ptr<node_for_binaryTree> rightChild)
        {
            left            = leftChild;
            right           = rightChild;
            frequncy_symbol = leftChild->frequncy_symbol + rightChild->frequncy_symbol;
        }
    };

    class functor_compare_for_sort
    {
    public:
        bool operator()(const std::shared_ptr<node_for_binaryTree> left, const std::shared_ptr<node_for_binaryTree> right) const
        {
            int different = left->frequncy_symbol - right->frequncy_symbol;

            if (different < 0 || (!different && left->symbol < right->symbol))
            {
                return true;
            } else
            {
                return false;
            }
        }
    };
}

namespace Ui {
class Huffman_window;
}

class Huffman_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Huffman_window(QWidget *parent = 0);
    ~Huffman_window();
public slots:
    void on_button_for_coding_clicked   ();
    void on_button_for_decoding_clicked ();
    void on_button_for_more_clicked     ();

private slots:
    void loadText_in_textBrowser(int);
    void setEnabled_moreButton  ();

private:
    enum { amountStrings_for_view = 10 }; //amount strings loading in textBrowser on start

    Ui::Huffman_window *ui;
    window_for_more    *more_window;

    typedef node_struct::node_for_binaryTree node;
    typedef std::shared_ptr<node> node_ptr;
    typedef node_struct::functor_compare_for_sort compare_for_sort;

    void printText_in_textBrowser(QFile &file_for_inputText);
    void setFrequency_for_symbols(QHash<char, int> &pairs_symbol_and_frequency, QFile &file_for_compressing);
    void create_binaryTree       (QHash<char, int> &pairs_symbol_and_frequency, QList<node_ptr> &listNodes_of_binaryTree);
    void create_prefixCode       (node_ptr root, QVector<bool> &prefixCode ,QHash<char, QVector<bool> > &pairs_symbol_and_prefixCode, \
                                                                                        QHash<char, int> &pairs_symbol_and_frequency);
    void write_compressedFile    (QFile &file_for_compressing, QHash<char, QVector<bool> > &pairs_symbol_and_prefixCode,
                                                                            QHash<char, int> &pairs_symbol_and_frequency);
    void coding  (QFile &file_for_compressing);
    void decoding(QFile &compressFile, QFile &new_decodingFile);
};

#endif // HUFFMAN_H
