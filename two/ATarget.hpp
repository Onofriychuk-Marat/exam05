#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
private:
    std::string type;

public:
    ATarget();
    ATarget(std::string const &);
    ATarget(ATarget const &);
    virtual ~ATarget();
    ATarget &operator=(ATarget const &);

    std::string const &getType(void) const;

    virtual ATarget *clone() const = 0;

    void getHitBySpell(ASpell const &) const;
};

#endif