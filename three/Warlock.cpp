#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name;
    std::cout << ": This looks like another boring day.";
    std::cout << std::endl;
}

Warlock::~Warlock()
{
    std::cout << this->name;
    std::cout << ": My job here is done!";
    std::cout << std::endl;
}

std::string const   &Warlock::getName(void) const
{
    return (this->name);
}

std::string const   &Warlock::getTitle(void) const
{
    return (this->title);
}

void                Warlock::setTitle(std::string const &title)
{
    this->title = title;
}

void                Warlock::introduce() const
{
    std::cout << this->name;
    std::cout << ": I am " << this->name;
    std::cout << ", " << this->title << " !";
    std::cout << std::endl;
}

void Warlock::learnSpell(ASpell *aspell)
{
    book.learnSpell(aspell);
}

void Warlock::forgetSpell(std::string name)
{
    book.forgetSpell(name);
}

void Warlock::launchSpell(std::string name, ATarget const &atarget)
{
    ASpell *aspell;
    
    if ((aspell = book.createSpell(name)))
        aspell->launch(atarget);
}
