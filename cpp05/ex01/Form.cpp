#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _name(""), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other) {
  if (this == &other)
    return *this;
  _isSigned = other._isSigned;
  return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
  return _name;
}

bool Form::getIsSigned() const {
  return _isSigned;
}

int Form::getGradeToSign() const {
  return _gradeToSign;
}

int Form::getGradeToExecute() const {
  return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() <= _gradeToSign)
    _isSigned = true;
  else
    throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
  return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
  os << "Form " << f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no")
     << ", sign grade: " << f.getGradeToSign()
     << ", execute grade: " << f.getGradeToExecute() << ".";
  return os;
}
