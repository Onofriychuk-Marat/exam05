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
    for (int i = 0; i < this->arrayASpeel.size(); i++)
    {
        delete this->arrayASpeel[i];
    }
    this->arrayASpeel.clear();
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

void    Warlock::learnSpell(ASpell *aspell)
{
    for (int i = 0; i < this->arrayASpeel.size(); i++)
    {
        if (this->arrayASpeel[i]->getName() == aspell->getName())
        {
            return ;
        }
    }
    arrayASpeel.push_back(aspell->clone());
}

void    Warlock::forgetSpell(std::string name)
{
    for (int i = 0; i < this->arrayASpeel.size(); i++)
    {
        if (this->arrayASpeel[i]->getName() == name)
        {
            delete this->arrayASpeel[i];
            this->arrayASpeel.erase(this->arrayASpeel.begin() + i);
        }
    }
}

void    Warlock::launchSpell(std::string name, ATarget const &atarget)
{
    for (int i = 0; i < this->arrayASpeel.size(); i++)
    {
        if (this->arrayASpeel[i]->getName() == name)
        {
            this->arrayASpeel[i]->launch(atarget);
        }
    }
}
