#pragma once
#include <string>

class Brain {
protected:
  std::string ideas[100];

  Brain(const std::string &type);

public:
  Brain();
  Brain(const Brain &other);
  virtual ~Brain();

  Brain &operator=(const Brain &other);

  void setIdea(int index, const std::string &idea);
  const std::string &getIdea(int index) const;
};
