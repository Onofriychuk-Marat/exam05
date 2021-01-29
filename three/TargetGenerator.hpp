#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <vector>

class TargetGenerator
{
private:
    std::vector<ATarget *> arrayTarget;

    TargetGenerator(TargetGenerator const &);
    TargetGenerator &operator=(TargetGenerator const &);

public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget *);
    void forgetTargetType(std::string const &);
    ATarget* createTarget(std::string const &);
};

#endif