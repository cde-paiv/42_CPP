#pragma once
#include <string>

class Brain {
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    const std::string& getIdea(int idx) const;
    void setIdea(int idx, const std::string& idea);

private:
    std::string _ideas[100];
};
