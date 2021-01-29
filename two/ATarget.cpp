#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string const &type)
{
    this->type = type;
}

ATarget::ATarget(ATarget const &atarget)
{
    this->type = atarget.getType();
}

ATarget::~ATarget() {}

ATarget &ATarget::operator=(ATarget const &atarget)
{
    this->type = atarget.type;
    return (*this);
}

std::string const &ATarget::getType() const
{
    return (this->type);
}

void ATarget::getHitBySpell(ASpell const &aspell) const
{
    std::cout << this->type;
    std::cout << " has been " << aspell.getEffects();
    std::cout << "!" << std::endl;
}