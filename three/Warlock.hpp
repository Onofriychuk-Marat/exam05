#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include <vector>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock 
{
private:
    std::string             name;
    std::string             title;
    std::vector<ASpell*>    arrayASpeel;
    SpellBook               book;

    Warlock();
    Warlock(Warlock const &);
    Warlock &operator=(Warlock const &);

public:
    Warlock(std::string const &, std::string const &);
    ~Warlock();

    std::string const  &getName(void) const;
    std::string const  &getTitle(void) const;
    void                setTitle(std::string const &);

    void introduce() const;

    void learnSpell(ASpell *);
    void forgetSpell(std::string);
    void launchSpell(std::string, ATarget const &);
};

#endif