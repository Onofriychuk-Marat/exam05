#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(SpellBook const &spellBook)
{
    this->arraySpell = spellBook.arraySpell;
}

SpellBook &SpellBook::operator=(SpellBook const &spellBook)
{
    this->arraySpell = spellBook.arraySpell;
    return (*this);
}

SpellBook::~SpellBook()
{
    for (int i = 0; i < this->arraySpell.size(); i++)
    {
        delete this->arraySpell[i];
    }
    this->arraySpell.clear();
}

void SpellBook::learnSpell(ASpell *aspell)
{
    for (int i = 0; i < this->arraySpell.size(); i++)
    {
        if (this->arraySpell[i]->getName() == aspell->getName())
        {
            return ;
        }
    }
    this->arraySpell.push_back(aspell->clone());
}

void SpellBook::forgetSpell(std::string const &name)
{
    for (int i = 0; i < this->arraySpell.size(); i++)
    {
        if (this->arraySpell[i]->getName() == name)
        {
            delete this->arraySpell[i];
            this->arraySpell.erase(this->arraySpell.begin() + i);
            return ;
        }
    }
}

ASpell* SpellBook::createSpell(std::string const &name)
{
    for (int i = 0; i < this->arraySpell.size(); i++)
    {
        if (this->arraySpell[i]->getName() == name)
        {
            return (this->arraySpell[i]->clone());
        }
    }
    return (NULL);
}
