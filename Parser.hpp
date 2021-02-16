/*
** EPITECH PROJECT, 2020
** Parser
** File description:
** Parser
*/

#ifndef __PARSER__
#define __PARSER__

#include "IComponent.hpp"

class Parser {
    private:
        int _inputs = 0;
        std::vector<std::string> _output;
        std::vector<std::string> _file;
        void processFile(std::string);
        int checkFile(std::string);
    public:
        Parser();
        ~Parser();
        std::map<std::string, std::unique_ptr<nts::IComponent>> generate(std::string);
        int getInputs() const;
        std::vector<std::string> getOutput() const;
};

#endif /**/
