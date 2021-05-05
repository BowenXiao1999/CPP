//
// Created by bowen on 2021/3/26.
//

static class Map {
    std::unordered_map<char, int> map_;
};

static int GetMapping(char c) {

    return ;
}
class Node {
    bool is_end_;
    int frequency;
    char val;
    bool is_root_;
    std::vector<Node*> child;
};


class TrieTree {
    std::unique_ptr<Node> root_;
};

TrieTree::TrieTree() {
    root_ = std::make_unique<Node>();
}

std::Node* TrieTree::Search(std::string key, int offset) {
    return nullptr;
}

void TrieTree::Insert(std::string key, int frequency) {
    Node* start = Search(key, 0);
    int start_offset = 0;
    for (size_t i = start_offset; i < key.size(); ++i) {
        char cur = key[i];
        Node* n = new Node();
        start->child[cur] = n;
        if (i == key.size() - 1) {
            n->is_end_ = true;
            n->frequency = frequency;
        }
    }
}

/*
 * 466, 0 -> inn
 * */
std::string TrieTree::Query(std::string qkey, int offset) {
    for (size_t i = 0; i < root_->child.size(); ++i) {
        if (root_->[offset] == root_->[offset].) {

        }
    }
}




