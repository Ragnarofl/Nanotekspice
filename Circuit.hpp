/*
** EPITECH PROJECT, 2020
** Circuit
** File description:
** Circuit
*/

#ifndef __CIRCUIT__
#define __CIRCUIT__

#include "Component.hpp"

class Circuit : public Component {
    private:
        std::string _value;
    public:
        Circuit(const std::string &);
        ~Circuit() final;
};

#endif /**/
