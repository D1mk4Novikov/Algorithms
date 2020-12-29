#pragma once

#include <string>

using namespace std;

class Wizard {
public:
    int mana = 0;
    string * name = new string("");

    void swap(Wizard& other) {
        std::swap(mana, other.mana);
        std::swap(name, other.name);
    }

    Wizard() {}

    Wizard(const string & name, int mana): mana(mana) {
        this->name = new string(name);
    }

    ~Wizard() {
        delete name;
    }

    Wizard(Wizard const & wizard): mana(wizard.mana) {
        name = new string(*(wizard.name));
    }

    Wizard& operator=(const Wizard & other) {
        if (this != &other) {
            Wizard(other).swap(*this);
        }
        return *this;
    }

    Wizard(Wizard&& other) noexcept {
        swap(other);
    }

    Wizard& operator=(Wizard && other) noexcept {
        swap(other);

        return *this;
    }
};