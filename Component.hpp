/*
** EPITECH PROJECT, 2020
** Component
** File description:
** Component
*/

#ifndef __COMPONENT__
#define __COMPONENT__

#include "IComponent.hpp"

class Component : public nts::IComponent {
    private:
        std::string _value;
        std::string _type;
        std::vector<pin_t> _pins;
        std::vector<Int2> _truthTable;
        std::vector<std::unique_ptr<nts::IComponent>> _v_comp;
    public:
        Component(const std::string &);
        ~Component();
        nts::Tristate compute(std::size_t pin = 1) override;
        std::string getType() const final;
        void setType(std::string) final;
        void setLink(std::size_t, nts::IComponent &, std::size_t) final;
        void dump() const final;
        std::vector<pin_t> &getPins() final;
        std::vector<Int2> &getTruthTable() final;
        void setPin(size_t pin, Type type) final;
        void setPinState(size_t, nts::Tristate) final;
        void setTruthTable(std::vector<Int2> table) final;
        void setComp(std::vector<std::unique_ptr<nts::IComponent>> &) final;
};

#endif /**/
