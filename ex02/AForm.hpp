#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        AForm();
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        virtual void execute(Bureaucrat const & executor) const;

        void beSigned(const Bureaucrat &b);

        const std::string &getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        class GradeTooHighException : public std::exception
        {
            public:
                 const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                 const char* what() const throw();
        };
        class FormNotSignedException : public std::exception
        {
            public:
                 const char* what() const throw();
        };

    protected:
        virtual void executeAction() const = 0;
};
std::ostream &operator<<(std::ostream &out, const AForm &f);
#endif