#include "node.h"
bool EmptyNode::Evaluate(const Date &date, const std::string &event) {
  return true;
}

DateComparisonNode::DateComparisonNode(Comparison cmp, const Date &d) : cmp(cmp), node_date(d) {}

bool DateComparisonNode::Evaluate(const Date &date, const std::string &event) {
  if (cmp == Comparison::Equal) {
    return date == node_date;
  } else if (cmp == Comparison::Greater) {
    return date > node_date;
  } else if (cmp == Comparison::GreaterOrEqual) {
    return date > node_date or date == node_date;
  } else if (cmp == Comparison::Less) {
    return date < node_date;
  } else if (cmp == Comparison::LessOrEqual) {
    return date < node_date or date == node_date;
  }
  return date != node_date;
}
EventComparisonNode::EventComparisonNode(Comparison cmp, const std::string &event) : cmp(cmp), node_event(event) {}

bool EventComparisonNode::Evaluate(const Date &date, const std::string &event) {
  if (cmp == Comparison::Equal) {
    return event == node_event;
  } else if (cmp == Comparison::Greater) {
    return event > node_event;
  } else if (cmp == Comparison::GreaterOrEqual) {
    return event > node_event or event == node_event;
  } else if (cmp == Comparison::Less) {
    return event < node_event;
  } else if (cmp == Comparison::LessOrEqual) {
    return event < node_event or event == node_event;
  }
  return event != node_event;
}

LogicalOperationNode::LogicalOperationNode(LogicalOperation operation,
                                           const std::shared_ptr<Node> &right,
                                           const std::shared_ptr<Node> &left)
    : operation(operation), right(right), left(left) {}

bool LogicalOperationNode::Evaluate(const Date &date, const std::string &event) {
  if (operation == LogicalOperation::And) {
    return left->Evaluate(date, event) and right->Evaluate(date, event);
  }
  return left->Evaluate(date, event) or right->Evaluate(date, event);
}
