#include <fstream>

/* FUNÇÃO QUE EXPORTA UM DADO Payload PARA UM DADO
ARQUIVO ESPECIFICADO EM NOME PELA STRING path */
void payload_to_csv(Payload p, std::string path)
{
    try
    {
        std::ofstream file(path);
        if(!file.is_open())
        {
            std::cerr << "couldn't open file " + path << std::endl;
        }

        file << Consts::payload_header << std::endl;
        
        for(Epoch ep : p.epochs)
        {
            file << ep.get_string() << std::endl;
        }

        file.close();

    } catch (std::exception& ex)
    {
        std::cerr << "ERRO: " << ex.what() << std::endl;
    }
}