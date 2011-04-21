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
        *  a private static method that takes in a pointer to the alignment object
        *  and writes the alignment to a file.
        *  @param File A pointer to the deisired file name
        *  @param alignment A pointer to the aligned genotypes
        */
        static void FileWrite(Alignment alignment)
        {

        }

         /**
         *  a private static method that takes in a pointer to the sequence object
         *  and writes the sequence to a file.
         *  @param File A pointer to the desired file name
         *  @param sequence A pointer to the sequence of the genotypes
         */
        static void FileWrite(Sequence sequence)
        {
            ofstream toaster;
            toaster.open ("m9848OUTPUT.txt");
            toaster << sequence.GetSequence();
            toaster.close();
        }

        /**
         *  a private static method that takes in a pointer to the result object
         *  and writes the result to a file.
         *  @param File A pointer to the desired file name
         *  @param result A pointer to the result from the aligned genotypes
         */

        /**
        static void Writer::AlignWrite(string *File, Result *result)
        {
            FILE *pFile;
            FILE *rFile;
            pFile = fopen("something.fasta", "wb");
            rFile = fopen("result.txt", "wb");
            fwrite(result, 1, sizeof(result), rFile);
            fclose(pFile);
            fclose(rFile);
        }
        */
    public:
        /**
         *  a public static method that calls the private method AlignWrite
         *  @param Path
         *  @param alignment A pointer to the aligned genotypes
         */
        static void Write(Alignment alignment)
        {
            FileWrite(alignment);
        }

        /**
         *  a public static method that calls the private method SeqWrite
         *  @param Path
         *  @param sequence A pointer to the sequence of the genotypes
         */
        static void Write(Sequence sequence)
        {
            FileWrite(sequence);
        }

        /**
         *  a public static method that calls the private method AlignWrite that writes the results
         *  @param Path
         *  @param result A pointer to the result of the aligned genotypes
         */
         /**
        static void Writer::Write(string Path, Result *result)
        {
            cout<<"Import Skynett" << endl;
        }
*/
};

#endif // _WRITER_H
