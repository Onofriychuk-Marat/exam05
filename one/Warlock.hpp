#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>

class Warlock 
{
private:
    std::string name;
    std::string title;

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
};

#endif