#pragma once
#include "../pch.h"

struct Node {
    int positionX;
    int positionY;

    bool operator==(Node node) const;
    bool operator!=(Node node) const;
    bool operator<(Node node) const;
    std::basic_iostream<char>::basic_ostream& operator<<(std::basic_iostream<char>::basic_ostream& out) const;
};

namespace std {
    /* implement hash function so we can put Node into an unordered_set */
    template <> struct hash<Node> {
        std::size_t operator()(const Node& node) const noexcept {
            // NOTE: better to use something like boost hash_combine
            return std::hash<int>()(node.positionX ^ (node.positionX << 16));
        }
    };
}

