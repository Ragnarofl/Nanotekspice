/*
** EPITECH PROJECT, 2020
** Parser
** File description:
** Parser
*/

#include "Parser.hpp"
#include "Factory.hpp"
#include "Component.hpp"

Parser::Parser() {}

Parser::~Parser() {}

void Parser::processFile(std::string file)
{
    std::ifstream afile(file, std::ios::in);
    std::string line;

    if (afile.is_open()) {
        while (std::getline(afile, line))
            if (line[0] != '#' && line[0] != '\0')
                _file.push_back(line);
    } else
        std::cerr << "Unable to open file" << std::endl;
}

int Parser::checkFile(std::string file)
{
    size_t i = 0;
    std::regex chip("^(input|output|4001|4011|4013|4030|4040|4069|4071|4081)\\t\\t\\w+$");
    std::regex link("^\\w+:\\d\\t\\t\\w+:\\d+$");

    this->processFile(file);
    if (_file.empty())
        return 0;
    if (_file[i].find(".chipsets:") == std::string::npos)
        return 0;
    i++;
    for (; i < _file.size(); i++)
        if (_file[i].find(".links:") != std::string::npos)
            break;
        else if (!std::regex_match(_file[i], chip))
            return 0;
    i++;
    for (; i < _file.size(); i++) {
        if (!std::regex_match(_file[i], link))
            return 0;
    }
    return (1);
}

std::map<std::string, std::unique_ptr<nts::IComponent>> Parser::generate(std::string file)
{
    size_t i = 1;
    size_t s = 0;
    size_t t = 0;
    Factory factory;
    std::map<std::string, std::unique_ptr<nts::IComponent>> comp_map;
    std::string str1;
    std::string str2;

    if (!this->checkFile(file)) {
        std::cerr << "Invalid file" << std::endl;
        return comp_map;
    }
    for (; i < _file.size(); i++) {
        if (_file[i].find(".links:") != std::string::npos)
            break;
        s = _file[i].find("\t");
        str1 = _file[i].substr(0, s);
        str2 = _file[i].substr(s + 2);
        comp_map[str2] = factory.createComponent(str1, str2);
        if (str1 == "output")
            _output.push_back(str2);
        if (str1 == "input")
            _inputs += 1;
    }
    i++;
    for (size_t x = 0, y = 0; i < _file.size(); i++) {
        s = _file[i].find("\t");
        str1 = _file[i].substr(0, s);
        str2 = _file[i].substr(s + 2);
        s = str1.find(":");
        t = str2.find(":");
        x = std::stoi(str1.substr(s + 1));
        y = std::stoi(str2.substr(t + 1));
        comp_map[str1.substr(0, s)]->setLink(x, *comp_map[str2.substr(0, t)].get(), y);
    }
    return comp_map;
}

int Parser::getInputs() const
{
    return _inputs;
}

std::vector<std::string> Parser::getOutput() const
{
    return _output;
}
