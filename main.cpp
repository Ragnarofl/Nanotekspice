/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** main
*/

#include "Component.hpp"
#include "Factory.hpp"
#include "IComponent.hpp"
#include "Parser.hpp"

int checkInputs(char **av, std::map<std::string, std::unique_ptr<nts::IComponent>> &comp_map)
{
    int state;
    size_t s = 0;
    std::string tmp;
    std::string str1;
    std::string str2;

    for (int i = 0; av[i]; i++) {
        tmp = av[i];
        if ((s = tmp.find("=")) == std::string::npos)
            return 1;
        str1 = tmp.substr(0, s);
        str2 = tmp.substr(s + 1);
        state = std::stoi(str2);
        if (comp_map.find(str1) == comp_map.end())
            return 1;
        if (state == 1)
            comp_map[str1]->setPinState(1, nts::TRUE);
        else if (state == 0)
            comp_map[str1]->setPinState(1, nts::FALSE);
        else if (state == -1)
            comp_map[str1]->setPinState(1, nts::UNDEFINED);
        else {
            std::cerr << "Invalid pin state for pin " + str1 << std::endl;
            return 1;
        }
    }
    return 0;
}

int update_input(std::string line, std::map<std::string, std::unique_ptr<nts::IComponent>> &comp_map)
{
    size_t s = line.find("=");
    std::string str1 = line.substr(0, s);
    std::string str2 = line.substr(s + 1);
    int state = std::stoi(str2);

    if (comp_map.find(str1) != comp_map.end() && comp_map[str1]->getType() == "input") {
        if (state == 1)
            comp_map[str1]->setPinState(1, nts::TRUE);
        else if (state == 0)
            comp_map[str1]->setPinState(1, nts::FALSE);
        else if (state == -1)
            comp_map[str1]->setPinState(1, nts::UNDEFINED);
        else {
            std::cerr << "Invalid pin state for pin " + str1 << std::endl;
            return (1);
        }
    }
    return (0);
}

int main(int ac, char **av)
{
    Parser parser;
    Factory factory;
    std::vector<nts::Tristate> state;
    std::regex input("^\\w+=\\w+$");
    std::map<std::string, std::unique_ptr<nts::IComponent>> comp_map;

    if (ac < 2)
        return 84;
    comp_map = parser.generate(av[1]);
    if (comp_map.empty() || parser.getInputs() != ac - 2 || parser.getOutput().empty())
        return 84;
    if (checkInputs(av + 2, comp_map))
        return 84;
    state.clear();
    for (std::string str : parser.getOutput())
        state.push_back(comp_map[str]->compute());
    std::vector<std::string> outpt = parser.getOutput();
    for (long unsigned int i = 0; i < outpt.size(); i++)
        std::cout << outpt[i] << "=" << state[i] << std::endl;
    state.clear();
    for (std::string line; 1;) {
        std::cout << "> ";
        if (!std::getline(std::cin, line))
            return 84;
        if (line == "simulate") {
            state.clear();
            for (std::string str : parser.getOutput())
                state.push_back(comp_map[str]->compute());
        }
        if (line == "loop")
            while (1)
                for (std::string str : parser.getOutput())
                    state.push_back(comp_map[str]->compute());
        if (line == "display" && !state.empty()) {
            std::vector<std::string> outpt = parser.getOutput();
            for (long unsigned int i = 0; i < outpt.size(); i++)
                std::cout << outpt[i] << "=" << state[i] << std::endl;
            state.clear();

        }
        if (line == "dump")
            for (std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator it = comp_map.begin(); it != comp_map.end(); it++)
                it->second->dump();
        if (std::regex_match(line, input))
            update_input(line, comp_map);
        if (line == "exit")
            return 0;
    }
    return 0;
}
