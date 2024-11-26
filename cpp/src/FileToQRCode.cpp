#include "QrCode.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
    if(argc < 1)
    {
        std::cout << "Uso: " << argv[0] << " arquivo" << std::endl;
        return -1;
    }

    std::ifstream inputFile(argv[1]);

    std::string line, content;

    while(std::getline(inputFile, line))
    {
        content += line + "\n";
    }
    inputFile.close();

    try
    {
        qrcodegen::QrCode code = qrcodegen::QrCode::encodeText(content.c_str(), qrcodegen::QrCode::Ecc::LOW);
        std::ofstream outputFile("out.svg");
        outputFile << code.toSvgString(4);
        outputFile.close();
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
