/*
** EPITECH PROJECT, 2020
** IComponent
** File description:
** IComponent
*/

#ifndef __ICOMPONENT__
#define __ICOMPONENT__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <memory>
#include <array>
#include <regex>
#include <map>

class Component;

namespace nts {
    enum Tristate : short;
}

struct Int2 {
  int col[2];
};

enum Type {
    OUTPUT = 0,
    INPUT = 1
};

typedef struct pin_s
{
    Type type;
    std::size_t pin;
    Component *comp;
    nts::Tristate state;
    struct pin_s *link;
} pin_t;

namespace nts
{
    enum Tristate : short {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setType(std::string) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual std::vector<pin_t> &getPins() = 0;
            virtual std::vector<Int2> &getTruthTable() = 0;
            virtual std::string getType() const = 0;
            virtual void setPin(size_t pin, Type type) = 0;
            virtual void setPinState(size_t pin, nts::Tristate state) = 0;
            virtual void setTruthTable(std::vector<Int2> table) = 0;
            virtual void setComp(std::vector<std::unique_ptr<nts::IComponent>> &) = 0;
    };
}

#endif /**/
