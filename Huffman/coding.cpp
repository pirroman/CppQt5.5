#include "huffman_window.h"

namespace {
    void write_service_info(QDataStream &newFile_stream, QHash<char, int> &pairs_symbol_and_frequency)
    {
        int amount_alphabet_of_code = pairs_symbol_and_frequency.size();
        newFile_stream.writeRawData((char*) &amount_alphabet_of_code, sizeof(int));

        for (auto iterator = pairs_symbol_and_frequency.begin(); iterator != pairs_symbol_and_frequency.end(); ++iterator)
        {
            newFile_stream.writeRawData((char*)&iterator.key()  , sizeof(char));
            newFile_stream.writeRawData((char*)&iterator.value(), sizeof(int));
        }//endfor
    }//endfunction

    void write_data(QFile &file_for_compressing, QDataStream &newFile_stream, QDataStream &compressing_file, \
                                                    QHash<char, QVector<bool> > &pairs_symbol_and_prefixCode)
    {
        QVector<bool> prefixCode_reading_symbol;
        quint8 readingSymbol    = 0;
        quint8 bufferWriteByte  = 0;
        int    counter_bits     = 7;

        while(!file_for_compressing.atEnd())
        {
            compressing_file.readRawData((char*)&readingSymbol, sizeof(quint8));
            prefixCode_reading_symbol = pairs_symbol_and_prefixCode.value((char)readingSymbol);

            for(int i(0); i < prefixCode_reading_symbol.size(); ++i, --counter_bits)
            {
                bufferWriteByte |= prefixCode_reading_symbol.at(i) << counter_bits;
                if (!counter_bits)
                {
                    newFile_stream.writeRawData((char*) &bufferWriteByte, sizeof(quint8));
                    bufferWriteByte = 0;
                    counter_bits    = 7;
                } //endif
            }//endfor
        }//endwhile
        if(bufferWriteByte)
            newFile_stream.writeRawData((char*) &bufferWriteByte, sizeof(quint8));
    }//end function
}//end namespace

void Huffman_window::coding(QFile &file_for_compressing)
{
    QHash<char, int> pairs_symbol_and_frequency;
    setFrequency_for_symbols(pairs_symbol_and_frequency, file_for_compressing);

    QList<node_ptr> list_nodes_of_binaryTree;
    create_binaryTree(pairs_symbol_and_frequency, list_nodes_of_binaryTree);
    node_ptr root = list_nodes_of_binaryTree.front();

    QVector<bool> prefixCode;
    QHash<char, QVector<bool> > pairs_symbol_and_PrefixCode;
    create_prefixCode(root, prefixCode, pairs_symbol_and_PrefixCode, pairs_symbol_and_frequency);

    write_compressedFile(file_for_compressing, pairs_symbol_and_PrefixCode, pairs_symbol_and_frequency);
}

void Huffman_window::setFrequency_for_symbols(QHash<char, int> &pairs_symbol_and_frequency, QFile &file_for_compressing)
{
    file_for_compressing.seek(0);
    QDataStream file_input_stream(&file_for_compressing);
    quint8 reading_symbol = 0;

    while(!file_for_compressing.atEnd())
    {
        file_input_stream.readRawData((char*) &reading_symbol, sizeof(quint8));
        pairs_symbol_and_frequency[(char)reading_symbol]++;
    }

    file_for_compressing.seek(0);
}
/***************************** binary Tree **************************
*                                  root = (l1 + r1)
*                              _____|_____
*                             |           |
*                     l1 = (l12 + r12) r1 = (l22 + r22)
*                           __|__       __|__
*                          |     |     |     |
*                         l12   r12   l22   r22*
*********************************************************************/
void Huffman_window::create_binaryTree(QHash<char, int> &pairs_symbol_and_frequency, QList<node_ptr> &list_nodes_of_binaryTree)
{
    for (QHash<char, int>::iterator iterator = pairs_symbol_and_frequency.begin(); iterator != pairs_symbol_and_frequency.end(); ++iterator)
    {
        node_ptr newNode(new node);
        newNode->frequncy_symbol = iterator.value();
        newNode->symbol          = iterator.key  ();
        list_nodes_of_binaryTree.push_back(newNode);
    }

    while (list_nodes_of_binaryTree.size() != 1)
    {
        qSort(list_nodes_of_binaryTree.begin(), list_nodes_of_binaryTree.end(), compare_for_sort());

        node_ptr left_child_node  = list_nodes_of_binaryTree.front();
        list_nodes_of_binaryTree.pop_front();
        node_ptr right_child_node = list_nodes_of_binaryTree.front();
        list_nodes_of_binaryTree.pop_front();
        node_ptr branch_parent_node(new node(left_child_node, right_child_node));
        list_nodes_of_binaryTree.push_back(branch_parent_node);
    }
}

// Walking on tree
void Huffman_window::create_prefixCode(node_ptr root, QVector<bool> &prefixCode, QHash<char, QVector<bool> > &pairs_symbol_and_prefixCode,\
                                                                                             QHash<char, int> &pairs_symbol_and_frequency  )
{
    if (root->left != nullptr)
    {
        prefixCode.push_back(0);
        create_prefixCode(root->left, prefixCode, pairs_symbol_and_prefixCode,\
                                                  pairs_symbol_and_frequency  );
    }
    if (root->right != nullptr)
    {
        prefixCode.push_back(1);
        create_prefixCode(root->right, prefixCode, pairs_symbol_and_prefixCode,\
                                                   pairs_symbol_and_frequency   );
    }

    if (pairs_symbol_and_frequency.contains(root->symbol))
    {
        pairs_symbol_and_prefixCode[root->symbol] = prefixCode;
    }

    if(!prefixCode.empty()) prefixCode.pop_back();
}

void Huffman_window::write_compressedFile(QFile &file_for_compressing, QHash<char, QVector<bool> > &pairs_symbol_and_prefixCode,\
                                                                                   QHash<char, int> &pairs_symbol_and_frequency )
{
    QString name_for_new_compressing_file = QFileDialog::getSaveFileName(this,tr("Save encoding file"), "",
                                                                 tr("Address Book (*.huf);;All Files (*)"));
    if (name_for_new_compressing_file.isEmpty())
    {
        QMessageBox::critical(NULL, tr("ERROR"), tr("Input name!"));
        return;
    }
    QFile newFile(name_for_new_compressing_file);
    if (!newFile.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("don't work. Push ok."),file_for_compressing.errorString());
        return;
    }

    QDataStream newFile_stream (&newFile);
    QDataStream compressingFile(&file_for_compressing);
    file_for_compressing.seek(0);

    write_service_info(newFile_stream, pairs_symbol_and_frequency);
    write_data        (file_for_compressing, newFile_stream, \
                      compressingFile, pairs_symbol_and_prefixCode);

    file_for_compressing.seek(0);
    newFile.close();
}
