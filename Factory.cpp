/*
** EPITECH PROJECT, 2020
** Factory
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Component.hpp"

Factory::Factory()
{
    _map["4001"] = &Factory::create4001;
    _map["4011"] = &Factory::create4011;
    _map["4013"] = &Factory::create4013;
    _map["4030"] = &Factory::create4030;
    _map["4040"] = &Factory::create4040;
    _map["4069"] = &Factory::create4069;
    _map["4071"] = &Factory::create4071;
    _map["4081"] = &Factory::create4081;
    _map["input"] = &Factory::createInput;
    _map["false"] = &Factory::createFalse;
    _map["output"] = &Factory::createOutput;
}

Factory::~Factory() {}

std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string &type, const std::string &value)
{
    return std::move(((this)->*(_map[type]))(value));
}

std::unique_ptr<nts::IComponent> Factory::create4001(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<std::unique_ptr<nts::IComponent>> v_comp;
    v_comp.push_back(std::move(createNor(value)));
    v_comp.push_back(std::move(createNor(value)));
    v_comp.push_back(std::move(createNor(value)));
    v_comp.push_back(std::move(createNor(value)));
    std::vector<Int2> newTable;

    component->setType("4001");
    component->setPin(1, INPUT);
    component->setPin(2, INPUT);
    component->setPin(3, OUTPUT);
    component->setPin(4, OUTPUT);
    component->setPin(5, INPUT);
    component->setPin(6, INPUT);
    component->setPin(7, INPUT);
    component->setPin(8, INPUT);
    component->setPin(9, INPUT);
    component->setPin(10, OUTPUT);
    component->setPin(11, OUTPUT);
    component->setPin(12, INPUT);
    component->setPin(13, INPUT);
    component->setPin(14, INPUT);
    component->setLink(1, *v_comp[0].get(), 1);
    component->setLink(2, *v_comp[0].get(), 2);
    component->setLink(3, *v_comp[0].get(), 3);
    component->setLink(4, *v_comp[1].get(), 3);
    component->setLink(5, *v_comp[1].get(), 2);
    component->setLink(6, *v_comp[1].get(), 1);
    component->setLink(8, *v_comp[2].get(), 1);
    component->setLink(9, *v_comp[2].get(), 2);
    component->setLink(10, *v_comp[2].get(), 3);
    component->setLink(11, *v_comp[3].get(), 3);
    component->setLink(12, *v_comp[3].get(), 2);
    component->setLink(13, *v_comp[3].get(), 1);
    newTable.push_back({1, 0});
    newTable.push_back({0, 0});
    component->setTruthTable(newTable);
    component->setComp(v_comp);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::create4011(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<std::unique_ptr<nts::IComponent>> v_comp;
    v_comp.push_back(std::move(createNand(value)));
    v_comp.push_back(std::move(createNand(value)));
    v_comp.push_back(std::move(createNand(value)));
    v_comp.push_back(std::move(createNand(value)));
    std::vector<Int2> newTable;

    component->setType("4011");
    component->setPin(1, INPUT);
    component->setPin(2, INPUT);
    component->setPin(3, OUTPUT);
    component->setPin(4, OUTPUT);
    component->setPin(5, INPUT);
    component->setPin(6, INPUT);
    component->setPin(7, INPUT);
    component->setPin(8, INPUT);
    component->setPin(9, INPUT);
    component->setPin(10, OUTPUT);
    component->setPin(11, OUTPUT);
    component->setPin(12, INPUT);
    component->setPin(13, INPUT);
    component->setPin(14, INPUT);
    component->setLink(1, *v_comp[0].get(), 1);
    component->setLink(2, *v_comp[0].get(), 2);
    component->setLink(3, *v_comp[0].get(), 3);
    component->setLink(4, *v_comp[1].get(), 3);
    component->setLink(5, *v_comp[1].get(), 2);
    component->setLink(6, *v_comp[1].get(), 1);
    component->setLink(8, *v_comp[2].get(), 1);
    component->setLink(9, *v_comp[2].get(), 2);
    component->setLink(10, *v_comp[2].get(), 3);
    component->setLink(11, *v_comp[3].get(), 3);
    component->setLink(12, *v_comp[3].get(), 2);
    component->setLink(13, *v_comp[3].get(), 1);
    newTable.push_back({1, 1});
    newTable.push_back({1, 0});
    component->setTruthTable(newTable);
    component->setComp(v_comp);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::create4013(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);

    return component;
}

std::unique_ptr<nts::IComponent> Factory::create4030(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<std::unique_ptr<nts::IComponent>> v_comp;
    v_comp.push_back(std::move(createXor(value)));
    v_comp.push_back(std::move(createXor(value)));
    v_comp.push_back(std::move(createXor(value)));
    v_comp.push_back(std::move(createXor(value)));
    std::vector<Int2> newTable;

    component->setType("4030");
    component->setPin(1, INPUT);
    component->setPin(2, INPUT);
    component->setPin(3, OUTPUT);
    component->setPin(4, OUTPUT);
    component->setPin(5, INPUT);
    component->setPin(6, INPUT);
    component->setPin(7, INPUT);
    component->setPin(8, INPUT);
    component->setPin(9, INPUT);
    component->setPin(10, OUTPUT);
    component->setPin(11, OUTPUT);
    component->setPin(12, INPUT);
    component->setPin(13, INPUT);
    component->setPin(14, INPUT);
    component->setLink(1, *v_comp[0].get(), 1);
    component->setLink(2, *v_comp[0].get(), 2);
    component->setLink(3, *v_comp[0].get(), 3);
    component->setLink(4, *v_comp[1].get(), 3);
    component->setLink(5, *v_comp[1].get(), 2);
    component->setLink(6, *v_comp[1].get(), 1);
    component->setLink(8, *v_comp[2].get(), 1);
    component->setLink(9, *v_comp[2].get(), 2);
    component->setLink(10, *v_comp[2].get(), 3);
    component->setLink(11, *v_comp[3].get(), 3);
    component->setLink(12, *v_comp[3].get(), 2);
    component->setLink(13, *v_comp[3].get(), 1);
    newTable.push_back({0, 1});
    newTable.push_back({1, 0});
    component->setTruthTable(newTable);
    component->setComp(v_comp);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::create4040(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);

    return component;
}

std::unique_ptr<nts::IComponent> Factory::create4069(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<std::unique_ptr<nts::IComponent>> v_comp;
    v_comp.push_back(std::move(createNot(value)));
    v_comp.push_back(std::move(createNot(value)));
    v_comp.push_back(std::move(createNot(value)));
    v_comp.push_back(std::move(createNot(value)));
    v_comp.push_back(std::move(createNot(value)));
    v_comp.push_back(std::move(createNot(value)));
    std::vector<Int2> newTable;

    component->setType("4071");
    component->setPin(1, INPUT);
    component->setPin(2, OUTPUT);
    component->setPin(3, INPUT);
    component->setPin(4, OUTPUT);
    component->setPin(5, INPUT);
    component->setPin(6, OUTPUT);
    component->setPin(7, INPUT);
    component->setPin(8, OUTPUT);
    component->setPin(9, INPUT);
    component->setPin(10, OUTPUT);
    component->setPin(11, INPUT);
    component->setPin(12, OUTPUT);
    component->setPin(13, INPUT);
    component->setPin(14, INPUT);
    component->setLink(1, *v_comp[0].get(), 1);
    component->setLink(2, *v_comp[0].get(), 2);
    component->setLink(3, *v_comp[1].get(), 1);
    component->setLink(4, *v_comp[1].get(), 2);
    component->setLink(5, *v_comp[2].get(), 1);
    component->setLink(6, *v_comp[2].get(), 2);
    component->setLink(8, *v_comp[3].get(), 2);
    component->setLink(9, *v_comp[3].get(), 1);
    component->setLink(10, *v_comp[4].get(), 2);
    component->setLink(11, *v_comp[4].get(), 1);
    component->setLink(12, *v_comp[5].get(), 2);
    component->setLink(13, *v_comp[5].get(), 1);
    newTable.push_back({1, 0});
    component->setTruthTable(newTable);
    component->setComp(v_comp);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::create4071(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<std::unique_ptr<nts::IComponent>> v_comp;
    v_comp.push_back(std::move(createOr(value)));
    v_comp.push_back(std::move(createOr(value)));
    v_comp.push_back(std::move(createOr(value)));
    v_comp.push_back(std::move(createOr(value)));
    std::vector<Int2> newTable;

    component->setType("4071");
    component->setPin(1, INPUT);
    component->setPin(2, INPUT);
    component->setPin(3, OUTPUT);
    component->setPin(4, OUTPUT);
    component->setPin(5, INPUT);
    component->setPin(6, INPUT);
    component->setPin(7, INPUT);
    component->setPin(8, INPUT);
    component->setPin(9, INPUT);
    component->setPin(10, OUTPUT);
    component->setPin(11, OUTPUT);
    component->setPin(12, INPUT);
    component->setPin(13, INPUT);
    component->setPin(14, INPUT);
    component->setLink(1, *v_comp[0].get(), 1);
    component->setLink(2, *v_comp[0].get(), 2);
    component->setLink(3, *v_comp[0].get(), 3);
    component->setLink(4, *v_comp[1].get(), 3);
    component->setLink(5, *v_comp[1].get(), 2);
    component->setLink(6, *v_comp[1].get(), 1);
    component->setLink(8, *v_comp[2].get(), 1);
    component->setLink(9, *v_comp[2].get(), 2);
    component->setLink(10, *v_comp[2].get(), 3);
    component->setLink(11, *v_comp[3].get(), 3);
    component->setLink(12, *v_comp[3].get(), 2);
    component->setLink(13, *v_comp[3].get(), 1);
    newTable.push_back({0, 1});
    newTable.push_back({1, 1});
    component->setTruthTable(newTable);
    component->setComp(v_comp);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::create4081(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<std::unique_ptr<nts::IComponent>> v_comp;
    v_comp.push_back(std::move(createAnd(value)));
    v_comp.push_back(std::move(createAnd(value)));
    v_comp.push_back(std::move(createAnd(value)));
    v_comp.push_back(std::move(createAnd(value)));
    std::vector<Int2> newTable;

    component->setType("4081");
    component->setPin(1, INPUT);
    component->setPin(2, INPUT);
    component->setPin(3, OUTPUT);
    component->setPin(4, OUTPUT);
    component->setPin(5, INPUT);
    component->setPin(6, INPUT);
    component->setPin(7, INPUT);
    component->setPin(8, INPUT);
    component->setPin(9, INPUT);
    component->setPin(10, OUTPUT);
    component->setPin(11, OUTPUT);
    component->setPin(12, INPUT);
    component->setPin(13, INPUT);
    component->setPin(14, INPUT);
    component->setLink(1, *v_comp[0].get(), 1);
    component->setLink(2, *v_comp[0].get(), 2);
    component->setLink(3, *v_comp[0].get(), 3);
    component->setLink(4, *v_comp[1].get(), 3);
    component->setLink(5, *v_comp[1].get(), 2);
    component->setLink(6, *v_comp[1].get(), 1);
    component->setLink(8, *v_comp[2].get(), 1);
    component->setLink(9, *v_comp[2].get(), 2);
    component->setLink(10, *v_comp[2].get(), 3);
    component->setLink(11, *v_comp[3].get(), 3);
    component->setLink(12, *v_comp[3].get(), 2);
    component->setLink(13, *v_comp[3].get(), 1);
    newTable.push_back({0, 0});
    newTable.push_back({0, 1});
    component->setTruthTable(newTable);
    component->setComp(v_comp);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::createInput(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);

    component->setType("input");
    component->setPin(1, INPUT);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::createFalse(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);

    component->setType("false");
    component->setPin(1, INPUT);
    component->setPinState(1, nts::FALSE);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::createOutput(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);

    component->setType("output");
    component->setPin(1, OUTPUT);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::createAnd(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<Int2> newTable;

    component->setType("And");
    component->setPin(1, INPUT);
    component->setPin(2, INPUT);
    component->setPin(3, OUTPUT);
    newTable.push_back({0, 0});
    newTable.push_back({0, 1});
    component->setTruthTable(newTable);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::createNand(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<Int2> newTable;

    component->setType("Nand");
    component->setPin(1, INPUT);
    component->setPin(2, INPUT);
    component->setPin(3, OUTPUT);
    newTable.push_back({1, 1});
    newTable.push_back({1, 0});
    component->setTruthTable(newTable);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::createOr(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<Int2> newTable;

    component->setType("Or");
    component->setPin(1, INPUT);
    component->setPin(2, INPUT);
    component->setPin(3, OUTPUT);
    newTable.push_back({0, 1});
    newTable.push_back({1, 1});
    component->setTruthTable(newTable);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::createNor(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<Int2> newTable;

    component->setType("Nor");
    component->setPin(1, INPUT);
    component->setPin(2, INPUT);
    component->setPin(3, OUTPUT);
    newTable.push_back({1, 0});
    newTable.push_back({0, 0});
    component->setTruthTable(newTable);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::createXor(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<Int2> newTable;

    component->setType("Xor");
    component->setPin(1, INPUT);
    component->setPin(2, INPUT);
    component->setPin(3, OUTPUT);
    newTable.push_back({0, 1});
    newTable.push_back({1, 0});
    component->setTruthTable(newTable);
    return component;
}

std::unique_ptr<nts::IComponent> Factory::createNot(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> component = std::make_unique<Component>(value);
    std::vector<Int2> newTable;

    component->setType("not");
    component->setPin(1, INPUT);
    component->setPin(2, OUTPUT);
    newTable.push_back({1, 0});
    component->setTruthTable(newTable);
    return component;
}
