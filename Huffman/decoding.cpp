#include "huffman_window.h"

namespace {
    typedef node_struct::node_for_binaryTree node;
    typedef std::shared_ptr<node> node_ptr;

    void load_service_info(QDataStream &compressFile_stream, QHash<char, int> &pairs_symbol_and_frequency)
    {
        int amount_alhpabet_of_code = 0;
        compressFile_stream.readRawData((char*) &amount_alhpabet_of_code, sizeof(int));

        char symbol              = 0;
        int  frequency_of_symbol = 0;
        for(;amount_alhpabet_of_code; --amount_alhpabet_of_code)
        {
            compressFile_stream.readRawData((char*) &symbol, sizeof(char));
            compressFile_stream.readRawData((char*) &frequency_of_symbol, sizeof(int));
            pairs_symbol_and_frequency[symbol] = frequency_of_symbol;
        }
    }

    void write_data(QFile &compressFile, QDataStream &compressFile_stream, QDataStream &new_decodingFile_stream, node_ptr root)
    {
        quint8 reading_byte      = 0;
        node_ptr start           = root;
        int counter_bits         = 7;
        int pointer_on_next_node = 0;

        compressFile_stream.readRawData((char*) &reading_byte, sizeof(quint8));
        bool flag_for_continue_reading = true;
        for(;flag_for_continue_reading; --counter_bits)
        {
            pointer_on_next_node = reading_byte & (1 << counter_bits);
            if (pointer_on_next_node && start->right)
                start = start->right;
            else if(!pointer_on_next_node && start->left)
                start = start->left;
            if (start->left == nullptr && start->right == nullptr && start->frequncy_symbol)
            {
                new_decodingFile_stream.writeRawData((char*)&start->symbol, sizeof(quint8));
                start = root;
            }
            if (!counter_bits && !compressFile.atEnd())
            {
                counter_bits = 7;
                compressFile_stream.readRawData((char*)&reading_byte, sizeof(quint8));
            } else if(!counter_bits && compressFile.atEnd())
            {
                flag_for_continue_reading = false;
            }
        }//endfor
    }//end function
}// end namespace

void Huffman_window::decoding(QFile &compressFile, QFile &new_decodingFile)
{
    compressFile.seek(0);
    QHash<char, int> pairs_symbol_and_frequency;
    QDataStream compressFile_stream(&compressFile);
    load_service_info(compressFile_stream, pairs_symbol_and_frequency);

    QList<node_ptr> list_nodes_of_binaryTree;
    create_binaryTree(pairs_symbol_and_frequency, list_nodes_of_binaryTree);
    node_ptr root = list_nodes_of_binaryTree.front();

    QDataStream new_decodingFile_stream(&new_decodingFile);

    write_data(compressFile, compressFile_stream, new_decodingFile_stream, root);

    new_decodingFile.seek(0);
}
