#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>

struct node {
	typedef boost::shared_ptr<node> smart_ptr;

	char        symbol;
	int         frq;
	std::string encoding;
	smart_ptr   left;
	smart_ptr   right;

	node() : symbol(0), frq(0) {}
	node(char s, int f) : symbol(s), frq(f) {}
};

const node operator +(const node& lhs, const node& rhs) {

	node internal_node;

	internal_node.left = node::smart_ptr(new node(lhs));
	internal_node.right = node::smart_ptr(new node(rhs));
	internal_node.frq = lhs.frq + rhs.frq;

	return internal_node;
}

bool operator >(const node& lhs, const node& rhs) {

	return lhs.frq > rhs.frq;
}

typedef std::priority_queue<node, std::vector<node>, std::greater<node> > huffman_tree;

huffman_tree build_huffman_tree(const std::string& text) {

	// Frequency table
	int frq[256] = {0};

	for (std::string::const_iterator it = text.begin(); it != text.end(); ++it) {
		++frq[static_cast<size_t>(*it)];
	}

	// Huffman tree
	std::priority_queue<node, std::vector<node>, std::greater<node> > tree;

	for (size_t ch = 0; ch < 256; ++ch) {
		if (frq[ch]) {
			tree.push(node(ch, frq[ch]));
		}
	}

	while (tree.size() > 1) {
		const node left = tree.top();
		tree.pop();
		const node right = tree.top();
		tree.pop();
		tree.push(left + right);
	}

	return tree;
}

void build_symbol_encoding(node& head, const std::string bits = "0") {

	head.encoding = bits;

	if (head.left.get()) {
		build_symbol_encoding(*head.left, bits + "0");
	}

	if (head.right.get()) {
		build_symbol_encoding(*head.right, bits + "1");
	}
}

void build_symbol_encoding(huffman_tree& tree) {

	node head = tree.top();
	tree.pop();

	build_symbol_encoding(head);

	tree.push(head);
}

typedef std::map<char, std::string> encoding_map;

void build_encoding_map(const node& head, encoding_map& map) {

	if (head.symbol) {
		map[head.symbol] = head.encoding;
		return;
	}

	if (head.left.get()) {
		build_encoding_map(*head.left, map);
	}
	if (head.right.get()) {
		build_encoding_map(*head.right, map);
	}
}

encoding_map build_encoding_map(huffman_tree& tree) {

	build_symbol_encoding(tree);

	encoding_map map;
	build_encoding_map(tree.top(), map);

	return map;
}

std::string encode(const std::string& text) {

	huffman_tree tree = build_huffman_tree(text);
	encoding_map map = build_encoding_map(tree);

	std::string crypt;

	for (std::string::const_iterator it = text.begin(); it != text.end(); ++it) {
		// std::cout << *it << " -> " << map[*it] << "\n";
		crypt += map[*it];
	}

	return crypt;
}

int main() {

	std::string text;
	std::getline(std::cin, text);

	std::cout << encode(text) << std::endl;

	return 0;
}

