#include <iostream>
#include <string>
#include "CIMModel.hpp"
#include "IEC61970.hpp"
#include "CIMExceptions.hpp"
#include <regex>
#include <dirent.h>
#include <fstream>
#ifndef CGMES_BUILD
#include "CIMNamespaces.hpp"
#endif


std::string getFileName(const std::string& s) {

    char sep = '/';

    size_t i = s.rfind(sep, s.length());
    if (i != std::string::npos) {
        return(s.substr(i+1, s.length() - i));
    }

    return("");
}


std::vector<std::string> search_folder(const char *path) {

	struct dirent *ent = NULL;
	DIR *pDir;
	pDir = opendir(path);
	std::vector<std::string> files;
	if(NULL == pDir){
		std::cerr << "The specified directory does not exist. " << path<<
				" Maybe you want to use the option -f to read a single File" << std::endl;
		return files;
	}

	while (NULL != (ent = readdir(pDir))) {
		std::string _path(path);
		std::string _dirName(ent->d_name);
		if(strcmp(ent->d_name,".") == 0 || strcmp(ent->d_name,"..") == 0 )
			continue;
		std::string file_path = _path + _dirName;
		files.push_back(file_path);
	}

	return files;
}

inline bool ends_with(std::string const & value, std::string const & ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

std::string formatName(std::string name) {
	if (name.length() > 12) {
		name.resize(10, ' ');
		name += "..  ";
	}
	else {
		name.resize(14, ' ');
	}
	return name;
}

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		std::cout << "Usage: example <cim file> [additional cim files]" << std::endl;
		std::cout << "Provide at least one cim file" << std::endl;
		return 1;
	}

	CIMModel someModel;
	someModel.setDependencyCheckOff();

    bool writeToFile = false;
    std::string output_file_name;
    std::string some= "wtf";
    std::regex match(".*xml$");


    int c;
	for(int i = 1; i < argc; i++)
	{

        if(some.compare(argv[i]) == 0){
            writeToFile = true;
			continue;
        }
		std::vector<std::string> files;
		if(!someModel.addCIMFile(argv[i]))
		{

			if(!ends_with(argv[i], "/")){
				char dest[strlen(argv[i])];
				strcpy(dest, argv[i]);
				files = search_folder(strcat(dest, "/"));
			}
			else{
				files = search_folder(argv[i]);
			}
			for (auto f : files)
			{
				if(!std::regex_match(f, match) ){
					std::cout << "is not a .xml file" << ( f )<< " skipping" << std::endl;
				}else{
					//std::cout << "CIM-XML file is:" << f << std::endl;
                    someModel.addCIMFile(f);
				}
			}
			if(files.size() == 0){
				std::cout << "File ' " << argv[i] << " ' is no XML or does not exist" << std::endl;
			}else{

                output_file_name = getFileName(argv[i]);
            }

		};
	}

	try
	{
		someModel.parseFiles();
	}
	catch(std::runtime_error &exp)
	{
		std::cerr << exp.what() << std::endl;
	}

    std::ofstream myfile;
    if(writeToFile == true){
        myfile.open (output_file_name+".IdentifiedObjects.txt");
    }
    for (BaseClass* Object : someModel.Objects)
	{
		if(CIMPP::IdentifiedObject* IdObj = dynamic_cast<CIMPP::IdentifiedObject*>(Object))
		{
			if(!IdObj->name.empty()) {
				static unsigned int i = 0;
				std::string outputName = formatName(IdObj->name);
                std::cout << outputName;
                if(writeToFile == true){
                    myfile << formatName(IdObj->name) << std::endl;
                }
				i++;
				if (i % 5 == 0) {
					std::cout << std::endl;
				}
			}
		}
	}
    if(writeToFile == true){
        myfile.close();
    }
	std::cout << std::endl;
	return 0;
}
