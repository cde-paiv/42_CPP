#include "ShrubberyCreationForm.hpp"
#include <fstream> // para escrever arquivo

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberryCreationform", 145, 137, target) {
    std::cout << "[ShrubberyyCreationForm] contructed\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "[ShrubberyCreationForm] destroyed\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other) {
    std::cout << "[ShruberryCreationForm] copy-constructed\n";
}

ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "[ShrubberyCreationForm] copy-assigned\n";
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

void    ShrubberyCreationForm::doExecute() const {
    const std::string filename = getTarget() + "_shrubbery";
    std::ofstream out(filename.c_str());
    if (!out) {
        std::cerr << "[ShrubberyCreationForm] cannot open file: " << filename << std::endl;
        return;
    }
    out << "   ccee88oo\n";
    out << " C8O8O8Q8PoOb o8oo\n";
    out << "dOB69QO8PdUOpugoO9bD\n";
    out << "CgggbU8OU qOp qOdoUOdcb\n";
    out << "    6OuU  /p u gcoUodpP\n";
    out << "      \\\\//  /douUP\n";
    out << "        \\\\////\n";
    out << "         |||/\\\n";
    out << "         |||\\/\n";
    out << "         |||||\n";
    out << "   .....//||||\\....\n";
    out.close();
    std::cout << "[ShrubberyCreationForm] file created: " << filename << "\n";
}