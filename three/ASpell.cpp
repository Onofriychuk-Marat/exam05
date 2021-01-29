#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string const & name, std::string const & effects)
{
    this->name = name;
    this->effects = effects;
}

ASpell::ASpell(ASpell const & aspell)
{
    this->name = aspell.getName();
    this->effects = aspell.getEffects();
}

ASpell::~ASpell() {}

ASpell &ASpell::operator=(ASpell const & aspell)
{
    this->name = aspell.getName();
    this->effects = aspell.getEffects();
    return (*this);
}

std::string const &ASpell::getName(void) const
{
    return (this->name);
}

std::string const &ASpell::getEffects(void) const 
{
    return (this->effects);
}

void ASpell::launch(ATarget const &atarget) const
{
    atarget.getHitBySpell(*this);
}
