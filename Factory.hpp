/*
** EPITECH PROJECT, 2020
** Factory
** File description:
** Factory
*/

#ifndef __FACTORY__
#define __FACTORY__

#include "IComponent.hpp"

class Factory {
    public:
        using createPtr_t = std::unique_ptr<nts::IComponent> (Factory::*)(const std::string &) const noexcept;
    private:
        std::map<std::string, createPtr_t> _map;
        std::unique_ptr<nts::IComponent> create4001 (const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4011 (const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4013 (const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4040 (const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4030 (const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4069 (const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4071 (const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4081 (const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createInput (const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createFalse (const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createOutput (const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createAnd(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createNand(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createOr(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createNor(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createXor(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createNot(const std::string &value) const noexcept;

    public:
        Factory();
        ~Factory();
        std::unique_ptr<nts::IComponent> createComponent(const std::string &, const std::string &);
};

#endif /**/
