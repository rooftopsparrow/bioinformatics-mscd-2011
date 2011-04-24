#ifndef _WRITER_H
#define _WRITER_H

#include <string>
#include <fstream>
#include <iostream>
#include "Alignment.h"
#include "Sequence.h"

class Writer
{
    private:
        /**
         * @brief Formats sequences in output files
         * Formats the one line string stored in a sequence's genotype
         * for better results when printing to a file.
         * @param gene A sequence's genotype
         */
        static string GeneFormat(string gene)
        {
            int temp = gene.length() / 70;
            int i;

            /* compensate for the characters that will be added by formatting */
            temp = (gene.length() + temp) / 70;

            for(i = 1; i <= temp; i++) {
                gene.insert(i * 70 - 1, 1, '\n');
            }

            return gene;
        }
    public:

       /**
        *  A public static method that takes in a pointer to the alignment object
        *  and writes the alignment to a file.
        *  @param File A pointer to the deisired file name
        *  @param alignment A pointer to the aligned genotypes
        */
        static void FileWrite(Alignment alignment)
        {

        }

         /**
         *  A public static method that takes in a pointer to the sequence object
         *  and writes the sequence to a file.
         *  @param sequence A pointer to a sequence
         */
        static void FileWrite(Sequence sequence)
        {
            ofstream toaster;
            toaster.open ((sequence.GetFilePath()+=".txt").c_str());
            toaster << sequence.GetName() << endl;
            toaster << GeneFormat(sequence.GetSequence()) << endl;
            toaster.close();
        }


        static void FileWrite(Alignment align_in, string name)
        {
            ofstream align_out;

            align_out.open((name += ".txt").c_str());
            align_out << align_in.GetSeqA().GetName() << endl;
            align_out << GeneFormat(align_in.GetSeqA().GetSequence()) << endl << endl;
            align_out << align_in.GetSeqB().GetName() << endl;
            align_out << GeneFormat(align_in.GetSeqB().GetSequence()) << endl << endl;
            align_out << "Score: " << align_in.GetScore() << endl;
            align_out.close();
        }
};

#endif // _WRITER_H
