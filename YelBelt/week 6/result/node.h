#pragma once
#include "date.h"

#include <string>
#include <memory>

enum class LogicalOperation {
  And,
  Or
};

enum class Comparison {
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual
};

class Node {
public:
//  Node() = default;
  virtual bool Evaluate(const Date &date, const std::string &event) = 0;
};

class EmptyNode : public Node {
public:
  bool Evaluate(const Date &date, const std::string &event) override;
};

class DateComparisonNode : public Node {
public:
  DateComparisonNode(Comparison cmp, const Date &date);
  bool Evaluate(const Date &date, const std::string &event) override;
private:
  Comparison cmp;
  Date node_date;
};

class EventComparisonNode : public Node {
public:
  EventComparisonNode(Comparison cmp, const std::string &event);
  bool Evaluate(const Date &date, const std::string &event) override;
private:
  Comparison cmp;
  std::string node_event;
};

class LogicalOperationNode : public Node {
public:
  LogicalOperationNode(LogicalOperation operation,
                       const std::shared_ptr<Node> &right,
                       const std::shared_ptr<Node> &left);
  bool Evaluate(const Date &date, const std::string &event) override;
private:
  LogicalOperation operation;
  std::shared_ptr<Node> right;
  std::shared_ptr<Node> left;
};
