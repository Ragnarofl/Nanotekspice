/*
** EPITECH PROJECT, 2020
** Component
** File description:
** Component
*/

#include "Component.hpp"

Component::Component(const std::string &value) : _value(value) {}

Component::~Component() {}

nts::Tristate Component::compute(std::size_t pin)
{
    int res;

    if (!_pins[pin - 1].link) {
        std::cerr << "The pin " << pin << " is not linked to anything" << std::endl;
        return nts::UNDEFINED;
    }
    if (_pins[pin - 1].comp->getType() == "input")
        return _pins[pin - 1].comp->getPins()[0].state;
    else if (_pins[pin - 1].comp->getType() == "output")
        return _pins[pin - 1].link->comp->compute(_pins[pin - 1].link->pin);
    if (_pins.size() > 2) {
        int x = _pins[0].link->comp->compute(_pins[0].link->pin);
        int y = _pins[1].link->comp->compute(_pins[1].link->pin);
        if (x == nts::UNDEFINED || y == nts::UNDEFINED)
            return nts::UNDEFINED;
        res = _pins[pin - 1].comp->getTruthTable()[x].col[y];
    } else {
        int x = _pins[0].link->comp->compute(_pins[0].link->pin);
        if (x == nts::UNDEFINED)
            return nts::UNDEFINED;
        res = _pins[pin - 1].comp->getTruthTable()[0].col[x];
    }
    if (res == 1)
        return nts::TRUE;
    else if (res == 0)
        return nts::FALSE;
    return nts::UNDEFINED;
}

std::string Component::getType() const
{
    return _type;
}

void Component::setType(std::string type)
{
    _type = type;
}

void Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    std::vector<pin_t> &otherPins = other.getPins();

    if (otherPins[otherPin - 1].link != NULL) {
        std::vector<pin_t> &otherNextPins = otherPins[otherPin - 1].link->comp->getPins();
        otherPin = otherPins[otherPin - 1].link->pin;
        _pins[pin - 1].link = &otherNextPins[otherPin - 1];
        otherNextPins[otherPin - 1].link = &_pins[pin - 1];
    } else {
        _pins[pin - 1].link = &otherPins[otherPin - 1];
        otherPins[otherPin - 1].link = &_pins[pin - 1];
    }
}

void Component::dump() const
{
    std::cout << _type + " " + _value << std::endl;
    for (pin_t p : _pins)
        std::cout << p.pin << " " << p.link->pin << " " << p.link->comp->getType() << std::endl;
}

std::vector<pin_t> &Component::getPins()
{
    return _pins;
}

std::vector<Int2> &Component::getTruthTable()
{
    return _truthTable;
}

void Component::setPin(size_t pin, Type type)
{
    pin_t newPin;

    newPin.pin = pin;
    newPin.type = type;
    newPin.comp = this;
    newPin.state = nts::UNDEFINED;
    newPin.link = NULL;
    _pins.push_back(newPin);
}

void Component::setPinState(size_t pin, nts::Tristate state)
{
    _pins[pin - 1].state = state;
}

void Component::setTruthTable(std::vector<Int2> table)
{
    _truthTable = table;
}

void Component::setComp(std::vector<std::unique_ptr<nts::IComponent>> &comps)
{
    _v_comp = std::move(comps);
}

/*std::vector<std::unique_ptr<nts::IComponent>> &Component::getComp() const
{
    return std::move(_v_comp);
}*/
