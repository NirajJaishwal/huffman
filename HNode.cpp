#include "HNode.hpp"

// Constructor for creating a new node from a character and its weight
HNode::HNode(const char& val, const int& w) : value(val), weight(w), left(nullptr), right(nullptr) {}

// Constructor for creating a new node from two existing nodes
HNode::HNode(HNode* l, HNode* r) : left(l), right(r), value('*'), weight(l->weight + r->weight) {}


