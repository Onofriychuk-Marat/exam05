#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
protected:
    std::string name;
    std::string effects;

public:
    ASpell();
    ASpell(std::string const &, std::string const &);
    ASpell(ASpell const &);
    virtual ~ASpell();
    ASpell &operator=(ASpell const &);
    
    
    std::string const &getName(void) const;
    std::string const &getEffects(void) const;

    virtual ASpell *clone(void) const = 0;

    void launch(ATarget const &) const;
};

#endif