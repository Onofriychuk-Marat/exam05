#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::TargetGenerator(TargetGenerator const &targetGenerator)
{
    this->arrayTarget = targetGenerator.arrayTarget;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &targetGenerator)
{
    this->arrayTarget = targetGenerator.arrayTarget;
    return (*this);
}

TargetGenerator::~TargetGenerator()
{
    for (int i = 0; i < this->arrayTarget.size(); i++)
    {
        delete this->arrayTarget[i];
    }
    this->arrayTarget.clear();
}

void TargetGenerator::learnTargetType(ATarget *atarget)
{
    if (atarget == nullptr)
        return ;
    for (int i = 0; i < this->arrayTarget.size(); i++)
    {
        if (this->arrayTarget[i]->getType() == atarget->getType())
        {
            return ;
        }
    }
    this->arrayTarget.push_back(atarget->clone());
}

void TargetGenerator::forgetTargetType(std::string const &name)
{
    for (int i = 0; i < this->arrayTarget.size(); i++)
    {
        if (this->arrayTarget[i]->getType() == name)
        {
            delete this->arrayTarget[i];
            this->arrayTarget.erase(this->arrayTarget.begin() + i);
            return ;
        }
    }
}

ATarget* TargetGenerator::createTarget(std::string const &name)
{
    for (int i = 0; i < this->arrayTarget.size(); i++)
    {
        if (this->arrayTarget[i]->getType() == name)
        {
            return (this->arrayTarget[i]->clone());
        }
    }
    return (NULL);
}
