#pragma once

#include <fstream>

void payload_to_csv(Payload p, std::string path)
{
    try
    {
        std::ofstream archive (path);
        if(!archive.is_open())
        {
            std::cerr << "couldn't open file" << std::endl;
        }

        archive << Consts::payload_header << std::endl;
        
        for(Epoch ep : p.epochs)
        {
            archive << ep.get_string() << std::endl;
        }

    } catch (std::exception& ex)
    {
        std::cerr << "ERRO: " << ex.what() << std::endl;
    }
}